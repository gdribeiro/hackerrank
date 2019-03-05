#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/BTree.h"
#include "../includes/NodeWithList.h"

// Testing
#include "../tests/NodeTesting.cpp"
#include "../tests/TreeTesting.cpp"

using namespace std;



int mainTest(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    auto testResult = RUN_ALL_TESTS();
}