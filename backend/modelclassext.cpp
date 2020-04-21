#include "ModelClassExt.h"

void ModelClassExt::initdb(std::string codeBaseDirectory){
    db.setDatabaseName(QString::fromStdString(codeBaseDirectory + "database/db.db"));
    if(!db.open()){
        qDebug("Model class build failed for linux and macos builds.");
        throw ModelException("Database failed to open.");
    }else{
        qDebug("Model class build successful.");
    }
}

void ModelClassExt::saveCollectionToDB() {

}

json ModelClassExt::getCollectionInfoJSON(int collectionID) {
    return json();
}


json ModelClassExt::getMuseumAndCollectionInfoJSON(int museumID) {
    return json();
}
