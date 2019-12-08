#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "ItemHash.h"

using namespace std;

item* ItemHash::createItem(string name, string description, item* next){
  item* newItem = new item;
  newItem->name = name;
  newItem->description = description;
  newItem->next = next;
  return newItem;
}

ItemHash::ItemHash(int size){
  this->tableSize = size;
  table = new item*[tableSize];
  for(int i = 0; i < size; i++){
    table[i] = nullptr;
  }
}

unsigned int ItemHash::hashFunction(string name){
  int nameSum = 0;
  for(int i = 0; i < name.length(); i++){
    nameSum += int(name[i]);
  }
  return (nameSum % tableSize);
}

string ItemHash::searchItem(string name){
  int index = hashFunction(name);
  item* crawler;
  crawler = table[index];
  while(crawler){
    if(crawler->name == name){
      return crawler->description;
    }
    crawler = crawler->next;
  }
  return "";
}

bool ItemHash::insertItem(string name, string description){
  if(searchItem(name).empty()){
    item* newItem = createItem(name, description, NULL);
    item* crawler = table[hashFunction(name)];
    if(crawler){
      while(crawler->next){
        crawler = crawler->next;
      }
      crawler->next = newItem;
    }else{
      table[hashFunction(name)] = newItem;
    }
    return true;
  }else{
    cout << "Error: Item " + name + " already exists!" << endl;
    return false;
  }
}

void ItemHash::printTable(){
  item* crawler;
  for(int i = 0; i < tableSize; i++){
    crawler = table[i];
    while(crawler){
      cout << crawler->name << ": " << crawler->description << endl;
      crawler = crawler->next;
    }
  }
}

void ItemHash::readData(string filename){
  ifstream iFile;
  iFile.open(filename);
  if(!iFile.is_open()){
    cout << "File " << filename << " cannot be opened" << endl;
    return;
  }
  string line;
  string name;
  string description;
  while(getline(iFile, line)){
    stringstream ss(line);
    name = "";
    description = "";
    getline(ss, name, ',');
    getline(ss, description);
    insertItem(name, description);
  }
  iFile.close();
}

void ItemHash::writeData(string filename){
  ofstream oFile;
  oFile.open(filename);
  if(!oFile.is_open()){
    cout << "Error: Cannot save to file " << filename << endl;
    return;
  }
  item* crawler;
  for(int i = 0; i < tableSize; i++){
    crawler = table[i];
    while(crawler){
      oFile << crawler->name << "," << crawler->description << '\n';
      crawler = crawler->next;
    }
  }
  oFile.close();
}
