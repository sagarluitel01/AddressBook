//SAGAR LUITEL
//CSCI  2421- 001
//FINAL PROJECT

#include <iostream>
#include "AddressBook.h"
#include "BSTree.h"
#include "Node.h"
#include <fstream>

//#include <string>


using namespace std;

int main()
{
    //BSTree tree;
    int searchItem = 0;
    vector<Node*> myVector;
    string word;
    AddressBook book;
    
    char option;
   
  do
  {
    cout << " *******************MENU******************" << endl; // Main menu
    cout << "               Please select one \n \n "
            "   A:  Read From File \n "
            "   B:  Add A Record \n "
            "   C:  Search A Record \n "
            "   D:  Update A Record \n "
            "   E:  Delete A Record \n "
            "   F:  Print \n "
            "   X:  Exit " << endl;
    cin >> option;
    
    if (option == 'A')
    {
        book.readfromFile(); //calling function read from file
    }
    if (option == 'B')
    {
        book.add();         //calling add function
    }
    if (option == 'C')
    {
        book.search(book.tree->Root(), searchItem, myVector);
    }
    if (option == 'D')
    {
        book.update(searchItem, book.tree->Root());
    }
    if (option == 'E')
    {
        book.remove(book.tree->Root());
    }
    if (option == 'F')
    {
        book.display(book.tree->Root());
    }
  }while (option != 'x' || option != 'X'); //x to exit the program
    
    return 0;
}
