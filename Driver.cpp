#include "Player.h"
#include "ItemHash.h"
#include "Party.h"
#include "BST.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>
#include <time.h>
#include <ctime>

using namespace std;

ItemHash spells(10313);
ItemHash items(10313);
ItemHash abilities(593);
ItemHash monsters(10313);

BST monstersTree("monsters");

Party party;


Player test;

void readInitData(){
  ifstream iMonsters;
  iMonsters.open("Monsters.csv");
  if(!iMonsters.is_open()){
    cout << "File Monsters.csv cannot be opened" << endl;
    return;
  }
  string line;
  string name;
  string cr;
  while(getline(iMonsters, line)){
    stringstream ss(line);
    name = "";
    cr = "";
    getline(ss, name, ',');
    getline(ss, cr);
    monstersTree.addItem(name, stoi(cr));
    monsters.insertItem(name, cr);
  }
  iMonsters.close();

  line = "";
  name = "";
  string level = "";
  ifstream iSpells;
  iSpells.open("Spells.csv");
  if(!iSpells.is_open()){
    cout << "File Spells.csv cannot be opened" << endl;
    return;
  }
  while(getline(iSpells, line)){
    stringstream ss(line);
    name = "";
    level = "";
    getline(ss, name, ',');
    getline(ss, level);
    spells.insertItem(name, level);
  }
  iSpells.close();

  line = "";
  name = "";
  string rarity = "";
  ifstream iItems;
  iItems.open("Items.csv");
  if(!iItems.is_open()){
    cout << "File Items.csv cannot be opened" << endl;
    return;
  }
  while(getline(iItems, line)){
    stringstream ss(line);
    name = "";
    level = "";
    getline(ss, name, ',');
    getline(ss, level);
    items.insertItem(name, level);
  }
  iItems.close();

  line = "";
  name = "";
  string description = "";
  ifstream iAbilities;
  iAbilities.open("Abilities.csv");
  if(!iAbilities.is_open()){
    cout << "File Abilities.csv cannot be opened" << endl;
    return;
  }
  while(getline(iAbilities, line)){
    stringstream ss(line);
    name = "";
    description = "";
    getline(ss, name, ',');
    getline(ss, description);
    abilities.insertItem(name, description);
  }
  iAbilities.close();
/*
  line = "";
  name = "";
  string description = "";
  ifstream iInventory;
  iInventory.open("PartyInventory.csv");
  if(!iInventory.is_open()){
    cout << "File PartyInventory.csv cannot be opened" << endl;
    return;
  }
  stringstream ss;
  ss.str("");
  ss.clear();
  while(getline(iInventory, line)){
    ss.str(line);
    name = "";
    description = "";
    getline(ss, name, ',');
    getline(ss, description);
    abilities.insertItem(name, description);
  }
  iAbilities.close();*/
}

void readInitPlayers(){
  ifstream iPlayers;
  iPlayers.open("Players.csv");
  if(!iPlayers.is_open()){
    cout << "File Players.csv cannot be opened" << endl;
    return;
  }
  string line;
  string countPlayers;
  string countShort;
  string hold1;
  string hold2;
  string hold3;
  string hold4;
  string hold5;
  string hold6;
  string hold7;
  string hold8;
  string hold9;
  bool profHold;
  bool expHold;
  int holdStats[6];
  string holdSkills[18];
  stringstream ss;
  getline(iPlayers, countPlayers);
  for(int i = 0; i < stoi(countPlayers); i++){
    Player player;
    line = "";
    getline(iPlayers, line);
    ss.str(line);
    getline(ss, hold1, ',');
    getline(ss, hold2, ',');
    getline(ss, hold3);
    line = "";
    ss.str("");
    ss.clear();
    getline(iPlayers, line);
    ss.str(line);
    getline(ss, hold4, ',');
    getline(ss, hold5, ',');
    player.setIdentityInfo(hold1, hold2, hold3, hold4, hold5);
    hold1 = hold2 = hold3 = hold4 = hold5 = "";
    //holding total level
    getline(ss, hold8, ',');
    countShort = "";
    getline(iPlayers, countShort);
    for(int j = 0; j < stoi(countShort); j++){
      line = "";
      ss.str("");
      ss.clear();
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2, ',');
      getline(ss, hold3);
      player.addClass(stoi(hold3), hold1, hold2);
      hold1 = hold2 = hold3 = "";
    }
    countShort = "";
    for(int j = 0; j < 6; j++){
      line = "";
      ss.str("");
      ss.clear();
      getline(iPlayers, line);
      //cout << "Line " << j << ": " << line << endl;
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2, ',');
      getline(ss, hold3);
      if(hold1 == "x"){
        profHold = false;
      }else{
        profHold = true;
      }
      if(hold2 == "x"){
        expHold = false;
      }else{
        expHold = true;
      }
      player.setSavingThrows(j, profHold, expHold, stoi(hold3));
      hold1 = hold2 = hold3 = "";
    }
    for(int j = 0; j < 18; j++){
      line = "";
      ss.str("");
      ss.clear();
      getline(iPlayers, line);
      //cout << "Line " << j << ": " << line << endl;
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2, ',');
      getline(ss, hold3);
      if(hold1 == "x"){
        profHold = false;
      }else{
        profHold = true;
      }
      if(hold2 == "x"){
        expHold = false;
      }else{
        expHold = true;
      }
      player.setSkills(j, profHold, expHold, stoi(hold3));
      hold1 = hold2 = hold3 = "";
    }
    line = "";
    ss.str("");
    ss.clear();
    getline(iPlayers, line);
    ss.str(line);
    //currhealth
    getline(ss, hold1, ',');
    //cout << "Hold1: " << hold1 << endl;
    //maxhealth
    getline(ss, hold2, ',');
    //ac
    getline(ss, hold3, ',');
    //initiative
    getline(ss, hold4);
    line = "";
    ss.str("");
    ss.clear();
    getline(iPlayers, line);
    ss.str(line);
    //speed
    getline(ss, hold5, ',');
    //passivewis
    getline(ss, hold6, ',');
    //profbonus
    getline(ss, hold7);
    //cout << "Line2: " << line << endl;
    line = "";
    ss.str("");
    ss.clear();
    getline(iPlayers, line);
    ss.str(line);
    //stats
    for(int j = 0; j < 6; j++){
      hold9 = "";
      getline(ss, hold9, ',');
      holdStats[j] = stoi(hold9);
    }
    player.setStats(stoi(hold1), stoi(hold2), stoi(hold3), stoi(hold4), stoi(hold5), stoi(hold6), stoi(hold8), stoi(hold7), holdStats);
    hold1 = hold2 = hold3 = hold4 = hold5 = hold6 = hold7 = hold8 = "";
    line = "";
    ss.str("");
    ss.clear();
    getline(iPlayers, line);
    ss.str(line);
    for(int j = 0; j < 5; j++){
      getline(ss, hold1, ',');
      holdStats[i] = stoi(hold1);
      hold1 = "";
    }
    line = "";
    ss.str("");
    ss.clear();
    player.setCurrency(holdStats[0], holdStats[1], holdStats[2], holdStats[3], holdStats[4]);
    countShort = "";
    getline(iPlayers, countShort);
    for(int j = 0; j < stoi(countShort); j++){
      line = "";
      ss.str("");
      ss.clear();
      hold1 = hold2 = "";
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2);
      player.addItem(hold1, stoi(hold2), "item");
    }
    hold1 = "";
    countShort = "";
    getline(iPlayers, countShort);
    for(int j = 0; j < stoi(countShort); j++){
      line = "";
      ss.str("");
      ss.clear();
      hold1 = hold2 = "";
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2);
      player.addItem(hold1, stoi(hold2), "spell");
    }
    hold1 = "";
    countShort = "";
    getline(iPlayers, countShort);
    for(int j = 0; j < stoi(countShort); j++){
      line = "";
      ss.str("");
      ss.clear();
      hold1 = hold2 = "";
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2);
      player.addItem(hold1, stoi(hold2), "ability");
    }
    line = "";
    ss.str("");
    ss.clear();
    party.addPlayerByInput(player);
  }
  iPlayers.close();
}

void savePartyData(){

}

bool inVector(string name, vector<string> names){
  for(int i = 0; i < names.size(); i++){
    if(names[i] == name){
      return true;
    }
  }
  return false;
}

vector <string> generateEncounter(vector<string> lastEncounter){
  int levelSum = 0;
  int monsterLevel = 0;
  int zeroCount = 0;
  vector <string> encounter;
  for(int i = 0; i < party.getPartySize(); i++){
    levelSum += party.getPlayerStats("totalLevel", i); 
  }
  if(levelSum / party.getPartySize() > 4){
    levelSum = levelSum * 0.5;
  }else{
    levelSum = levelSum * 0.25;
  }
  time_t currentTime;
  srand(time(&currentTime));
  int start = rand() % 10313;
  for(int i = start; i < 10313; i++){
    if(!monsters.getIndex(i).empty()){
      monsterLevel = monstersTree.searchItem(monsters.getIndex(i));
      if(monsterLevel <= levelSum && !inVector(monsters.getIndex(i), lastEncounter)){
        if((monsterLevel != 0 || zeroCount < 2)){
          levelSum -= monsterLevel;
          encounter.push_back(monsters.getIndex(i));
        }
        if(monsterLevel == 0){
          zeroCount ++;
        }
      }
      if(levelSum == 0){
        for(int i = 0; i < encounter.size(); i++){
          cout << encounter[i] << "| CR " << monstersTree.searchItem(monsters.getIndex(monsters.hashFunction(encounter[i]))) << endl;
        }
        return encounter;
      }
    }
    if(i >= 10312){
      i = -1;
    }
  }
}


int printMainMenu(){
  while(true){
    string choice = "";
    cout << "1: Manage Party" << endl;
    cout << "2: Generate Encounter" << endl;
    cout << "3: Save" << endl;
    cout << "4. Get Data" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    if(isdigit(choice[0]) && stoi(choice) < 6 && stoi(choice) > 0){
      return stoi(choice);
    }
    cout << "That's not a valid input! Please try again!" << endl;
  }
}

void getDataMenu(){
  string choice;
  while(true){
    choice = "";
    cout << "1: Get Item Data" << endl;
    cout << "2: Get Spell Data" << endl;
    cout << "3: Get Ability Data" << endl;
    cout << "4. Go Back" << endl;
    cin >> choice;
    if(isdigit(choice[0]) && stoi(choice) < 6 && stoi(choice) > 0){
      break;
    }
    cout << "That's not a valid input! Please try again!" << endl;
  }
  switch(stoi(choice)){
    case 1:
      cout << "What item would you like data for?" << endl;
      choice = "";
      cin >> choice;
      if(items.searchItem(choice) == ""){
        cout << "No data available" << endl;
      }else{
        cout << choice << " has a rarity of " << items.searchItem(choice) << endl;
      }
      break;
    case 2:
      cout << "What spell would you like data for?" << endl;
      choice = "";
      cin >> choice;
      if(spells.searchItem(choice) == ""){
        cout << "No data available" << endl;
      }else{
        cout << choice << " is level " << spells.searchItem(choice) << endl;
      }
      break;
    case 3:
      cout << "What ability would you like data for?" << endl;
      choice = "";
      cin >> choice;
      if(abilities.searchItem(choice) == ""){
        cout << "No data available" << endl;
      }else{
        cout << choice << " has " << abilities.searchItem(choice) << " max charges" << endl;
      }
      break;
    default:
      return;
  }
}

void managePartyMenu(){
  string choice;
  string choice2;
  while(true){
    choice = "";
    cout << "------------------" << endl;
    cout << "1: Edit Player" << endl;
    cout << "2: Print Party" << endl;
    cout << "3: Print Money" << endl;
    cout << "4: Edit Party Money" << endl;
    cout << "5: Add Item" << endl;
    cout << "6: Modify Item" << endl;
    cout << "7: Delete Item" << endl;
    cout << "8: Print Party Inventory" << endl;
    cout << "9: Go Back" << endl;
    cout << "------------------" << endl;
    cin >> choice;
    if(isdigit(choice[0]) && stoi(choice) < 10 && stoi(choice) > 0){
      break;
    }
    cout << "That's not a valid input! Please try again!" << endl;
  }
  switch(stoi(choice)){
    case 1:
      cout << "What player would you like to edit?" << endl;
      choice = "";
      cin >> choice;
      party.editPlayer(choice);
      break;
    case 2:
      party.printPlayers();
      break;
    case 3:
      party.printMoney();
      break;
    case 4:
      while(true){
          cout << "------------------" << endl;
          cout << "1: Copper" << endl;
          cout << "2: Silver" << endl;
          cout << "3. Electrum" << endl;
          cout << "4: Gold" << endl;
          cout << "5: Platinum" << endl;
          cout << "------------------" << endl;
          choice = "";
          cin >> choice;
          if(isdigit(choice[0]) && stoi(choice) < 6 && stoi(choice) > 0){
            break;
          }
          cout << "That's not a valid input! Please try again!" << endl;
        }
        switch(stoi(choice)){
          case 1:
            cout << "How much would you like to withdraw or deposit?" << endl;
            choice = "";
            cin >> choice;
            party.modifyMoney(stoi(choice), 0, 0, 0, 0);
            break;
          case 2:
            cout << "How much would you like to withdraw or deposit?" << endl;
            choice = "";
            cin >> choice;
            party.modifyMoney(0, stoi(choice), 0, 0, 0);
            break;
          case 3:
            cout << "How much would you like to withdraw or deposit?" << endl;
            choice = "";
            cin >> choice;
            party.modifyMoney(0, 0, stoi(choice), 0, 0);
            break;
          case 4:
            cout << "How much would you like to withdraw or deposit?" << endl;
            choice = "";
            cin >> choice;
            party.modifyMoney(0, 0, 0, stoi(choice), 0);
            break;
          default:
            cout << "How much would you like to withdraw or deposit?" << endl;
            choice = "";
            cin >> choice;
            party.modifyMoney(0, 0, 0, 0, stoi(choice));
            break;
        }
      break;
    case 5:
      cout << "What is the item's name?" << endl;
      choice = "";
      cin >> choice;
      cout << "What is the item's quantity?" << endl;
      choice2 = "";
      cin >> choice2;
      party.addItem(choice, stoi(choice2));
      break;
    case 6:
      cout << "What is the item's name?" << endl;
      choice = "";
      cin >> choice;
      cout << "What is the item's quantity?" << endl;
      choice2 = "";
      cin >> choice2;
      party.modifyItem(choice, stoi(choice2));
      break;
    case 7:
      cout << "What item would you like to delete?" << endl;
      choice = "";
      cin >> choice;
      party.deleteItem(choice);
      break;
    case 8:
      cout << "--------------------" << endl;
      cout << "Party Inventory:" << endl;
      party.printAllItems(); 
      cout << "--------------------" << endl;
      break;
    default:
      return;
  }
}

int mainChoice = 0;

int main(){
  readInitData();
  readInitPlayers();
  

  vector<string> lastEncounter;
  vector<string> latestHolder;
  lastEncounter.push_back("ape");
  lastEncounter.push_back("bat");
  lastEncounter.push_back("baboon");
  lastEncounter.push_back("elk");
  lastEncounter.push_back("ape");
  lastEncounter.push_back("bat");
  lastEncounter.push_back("cat");
  time_t currentTime;
  while(true){
    mainChoice = printMainMenu();
    switch(mainChoice){
      case 1:
        managePartyMenu();
        break;
      case 2:
        latestHolder = generateEncounter(lastEncounter);
        lastEncounter.insert(lastEncounter.end(), latestHolder.begin(), latestHolder.end());
        srand(time(&currentTime));
        for(int i = 0; i < latestHolder.size(); i++){
          lastEncounter.erase(lastEncounter.begin() + rand() % lastEncounter.size());
        }
        break;
      case 3:
        cout << "Sorry, this function is not yet implemented" << endl;
        break;
      case 4:
        getDataMenu();
        break;
      default:
        cout << "Goodbye" << endl;
        return 0;
    }   
  }
}