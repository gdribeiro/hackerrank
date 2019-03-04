#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/Tree.h"
#include "../includes/NodeWithList.h"

// Testing
#include "../tests/NodeTesting.cpp"

using namespace std;



int mainTest(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    auto testResult = RUN_ALL_TESTS();
}