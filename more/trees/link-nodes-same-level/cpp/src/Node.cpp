#ifndef NODE_S
#define NODE_S

#include "../includes/Node.h"

using namespace std;


Node::Node() {};
Node::Node(int value) {
    this->value = value;
}
void Node::insertLeftNode(Node *node) {
    this->leftNode = node;
}
void Node::insertRightNode(Node *node) {
    this->rightNode = node;
}
Node* Node::getLeft() {
    return leftNode;
}
Node* Node::getRight() {
    return rightNode;
}
int Node::getValue() {
    return this->value;
}

#endif