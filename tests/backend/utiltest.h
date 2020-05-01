#ifndef UTILTEST_H
#define UTILTEST_H
#include "../../backend/util.h"
#include "../../model/modelclass.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <../../nlohmann/json.hpp>
#include "mockmodelclass.h"

using namespace std;
using json = nlohmann::json;
using ::testing::InSequence;
using ::testing::Return;
using ::testing::Throw;

class MockObject {
public:
    MockObject(){}
    MOCK_METHOD0(toJSON, json());
};

class UtilTest : public ::testing::Test {
protected:

    UtilTest() {

    }

    virtual ~UtilTest() {
    // You can do clean-up work that doesn't throw exceptions here.
    }


    virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
    }

    virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
    }

};



#endif // UTILTEST_H
