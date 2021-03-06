#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

struct Item{
  string name;
  int data;
  Item* left;
  Item* right;
};

class BST{
  private:
    string type;
    Item* root;

    void setType(string newType);

    Item* createItem(string name, int data);

    Item* addItemHelper(Item* curr, string name, int data);
    void printTreeHelper(Item* curr);

    Item* searchHelper(Item* curr, string name);

    Item* getFirstItem(Item* curr);
    Item* getLastItem(Item* curr);

    void destroyTree(Item* curr);
    Item* deleteItemHelper(Item* curr, string name);

  public:
    Item* getRoot();
    void addItem(string name, int data);
    int searchItem(string name);
    void printTree();
    BST();
    BST(string type);
    ~BST();
    Item* modifyItem(string name, int newData);
    void deleteItem(string name);
};
#endif