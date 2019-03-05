#include "../includes/BTree.h"

Tree::Tree() {

}
Tree::Tree(Node *root) {
    this->root = root;
}
Tree::~Tree() {
}
Node* Tree::getRoot() {
    return root;
}
void Tree::insertNode(Node *newNode) {
    if (!root) {
        root = newNode;
    } else {
        insertNode2Node(root, newNode);
    }
}
void Tree::insertNode2Node(Node *nodeFromTree, Node *newNode) {
    if (newNode->getValue() < nodeFromTree->getValue()) {
        if (nodeFromTree->getLeft()) {
            insertNode2Node(nodeFromTree->getLeft(), newNode);
        }
        else {
            nodeFromTree->insertLeftNode(newNode);
        }
    }
    else {
        if (nodeFromTree->getRight()) {
            insertNode2Node(nodeFromTree->getRight(), newNode);
        }
        else {
            nodeFromTree->insertRightNode(newNode);
        }
    }
    
}