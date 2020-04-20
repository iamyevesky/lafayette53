#include "devtests.h"


TEST_F(DevTests, testingModelClassOpenClose){
    ModelClass::initdb();
    ASSERT_TRUE(ModelClass::open());
    ASSERT_TRUE(ModelClass::status());
    ASSERT_TRUE(ModelClass::close());
    ASSERT_FALSE(ModelClass::status());


}

TEST_F(DevTests, testingModelClassReadInfo){
   ModelClass::initdb();
   ModelClass::open();
   QJsonObject object;
   object["username"] = "Lekso_";
   object["email"] = "borashvl@lafayette.edu";
   QJsonDocument doc;
   doc.setObject(object);
   ASSERT_EQ(doc.toJson().toStdString(), ModelClass::getUserInfoJSON(0));

   QJsonObject museumObj;
   museumObj["name"] = "Lekso's Space";
   museumObj["introduction"] = "This is Lekso's Space";
   museumObj["description"] = "This is my space here!";
   museumObj["museumID"] = 0;
   museumObj["userID"] = 0;
   QJsonDocument museumDoc;
   museumDoc.setObject(museumObj);
   ASSERT_EQ(museumDoc.toJson().toStdString(), ModelClass::getMuseumInfoJSON(0));

   QJsonArray museumArray;
   QJsonObject museum0;
   QJsonObject museum1;
   QJsonObject museum2;
   QJsonObject museum3;
   museum0["name"] = "Lekso's Space";
   museum1["name"] = "Peter's Space";
   museum2["name"] = "Sena's Space";
   museum3["name"] = "Malo's Space";

   museum0["introduction"] = "This is Lekso's Space";
   museum1["introduction"] = "This is Peter's Space";
   museum2["introduction"] = "This is Sena's Space";
   museum3["introduction"] = "This is Malo's Space";

   museum0["description"] = "This is my space here!";
   museum1["description"] = "This is my space here!";
   museum2["description"] = "This is my space here!";
   museum3["description"] = "This is my space here!";

   museum0["museumID"] = 0;
   museum1["museumID"] = 1;
   museum2["museumID"] = 2;
   museum3["museumID"] = 3;

   museum0["userID"] = 0;
   museum1["userID"] = 1;
   museum2["userID"] = 2;
   museum3["userID"] = 3;
   museumArray.append(museum0);
   museumArray.append(museum1);
   museumArray.append(museum2);
   museumArray.append(museum3);
   QJsonDocument museumListDoc;
   museumListDoc.setArray(museumArray);
   ASSERT_EQ(museumListDoc.toJson().toStdString(), ModelClass::getMuseumListJSON());
   ModelClass::close();
}

TEST_F(DevTests, testingUserInput){
    User newUser("yevs", "yvs@lafayette.edu", "password");
    ModelClass::open();
    ASSERT_TRUE(ModelClass::saveUserToDB(newUser));
    ASSERT_TRUE(newUser.indb());
    EXPECT_EQ(ModelClass::getPasswordHash(newUser.getName()), "password");
    EXPECT_EQ(newUser.getEmail(), ModelClass::getUserObject("yevs").getEmail());
    EXPECT_EQ(newUser.getPassword(), ModelClass::getUserObject("yevs").getPassword());
    EXPECT_EQ(newUser.getUserID(), ModelClass::getUserObject("yevs").getUserID());
    EXPECT_EQ(newUser.getJSON(), ModelClass::getUserObject("yevs").getJSON());
    EXPECT_EQ(newUser.getName(), ModelClass::getUserObject("yevs").getName());

    EXPECT_EQ(ModelClass::getPasswordHash(newUser.getName()), "password");
    EXPECT_EQ(newUser.getEmail(), ModelClass::getUserObject(newUser.getUserID()).getEmail());
    EXPECT_EQ(newUser.getPassword(), ModelClass::getUserObject(newUser.getUserID()).getPassword());
    EXPECT_EQ(newUser.getUserID(), ModelClass::getUserObject(newUser.getUserID()).getUserID());
    EXPECT_EQ(newUser.getJSON(), ModelClass::getUserObject(newUser.getUserID()).getJSON());
    EXPECT_EQ(newUser.getName(), ModelClass::getUserObject(newUser.getUserID()).getName());

    newUser.setEmail("yevenyos");
    EXPECT_TRUE(ModelClass::updateUserInDB(newUser));
    ASSERT_TRUE(ModelClass::removeUserFromDB(newUser));
    ASSERT_TRUE(!newUser.indb());
    ModelClass::close();
}

TEST_F(DevTests, testingMuseumInput){
    User newUser("sena", "s@lafayette.edu", "password");
    ModelClass::open();
    ASSERT_TRUE(ModelClass::saveUserToDB(newUser));
    ASSERT_TRUE(newUser.indb());
    Museum museum("aMuseum", "a sample museum", newUser);
    ASSERT_TRUE(ModelClass::saveMuseumToDB(museum));
    ASSERT_TRUE(museum.indb());
    museum.setName("newName");
    EXPECT_TRUE(ModelClass::updateMuseumInDB(museum));
    museum.getUser().setPassword("able");
    EXPECT_EQ(newUser.getPassword(), museum.getUser().getPassword());
    ASSERT_TRUE(ModelClass::removeMuseumFromDB(museum));
    ASSERT_TRUE(!museum.indb());
    ASSERT_TRUE(ModelClass::removeUserFromDB(newUser));
    ASSERT_TRUE(!newUser.indb());
    ModelClass::close();
}

TEST_F(DevTests, TestingModelClassMuseumAndUserReturns){
    User newUser("sena", "s@lafayette.edu", "password");
    ModelClass::open();
    ASSERT_TRUE(ModelClass::saveUserToDB(newUser));
    Museum museum("aMuseum", "a sample museum", newUser);
    ASSERT_TRUE(ModelClass::saveMuseumToDB(museum));
    EXPECT_EQ(museum.getMuseumID(), ModelClass::getMuseumObject("aMuseum").getMuseumID());
    EXPECT_EQ(museum.getName(), ModelClass::getMuseumObject("aMuseum").getName());
    EXPECT_EQ(museum.getJSON(), ModelClass::getMuseumObject("aMuseum").getJSON());
    EXPECT_EQ(museum.getDescription(), ModelClass::getMuseumObject("aMuseum").getDescription());
    EXPECT_EQ(museum.getUser().getUserID(), ModelClass::getMuseumObject("aMuseum").getUser().getUserID());
    EXPECT_EQ(museum.getUser().getName(), ModelClass::getMuseumObject("aMuseum").getUser().getName());
    EXPECT_EQ(museum.getUser().getEmail(), ModelClass::getMuseumObject("aMuseum").getUser().getEmail());
    EXPECT_EQ(museum.getUser().getPassword(), ModelClass::getMuseumObject("aMuseum").getUser().getPassword());
    EXPECT_EQ(museum.getUser().getJSON(), ModelClass::getMuseumObject("aMuseum").getUser().getJSON());
    ASSERT_TRUE(ModelClass::removeMuseumFromDB(museum));
    ASSERT_TRUE(!museum.indb());
    ASSERT_TRUE(ModelClass::removeUserFromDB(newUser));
    ASSERT_TRUE(!newUser.indb());
}


