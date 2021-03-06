TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql
QMAKE_CXXFLAGS += -std=gnu++11
QMAKE_CXXFLAGS_WARN_ON = -w

QMAKE_LFLAGS += -g -fprofile-arcs -ftest-coverage  -O0
QMAKE_CXXFLAGS += -g -fprofile-arcs -ftest-coverage -O0

#lcov --capture --directory build-lafayette53-Desktop_Qt_5_14_1_clang_64bit-Debug/tests/backend --output-file lcov/coverage.info
#genhtml lcov/coverage.info --output-directory lcov


SOURCES += \
        main.cpp \
        handlertest.cpp \
        utiltest.cpp

HEADERS += \
        handlertest.h \
        mockmodelclass.h \
        utiltest.h

SOURCES += \
    ../../model/modelclass.cpp \
    ../../model/artifact.cpp \
    ../../model/collection.cpp \
    ../../backend/handler.cpp


HEADERS += \
    ../../backend/handler.h \
    ../../backend/util.h \
    ../../backend/controller.h \
    ../../model/modelclass.h \
    ../../model/artifact.h \
    ../../model/collection.h \
    ../../model/museum.h \
    ../../model/user.h \
    ../../model/ModelException.h



SOURCES += ../../gtest/googletest/src/gtest-all.cc \
           ../../gtest/googlemock/src/gmock-all.cc \
           ../../nlohmann/json.hpp


INCLUDEPATH +=  ../../gtest                                   \
                ../../gtest/googletest                        \
                ../../gtest/googletest/include                \
                ../../gtest/googletest/include/gtest          \
                ../../gtest/googlemock                        \
                ../../gtest/googlemock/include                \
                ../../gtest/googlemock/include/gmock

LIBS += -lcpprest -lssl -lcrypto -lboost_system -pthread


macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/lib/ -lboost_system

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/boost@1.60/1.60.0/include


macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/cpprestsdk/2.10.15/lib/ -lcpprest.2.10

INCLUDEPATH += $$PWD/../../../../../../../../../usr/local/Cellar/cpprestsdk/2.10.15/include
DEPENDPATH += $$PWD/../../../../../../../../../usr/local/Cellar/cpprestsdk/2.10.15/include

macx: LIBS += -L$$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/lib/ -lssl.1.0.0

INCLUDEPATH +=  $$PWD/../../../../../../../../../usr/local/Cellar/openssl/1.0.2t/include
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
