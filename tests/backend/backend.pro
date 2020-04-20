TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt
QT += sql
QMAKE_CXXFLAGS += -std=gnu++11

SOURCES += \
        main.cpp \
        handlertest.cpp \
        utiltest.cpp

HEADERS += \
        handlertest.h \
        utiltest.h

SOURCES += \
    ../../model/modelclass.cpp \
    ../../model/artifact.cpp \
    ../../model/collection.cpp


HEADERS += \
    ../../backend/handler.h \
    ../../backend/util.h \
    ../../model/modelclass.h \
    ../../model/artifact.h \
    ../../model/collection.h \
    ../../model/museum.h \
    ../../model/user.h \
    ../../model/LafException.h \
    ../../model/ModelException.h \
    ../../nlohmann/json.hpp



SOURCES += ../../gtest/googletest/src/gtest-all.cc \
           ../../gtest/googlemock/src/gmock-all.cc


INCLUDEPATH +=  ../../gtest                                   \
                ../../gtest/googletest                        \
                ../../gtest/googletest/include                \
                ../../gtest/googletest/include/gtest          \
                ../../gtest/googlemock                        \
                ../../gtest/googlemock/include                \
                ../../gtest/googlemock/include/gmock

#LIBS += -lgtest -L$$PWD/../../
#LIBS += -lgtest -L$$PWD/../../


LIBS += -lcpprest -lssl -lcrypto -lboost_system -pthread


macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/lib/ -lboost_system

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include


macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/cpprestsdk/2.10.15/lib/ -lcpprest.2.10

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/cpprestsdk/2.10.15/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/cpprestsdk/2.10.15/include

macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/lib/ -lssl.1.0.0

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/include

macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/lib/ -lcrypto.1.0.0

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/include

macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/lib/ -lboost_thread-mt

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include

macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/lib/ -lboost_chrono-mt

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include