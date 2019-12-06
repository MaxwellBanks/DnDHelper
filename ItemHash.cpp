#include <iostream>
#include <string>
#include "ItemHash.hpp"

using namespace std;

item* ItemHash::createItem(string name, string description, item* next){
  item* newItem = new item;
  newItem->name = name;
  item->description = description;
  item->next = next;
  return newItem;
}

ItemHash::ItemHash(int size){
  this->tableSize = size;
  table = new node*[tableSize];
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

item* ItemHash::searchItem(string name){
  int index = hashFunction(name);
  item* crawler;
  crawler = table[index];
  while(crawler){
    if(crawler->name == name){
      return crawler->description;
    }
    crawler = crawler->next;
  }
  return NULL;
}

bool ItemHash::insertItem(string name, string description){
  if(!searchItem(name)){
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