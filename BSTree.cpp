#include "BSTree.h"
#include "Entry.h"

// Constructor
BSTree::BSTree() {
    root = nullptr;
}

// Destructor
BSTree::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
void BSTree::freeNode(Node* leaf)
{
    if ( this->Root() == leaf)
    {
        
    }
    else if ( leaf != nullptr )
   
        {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
        }
    
}

// Add a node
void BSTree::addNode(int key, Entry& entry)
{
    // No elements. Add the root
    if ( root == nullptr )
    {
        Node* n = new Node();
        n->setKey(key);
        n->setData(entry); //
        root = n;
    }
    else {
        addNode(key, root, entry);
    }
}

// Add a node (private)
void BSTree::addNode(int key, Node* leaf, Entry& entry) {
    if ( key <= leaf->ID() )
    {
        if ( leaf->Left() != nullptr )
            addNode(key, leaf->Left(), entry);
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setData(entry); //
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            addNode(key, leaf->Right(), entry);
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setData(entry);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Find a node
Node* BSTree::findNode(int key, Node* node)
{
    Node* temp;
    while (node != NULL)
    {
        if (node->ID() == key)
            break;
        
        if (key > node->ID())
        {
            node = node->Right();
        }
        else
        {
        if (key < node->ID())
                node = node->Left();
        }
    }
    
    if (node == NULL)
        return node;
    
    if (node->ID() == key)
    {
        temp = node;
        return temp;
    }
    return node;
}

// Print the BSTree
void BSTree::printPreorder(Node* node)
{
    if (node == NULL)
        return;
    
    /* first print data of node */
    cout << node->ID() << endl;
    
    /* then recur on left sutree */
    printPreorder(node->Left());
    
    /* now recur on right subtree */
    printPreorder(node->Right());
}
void BSTree::printPreordername(Node* node, int num)
{
    if (node == NULL)
        return;
    
    /* first print data of node */
    if (num == 1) {
        cout << node->getData().getNameInfo().getFirstName() << endl;
    }
    if (num == 2) {
        cout << node->getData().getNameInfo().getLastName() << endl;
    }
    if (num == 3) {
        cout << node->getData().getNameInfo().getCompanyName() << endl;
    }
    if (num == 4) {
        cout << node->getData().getContactInfo().getEMail() << endl;
    }
    if (num == 5) {
        cout << node->getData().getContactInfo().getMobile() << endl;
    }
    if (num == 6) {
        cout << node->getData().getNameInfo().getID() << endl;
        cout << node->getData().getNameInfo().getFirstName() << endl;
        cout << node->getData().getNameInfo().getMiddleName() << endl;
        cout << node->getData().getNameInfo().getLastName() << endl;
        cout << node->getData().getNameInfo().getCompanyName() << endl;
        cout << node->getData().getContactInfo().getHomePhone() << endl;
        cout << node->getData().getContactInfo().getOfficePhone() << endl;
        cout << node->getData().getContactInfo().getEMail() << endl;
        cout << node->getData().getContactInfo().getMobile() << endl;
        cout << node->getData().getAddress().getStreetAddress() << endl;
        cout << node->getData().getAddress().getCity() << endl;
        cout << node->getData().getAddress().getStates() << endl;
        cout << node->getData().getAddress().getZipCode() << endl;
        cout << node->getData().getAddress().getCountry() << endl;
        
        for (int i = 0; i < node->getData().getAffiliates().size(); i++)
        {
            cout << node->getData().getAffiliates()[i].getFirstName() << " "
                 << node->getData().getAffiliates()[i].getLastName() << ", "
                 << node->getData().getAffiliates()[i].getPhone() << ", "
                 << node->getData().getAffiliates()[i].getEMail() << ";" << endl;
        }
    
    }
    /* then recur on left sutree */
    printPreordername(node->Left(), num);
    
    /* now recur on right subtree */
    printPreordername(node->Right(), num);
}
void BSTree::printInorder(Node* node)
{

    
}

void BSTree::printPostorder(Node* node)
{
    if ( node != nullptr)
    {
    
    }
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* BSTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* BSTree::max(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* BSTree::successor(int key, Node *node)
{
    

    Node *successor = nullptr;
    Node *current  = root;
    if(root == nullptr)
        return NULL;
    
    while(current->ID() != key){
        /* If node value is greater than the node which are looking for, then go to left sub tree
         Also when we move left, update the successor pointer to keep track of lst left turn */
        
        if(current->ID() >key){
            successor = current;
            current= current->Left();
        }
        /* Else take right turn and no need to update successor pointer */
        else
            current = current->Right();
    }
    /*Once we reached at the node for which inorder successor is to be found, check if it has right sub tree, if yes then find the minimum in that right sub tree and return that node
     
     Else last left turn taken node is already stored in successor pointer and will be returned*/
    if(current && current->Right()){
        successor = min(current->Right());
    }
    
    return successor;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* BSTree::predecessor(int key, Node *node)
{
    Node* current = findNode(key, node);

    if (current == nullptr)
        { return nullptr; }
    
    if (current->Left() !=nullptr)
    {
        return max(current->Left());
    } else
    
    {
        Node *tempParent = current->Parent();
        while (tempParent !=nullptr) {
            if (current == tempParent->Right() ){
                break;
            }
            current = tempParent;
            tempParent = current->Parent();
        }
        return tempParent;
    }
}


void BSTree::deleteNode(int key)
{
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
    
}

//deleteNode (Private)
Node* BSTree::deleteNode(Node* root,int key)
{
   
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */

    
        if(root == nullptr) return root;
        else if(key < root->ID())
            root->setLeft( deleteNode(root->Left(),key));
        else if(key > root->ID())
            root->setRight( deleteNode(root->Right(), key) );
        else {
            // Case 1: No Child
            if(root->Left() == nullptr && root->Right() == nullptr){
                delete root;
                root = nullptr;
                // Case 2: one child
            } else if(root->Left() == nullptr){
                Node *temp = root;
                root = root->Right();
                delete temp;
            } else if(root->Right() == nullptr){
                Node *temp = root;
                root = root->Left();
                delete temp;
            } else{
                Node *temp = min(root->Right());
                root->setKey(temp->ID() );
                root->setData(temp->getData());
                root->setRight(  deleteNode(root->Right(), temp->ID() ) );
            }
        }
        return root;
    
}


/*
 this is the search function
 var wrod is the string which user entered, and int searchItem also entered by
 user for the swith statement. the word will be compaired with data in the node 
 if found the node will be stored in searchReasult vector
 */
void BSTree::search(Node* node, string word, int searchItem, vector<Node*>& searchResult)
{
    if ( root == nullptr)
    {
        return;
    }
    else
    {
        switch (searchItem)  // user enter from the menu
        {
            case 1:         // if user enter 1
                if(word == node->getData().getNameInfo().getFirstName()) // compaire word with data in node
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 2:
                if(word == node->getData().getNameInfo().getMiddleName())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                }
                break;
            case 3:
                if(word == node->getData().getNameInfo().getLastName())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                }
            case 4:
                if(word == node->getData().getNameInfo().getCompanyName())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                }
                
            case 5:
                if(word == node->getData().getContactInfo().getHomePhone())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 6:
                if(word == node->getData().getContactInfo().getOfficePhone())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                }
                break;
            case 7:
                if(word == node->getData().getContactInfo().getMobile())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 8:
                if(word == node->getData().getContactInfo().getEMail())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 9:
                if(word == node->getData().getAddress().getStreetAddress())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 10:
                if(word == node->getData().getAddress().getCity())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 11:
                if(word == node->getData().getAddress().getStates())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 12:
                if(word == node->getData().getAddress().getZipCode())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 13:
                if(word == node->getData().getAddress().getCountry())
                {
                    cout << " Found " << endl;
                    searchResult.push_back(node);
                    
                }
                break;
            case 14:
                
                break;
        }

        
        if ( node->Left() != nullptr)
        {
            
            search(node->Left(), word, searchItem, searchResult);
            
        }
        
        if ( node->Right() != nullptr)
        {
            
            search(node->Right(), word, searchItem, searchResult);
            
        }
    }
}

/*void BSTree::searchNode(int key, Node* node)
{
    while (node != NULL)
    {
        if (node->ID() == key)
            break;
        
        if (key > node->ID())
            node = node->Right();
        else
            if (key < node->ID())
            node = node->Left();
    }
    
    if (node == NULL)
    {
        cout << " Not found " << endl;
        return;
    }
    
    if (node->ID() == key)
    {
        cout << node->getData().getNameInfo().getID() << endl;
        cout << node->getData().getNameInfo().getFirstName() << endl;
        cout << node->getData().getNameInfo().getMiddleName() << endl;
        cout << node->getData().getNameInfo().getLastName() << endl;
        cout << node->getData().getNameInfo().getCompanyName() << endl;
        cout << node->getData().getContactInfo().getOfficePhone() << endl;
        cout << node->getData().getContactInfo().getHomePhone() << endl;
        cout << node->getData().getContactInfo().getMobile() << endl;
        cout << node->getData().getContactInfo().getEMail() << endl;
        cout << node->getData().getAddress().getStreetAddress() << endl;
        cout << node->getData().getAddress().getCity() << endl;
        cout << node->getData().getAddress().getStates() << endl;
        cout << node->getData().getAddress().getZipCode() << endl;
        cout << node->getData().getAddress().getCountry() << endl;
        //cout << &newEntry.getAffiliates();
        
        for (int i = 0; i < node->getData().getAffiliates().size(); i++)
        {
            cout << node->getData().getAffiliates()[i].getFirstName() << " "
            << node->getData().getAffiliates()[i].getLastName() << ", "
            << node->getData().getAffiliates()[i].getEMail() << ", "
            << node->getData().getAffiliates()[i].getPhone() << ";" << endl;
        }

        
    }
    return;
}*/

