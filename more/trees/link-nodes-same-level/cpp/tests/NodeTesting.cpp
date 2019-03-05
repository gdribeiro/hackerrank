#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/BTree.h"
#include "../includes/NodeWithList.h"

using namespace std;

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


TEST(NodeTesting, deleteLeftNode) {
    Node* root = new Node(0);
    Node* leftNode = new Node(1);
    root->insertLeftNode(leftNode);
    // This test would be better using fixture
    root->deleteLeftNode();
    EXPECT_EQ(root->getLeft(), nullptr);
}

TEST(NodeTesting, deleteRightNode) {
    Node* root = new Node(0);
    Node* rightNode = new Node(1);
    root->insertRightNode(rightNode);
    // This test would be better using fixture
    root->deleteRightNode();
    EXPECT_EQ(root->getRight(), nullptr);
}