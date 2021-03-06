#ifndef MOCKMODELCLASS_H
#define MOCKMODELCLASS_H
// Other Libraries
#include <vector>
// GTest related includes
#include "gmock/gmock.h"
// Model
#include "../../model/modelclass.h"
#include "../../model/ModelException.h"
#include "../../model/collection.h"
#include "../../model/user.h"
#include "../../model/museum.h"
#include "../../model/artifact.h"

using namespace std;
/**
 * @brief The MockModelClass class Mocks ModelClass using GMock.
 */
class MockModelClass: public  ModelClass {
public:
    MockModelClass() : ModelClass("") {}
    /**< User */
    MOCK_METHOD1(getUserObject, User(string));
    MOCK_METHOD1(saveUserToDB, void(User&));
    MOCK_METHOD1(updateUserInDB, void(User&));
    MOCK_METHOD1(checkHeadCurator, bool(User&));

    /**< Museum */
    MOCK_METHOD0(getMuseumList, vector<Museum>());
    MOCK_METHOD1(getMuseumByCurator, vector<Museum>(int));
    MOCK_METHOD1(getMuseumObject, Museum(int));
    MOCK_METHOD1(saveMuseumToDB, void(Museum&));
    MOCK_METHOD1(removeMuseumFromDB, void(Museum&));

    /**< Collection */
    MOCK_METHOD1(getCollectionListByMuseumID, vector<Collection>(int));
    MOCK_METHOD1(getCollectionsByArtifact, vector<Collection>(int));
    MOCK_METHOD1(getCollectionObject, Collection(int));
    MOCK_METHOD1(saveCollectionToDB, void(Collection&));
    MOCK_METHOD1(updateCollectionInDB, void(Collection&));

    /**< Artifact */
    MOCK_METHOD1(getArtifactsByMuseum, vector<Artifact>(int));
    MOCK_METHOD1(getArtifactsByCollection, vector<Artifact>(int));
    MOCK_METHOD2(addArtifactCollection, void(Artifact const &, Collection const & ));
    MOCK_METHOD1(saveArtifactToDB, void(Artifact&));
    MOCK_METHOD1(getArtifact, Artifact(int));
    MOCK_METHOD1(updateArtifactInDB, void(Artifact &));
    MOCK_METHOD1(removeArtifactInDB, void(Artifact &));

    /**< Edit  */
    MOCK_METHOD1(getEditArtifactObject, Edit<Artifact>(int));
    MOCK_METHOD1(getArtifactEdits, vector<Edit<Artifact>>(int));
    MOCK_METHOD1(getArtifactActions, vector<Edit<Artifact>>(int));
    MOCK_METHOD1(getEditCollectionObject, Edit<Collection>(int));
    MOCK_METHOD1(getCollectionEdits, vector<Edit<Collection>>(int));
    MOCK_METHOD1(getCollectionActions, vector<Edit<Collection>>(int));
    MOCK_METHOD1(saveEditToDB, void(Edit<Artifact> &));
    MOCK_METHOD1(saveEditToDB, void(Edit<Collection> &));
    MOCK_METHOD1(updateEditInDB,  void(Edit<Artifact>  &));
    MOCK_METHOD1(updateEditInDB,  void(Edit<Collection> &));
    MOCK_METHOD1(removeArtifactCollection, void(Artifact const &));

};

#endif // MOCKMODELCLASS_H
