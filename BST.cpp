#include "BST.h"
#include <iostream>
#include <string>

void BST::setType(string newType){
  type = newType;
}

Item* BST::createItem(string name, int data){
  Item* newItem = new Item;
  newItem->name = name;
  newItem->data = data;
  newItem->left = NULL;
  newItem->right = NULL;
  return newItem;
}

Item* BST::addItemHelper(Item* curr, string name, int data){
  if(!root){
    root = createItem(name, data);
    return root;
  }
  if(!curr){
    return createItem(name, data);
  }else if(curr->name < name){
    curr->right = addItemHelper(curr->right, name, data);
  }else if(curr->name > name){
    curr->left  = addItemHelper(curr->left, name, data);
  }
  return curr;
}

void BST::printTreeHelper(Item* curr){
  if(curr){
    printTreeHelper(curr->left);
    cout << curr->name << ", ";
    if(type == "ability"){
      cout << "Charges: " << curr->data << endl;
    }else if(type == "spell"){
      cout << "Level: " << curr->data << endl;
    }else if(type == "item"){
      cout << "Quantity: " << curr->data << endl;
    }else{
      cout << "CR " << curr->data << endl;
    }
    printTreeHelper(curr->right);
  }
}

Item* BST::searchHelper(Item* curr, string name){
  if(!curr){
    return NULL;
  }else if(curr->name > name){
    return searchHelper(curr->left, name);
  }else if(curr->name < name){
    return searchHelper(curr->right, name);
  }else{
    return curr;
  }
}

Item* BST::getFirstItem(Item* curr){
  if(curr->left){
    return getFirstItem(curr->left);
  }
  return curr;
}

Item* BST::getLastItem(Item* curr){
  if(curr->right){
    return getLastItem(curr->right);
  }
  return curr;
}

void BST::destroyTree(Item* curr){
  if(curr){
    destroyTree(curr->left);
    destroyTree(curr->right);
    delete curr;
    curr = NULL;
  }
}

Item* BST::deleteItemHelper(Item* curr, string name){
  if(!curr){
    return NULL;
  }else if(name > curr->name){
    curr->right = deleteItemHelper(curr->right, name);
  }else if(name < curr->name){
    curr->left = deleteItemHelper(curr->left, name);
  }else{
    if(!curr->left && !curr->right){
      delete curr;
      curr = NULL;
    }else if(!curr->left){
      Item* temp = curr;
      curr = curr->right;
      delete temp;
    }else if(!curr->right){
      Item* temp = curr;
      curr = curr->left;
      delete temp;
    }else{
      curr->name = getFirstItem(curr->right)->name;
      curr->data = getFirstItem(curr->right)->data;
      curr->right = deleteItemHelper(curr->right, curr->name);
    }
    //return curr;
  }
  return curr;
}

Item* BST::getRoot(){
  return root;
}

void BST::addItem(string name, int data){
  addItemHelper(root, name, data);
}

bool BST::searchItem(string name){
  Item* tree = searchHelper(root, name);
  if(tree){
    return true;
  }
  cout << name << " not found" << endl;
  return false;
}

void BST::printTree(){
  printTreeHelper(root);
}

BST::BST(){

}

BST::BST(string type){
  setType(type);
}

BST::~BST(){
  destroyTree(root);
}

Item* BST::modifyItem(Item* curr, string name, int newData){
  Item* toEdit = searchHelper(root, name);
  toEdit->data = newData;
  return toEdit;
}

void BST::deleteItem(string name){
  deleteItemHelper(root, name);
}
