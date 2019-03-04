#ifndef NODEWITHLIST_H
#define NODEWITHLIST_H

#include "Node.h"

using namespace std;


class NodeWithList: public Node {
    public:
    NodeWithList();
    NodeWithList(int value);
    void addNextInLine(Node *next);
};



#endif