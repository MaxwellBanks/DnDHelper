#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

using namespace std;

struct item{
  string name;
  string description;
  item* next;
};

class ItemHash{
  private:
    int tableSize;

    item* *table;

    item* createItem(string name, string description, item* next);
  public:
    ItemHash(int size);

    bool insertItem(string name, string description);

    unsigned int hashFunction(string name);

    void printTable();

    string searchItem(string name);

    void readData(string filename);

    void writeData(string filename);

    string getIndex(int index);
};

#endif
