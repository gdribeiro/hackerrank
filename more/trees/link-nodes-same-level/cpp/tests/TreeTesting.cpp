#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include "../includes/Node.h"
#include "../includes/BTree.h"
#include "../includes/NodeWithList.h"

using namespace std;


TEST(TreeTesting, insert2Root) {
    Node *node = new Node(0);
    Tree *tree  = new Tree();
    tree->insertNode(node);
    EXPECT_EQ(tree->getRoot(), node);
}

TEST(TreeTesting, initializeWithRootNode) {
    Tree *tree = new Tree(new Node(0));
    EXPECT_EQ(tree->getRoot()->getValue(), 0);
}
TEST(TreeTesting, insert2TheLeft) {
    Tree *tree = new Tree(new Node(0));
    tree->insertNode(new Node(-1));
    EXPECT_EQ(tree->getRoot()->getLeft()->getValue(), -1);
}

TEST(TreeTesting, insert2TheRight) {
    Tree *tree = new Tree(new Node(0));
    tree->insertNode(new Node(1));
    EXPECT_EQ(tree->getRoot()->getRight()->getValue(), 1);
}