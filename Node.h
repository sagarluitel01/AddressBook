#ifndef NODE_
#define NODE_
#include <iostream>
#include "Entry.h"
using namespace std;

// A generic tree node class

//Placeholder for a composite data type

//Binary Tree Node
class Node
{
private:
    int iD;
    Entry data;
    Node* left;
    Node* right;
    Node* parent;
public:
    Node() { iD =-1; left=nullptr; right=nullptr; parent = nullptr;};
    void setKey(int aKey) { iD = aKey; };
    void setLeft(Node* aLeft) { left = aLeft; };
    void setRight(Node* aRight) { right = aRight; };
    void setParent(Node* aParent) { parent = aParent; };
    int ID() { return iD; };
    Node* Left() { return left; };
    Node* Right() { return right; };
    Node* Parent() { return parent; };
    void setData(Entry iData) { data = iData;}
    Entry getData() { return data;}
};



#endif
