#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/Tree.h"
#include "../includes/NodeWithList.h"

using namespace std;


// Create test fixture for node in another class and call it here!
TEST(NodeTesting, getValue) {
    Node* node = new Node(0);
    auto value = node->getValue();
    EXPECT_EQ(value, 0);
}
TEST(NodeTesting, getEmptyLeftNode) {
    Node* node = new Node(0);
    Node* leftNode = node->getLeft();
    EXPECT_EQ(leftNode, nullptr);
}
TEST(NodeTesting, getEmptyRightNode) {
    Node* node = new Node(0);
    Node* rightNode = node->getRight();
    EXPECT_EQ(rightNode, nullptr);
}

TEST(NodeTesting, addLeftNode) {
    Node* root = new Node(0);
    Node* leftNode = new Node(1);
    root->insertLeftNode(leftNode);
    EXPECT_EQ(root->getLeft(), leftNode);
}

TEST(NodeTesting, addRighttNode) {
    Node* root = new Node(0);
    Node* rightNode = new Node(1);
    root->insertRightNode(rightNode);
    EXPECT_EQ(root->getRight(), rightNode);
}
