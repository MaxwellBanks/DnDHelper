#include "Player.h"
#include "ItemHash.h"
#include "Party.h"
#include "BST.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <locale>
#include <time.h>

using namespace std;

ItemHash spells(10313);
ItemHash items(10313);
ItemHash abilities(593);
ItemHash monsters(10313);

BST monstersTree;

Party party;

BST bst("ability");

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
}

void readInitPlayers(){
  ifstream iPlayers;
  iPlayers.open("Players.csv");
  if(!iPlayers.is_open()){
    cout << "File Players.csv cannot be opened" << endl;
    return;
  }
  string line;
  string countlong;
  string countshort;
  string hold1;
  string hold2;
  string hold3;
  string hold4;
  string hold5;
  string hold6;
  string hold7;
  string hold8;
  bool profHold;
  bool expHold;
  int holdStats[6];
  string holdSkills[18];
  stringstream ss;
  getline(iPlayers, countlong);
  for(int i = 0; i < stoi(countlong); i++){
    Player player;
    line = "";
    getline(iPlayers, line);
    ss.str(line);
    getline(ss, hold1, ',');
    getline(ss, hold2, ',');
    getline(ss, hold3);
    ss.str("");
    getline(iPlayers, line);
    ss.str(line);
    getline(ss, hold4, ',');
    getline(ss, hold5, ',');
    player.setIdentityInfo(hold1, hold2, hold3, hold4, hold5);
    hold1 = hold2 = hold3 = hold4 = hold5 = "";
    //holding total level
    getline(ss, hold8);
    countshort = "";
    getline(iPlayers, countshort);
    for(int j = 0; j < stoi(countshort); j++){
      getline(iPlayers, line);
      cout << line;
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2, ',');
      getline(ss, hold3);
      //player.addClass(stoi(hold3), hold1, hold2);
      hold1 = hold2 = hold3 = "";
    }/*
    countshort = "";
    for(int j = 0; j < 6; j++){
      getline(iPlayers, line);
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
      player.setSavingThrows(i, profHold, expHold, stoi(hold3));
      hold1 = hold2 = hold3 = "";
    }
    for(int j = 0; j < 18; j++){
      getline(iPlayers, line);
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
      player.setSkills(i, profHold, expHold, stoi(hold3));
      hold1 = hold2 = hold3 = "";
    }
    getline(iPlayers, line);
    ss.str(line);
    //currhealth
    getline(ss, hold1, ',');
    //maxhealth
    getline(ss, hold2, ',');
    //ac
    getline(ss, hold3, ',');
    //initiative
    getline(ss, hold4);
    getline(iPlayers, line);
    ss.str(line);
    //speed
    getline(ss, hold5, ',');
    //passivewis
    getline(ss, hold6, ',');
    //profbonus
    getline(ss, hold7, ',');
    getline(iPlayers, line);
    ss.str(line);
    //stats
    for(int j = 0; j < 6; j++){
      getline(ss, hold1, ',');
      holdStats[i] = stoi(hold1);
      hold1 = "";
    }
    player.setStats(stoi(hold1), stoi(hold2), stoi(hold3), stoi(hold4), stoi(hold5), stoi(hold6), stoi(hold8), stoi(hold7), holdStats);
    hold1 = hold2 = hold3 = hold4 = hold5 = hold6 = hold7 = hold8 = "";
    getline(iPlayers, line);
    ss.str(line);
    for(int j = 0; j < 5; j++){
      getline(ss, hold1, ',');
      holdStats[i] = stoi(hold1);
      hold1 = "";
    }
    player.setCurrency(holdStats[0], holdStats[1], holdStats[2], holdStats[3], holdStats[4]);
    getline(iPlayers, countshort);
    for(int j = 0; j < stoi(countshort); j++){
      hold1 = hold2 = "";
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2);
      player.addItem(hold1, stoi(hold2), "item");
    }
    hold1 = "";
    countshort = "";
    getline(iPlayers, countshort);
    for(int j = 0; j < stoi(countshort); j++){
      hold1 = hold2 = "";
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2);
      player.addItem(hold1, stoi(hold2), "spell");
    }
    hold1 = "";
    countshort = "";
    getline(iPlayers, countshort);
    for(int j = 0; j < stoi(countshort); j++){
      hold1 = hold2 = "";
      getline(iPlayers, line);
      ss.str(line);
      getline(ss, hold1, ',');
      getline(ss, hold2);
      player.addItem(hold1, stoi(hold2), "ability");
    }*/
  }
  iPlayers.close();
}

void generateEncounter(){
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
  srand(time(0));
  int start = rand() % 10313;
  for(int i = start; i < 10313; i++){
    if(!monsters.getIndex(i).empty()){
      monsterLevel = monstersTree.searchItem(monsters.getIndex(i));
      if(monsterLevel <= levelSum){
        if((monsterLevel != 0 || zeroCount < 3)){
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
        return;
      }
    }
    if(i == 10312){
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

int mainChoice = 0;

int main(){
  readInitData();
  //readInitPlayers();


  vector <int> testClassLevel;
  vector <string> testClass;
  vector <string> testSubClass;
  testClassLevel.push_back(5);
  testClass.push_back("bard");
  testSubClass.push_back("college of lore");
  bool allFalse[6];
  bool allTrue[18];
  int longstatArr[18];
  for(int i = 0; i< 6; i++){
    allFalse[i] = false;
  }
  for(int i = 0; i < 18; i++){
    allTrue[i] = true;
    longstatArr[i] = i % 3;
  }
  int statArr[6] = {15, 14, 13, 12, 11, 10};
  int currArr[5] = {1, 2, 3, 4, 5};
  party.addPlayer("testname", "testchar", "test nick", "testrace", "testbkgd", testClassLevel, testClass,
                  testSubClass, allFalse, allFalse, statArr, allTrue, allTrue, longstatArr, 37, 40, 15, 3, 
                  30, 12, 5, 3, statArr, testClass, testClassLevel, testClass, testClassLevel, testClass, testClassLevel, currArr);
  party.printPlayers();


  while(true){
    mainChoice = printMainMenu();
    switch(mainChoice){
      case 1:
        break;
      case 2:
        generateEncounter();
        break;
      case 3:
        break;
      case 4:
        getDataMenu();
        break;
      default:
        cout << "Goodbye" << endl;
        return 0;
    }
      
  }
  /*
  test.setIdentityInfo("Max", "Varis", "Var", "Elf", "Charlatain");
  int statArr[6] = {15, 14, 13, 12, 11, 10};
  test.setStats(37, 40, 16, 2, 30, 12, 5, 3, statArr);
  test.addClass(5, "Bard", "College of Lore");
  test.addClass(2, "Rogue", "Arcane Trickster");
  test.setSavingThrows(0, false, false, 2);
  test.setSavingThrows(1, true, false, 4);
  test.setSavingThrows(2, false, false, 2);
  test.setSavingThrows(3, true, true, 8);
  test.setSavingThrows(4, false, false, 2);
  test.setSavingThrows(5, false, false, 2);
  for(int i = 0; i < 18; i ++){
    test.setSkills(i, i % 2, i % 3, 6);
  }
  test.setCurrency(10, 20, 30, 40, 50);
  //test.printCharacter();

  items.readData("testData1.txt");
  //items.printTable();
  items.writeData("testData2.txt");

  bst.addItem("ability1", 1);
  bst.addItem("ability2", 2);
  bst.addItem("ability4", 4);
  bst.addItem("ability3", 3);
  //bst.printTree();
  bst.deleteItem("ability5");
  //test.printSkills();
  //test.printCurrency();
  bst.printTree();
  monsters.printTable();
  spells.printTable();
  items.printTable();
  abilities.printTable();*/
}
