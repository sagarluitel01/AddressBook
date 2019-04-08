#include <iostream>
#include <string>
#include "Affiliates.h"
#include "BSTree.h"
#include "Entry.h"
#include "Node.h"

#include <fstream>

using namespace std;

class AddressBook
{
private:
    //BSTree* tree;
    
public:
    BSTree* tree = new BSTree;
    void readfromFile();
    void searchId(int, Node*);
    void add();
    void update( int searchItem, Node* node);
    void remove(Node*);
    void display(Node*);
    void sort();
    void search(Node*, int, vector<Node*>&);
    void inorder(BSTree);
    
};

