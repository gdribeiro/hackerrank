#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/Tree.h"
#include "../includes/NodeWithList.h"

using namespace std;



TEST(NodeTesting, getEmptyLeftNode) {
    Node* node = new Node(0);
    Node* leftNode = node->getLeft();
    EXPECT_EQ(leftNode, nullptr);
}



int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    auto testResult = RUN_ALL_TESTS();
    cout << "Hello, it seems to be working!!!!" << endl;
    return testResult;
}