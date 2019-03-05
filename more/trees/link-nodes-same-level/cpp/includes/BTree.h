#ifndef BTREE_H
#define BTREE_H

#include "Node.h"


using namespace std;

class Tree {
    private:
        Node* root;
        void insertNode2Node(Node *nodeFromTree, Node *newNode);
    public:
        Tree();
        Tree(Node *root);
        ~Tree();
        void insertNode(Node *newNode);
        Node* getRoot();
};

#endif