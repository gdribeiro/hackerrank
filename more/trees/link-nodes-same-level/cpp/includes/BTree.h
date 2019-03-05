#ifndef BTREE_H
#define BTREE_H

#include "Node.h"


using namespace std;

class Tree {
    private:
        Node* root;
    public:
        Tree();
        ~Tree();
        void insertNodeRoot(Node *newNode);
        void insertNode2Node(Node *nodeFromTree, Node *newNode);
};

#endif