#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<cstdio>


using namespace std;


class Node {
    private:
        std::string name;
        int value;
        Node *leftNode;
        Node *rightNode;

    public:
        Node();
        Node(int value);
        void insertLeftNode(Node *node);
        void insertRightNode(Node *node);
        Node *getLeft();
        Node *getRight();
        int getValue();
};
#endif