#include "../includes/Tree.h"

Tree::Tree() {

}
Tree::~Tree() {
}
void Tree::insertNodeRoot(Node *newNode) {
    if (!root) {
        root = newNode;
    } else {
        insertNode2Node(newNode, root->getRight()); 
    }
}
void Tree::insertNode2Node(Node *nodeFromTree, Node *newNode) {
    if (newNode->getValue() < nodeFromTree->getValue()) {
        if (nodeFromTree->getLeft()) {
            insertNode2Node(newNode, nodeFromTree->getLeft());
        }
        else {
            nodeFromTree->insertLeftNode(newNode);
        }
    }
    else {
        if (nodeFromTree->getRight()) {
            insertNode2Node(newNode, nodeFromTree->getRight());
        }
        else {
            nodeFromTree->insertRightNode(newNode);
        }
    }
    
}