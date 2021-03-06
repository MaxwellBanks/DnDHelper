#include <iostream>
#include <vector>
#include "Player.h"
#include <string>
#include <cmath>
#include "BST.h" 

using namespace std;

//BST for items here
BST item("item");
//BST for abilities
BST ability("ability");
// BST for spells
BST spell("spell");

Player::Player(){
}

void Player::deletePlayer(){
  item.~BST();
  ability.~BST();
  spell.~BST();
}


//Identity Info
void Player::setIdentityInfo(string playerName, string charName, string charNickname, string race, string background){
  if(!playerName.empty()){
    identityInfo.playerName = playerName;
  }
  if(!charName.empty()){
    identityInfo.characterName = charName;
  }
  if(!charNickname.empty()){
    identityInfo.characterNickname = charNickname;
  }
  if(!race.empty()){
    identityInfo.race = race;
  }
  if(!background.empty()){
    identityInfo.background = background;
  }
}

string Player::getIdentityInfo(string infoType){
  if(infoType == "playerName"){
    return identityInfo.playerName;
  }
  if(infoType == "charName"){
    return identityInfo.characterName;
  }
  if(infoType == "charNickname"){
    return identityInfo.characterNickname;
  }
  if(infoType == "race"){
    return identityInfo.race;
  }
  if(infoType == "background"){
    return identityInfo.background;
  }
}

///////////////////////////////////////////////////////////////////////////////
//DND Class Info
void Player::addClass(int classLevel, string className, string subClass){
  classType newClass;
  newClass.classLevel = classLevel;
  newClass.className = className;
  newClass.subClass = subClass;
  classes.push_back(newClass);
  stats.totalLevel = 0;
  for(int i = 0; i < classes.size(); i++){
    stats.totalLevel += classes[i].classLevel;
  }
}

vector <classType> Player::getClasses(){
  return classes;
}

///////////////////////////////////////////////////////////////////////////////
//Skills/Saving Throws Data
void Player::setSavingThrows(int index, bool proficient, bool expertise, int modifier){
  savingThrows[index].proficient = proficient;
  savingThrows[index].expertise = expertise;
  savingThrows[index].modifier = modifier;
}

skillData Player::getSavingThrows(int index){
  return savingThrows[index];
}

void Player::setSkills(int index, bool proficient, bool expertise, int modifier){
  skills[index].proficient = proficient;
  skills[index].expertise = expertise;
  skills[index].modifier = modifier;
}

skillData Player::getSkills(int index){
  return skills[index];
}

///////////////////////////////////////////////////////////////////////////////
//Stats Data
void Player::setStats(int currHealth, int maxHealth, int ac, int initiative, int speed, int passiveWis, int totalLevel, int profBonus, int* statArr){
  if(currHealth){
      stats.currentHealth = currHealth;
  }
  if(maxHealth){
    stats.maxHealth = maxHealth;
  }
  if(ac){
    stats.AC = ac;
  }
  if(initiative){
    stats.initiative = initiative;
  }
  if(speed){
    stats.speed = speed;
  }
  if(passiveWis){
    stats.passiveWis = passiveWis;
  }
  if(totalLevel){
    stats.totalLevel = totalLevel;
  }
  if(profBonus){
    stats.proficiencyBonus = profBonus;
  }
  for(int i = 0; i < 6; i++){
    if(statArr[i]){
      stats.statArr[i] = statArr[i];
    }
  }
}

int Player::getStats(string statType){
  if(statType == "currentHealth"){
    return stats.currentHealth;
  }else if(statType == "maxHealth"){
    return stats.maxHealth;
  }else if(statType == "AC"){
    return stats.AC;
  }else if(statType == "initiative"){
    return stats.initiative;
  }else if(statType == "speed"){
    return stats.speed;
  }else if(statType == "passiveWis"){
    return stats.passiveWis;
  }else if(statType == "totalLevel"){
    return stats.totalLevel;
  }else if(statType == "proficiencyBonus"){
    return stats.proficiencyBonus;
  }else if(statType == "Str"){
    return stats.statArr[0];
  }else if(statType == "Dex"){
    return stats.statArr[1];
  }else if(statType == "Con"){
    return stats.statArr[2];
  }else if(statType == "Int"){
    return stats.statArr[3];
  }else if(statType == "Wis"){
    return stats.statArr[4];
  }else if(statType == "Cha"){
    return stats.statArr[5];
  }
}

//////////////////////////////////////////////////////////////////////////////

void Player::addItem(string name, int data, string treeType){
  if(treeType == "item"){
    item.addItem(name, data);
  }else if(treeType == "ability"){
    ability.addItem(name, data);
  }else{
    spell.addItem(name, data);
  }
}

void Player::modifyItem(string name, int newData, string treeType){
  if(treeType == "item"){
    item.modifyItem(name, newData);
  }else if(treeType == "ability"){
    ability.modifyItem(name, newData);
  }else{
    spell.modifyItem(name, newData);
  }
}

void Player::deleteItem(string name, string treeType){
  if(treeType == "item"){
    item.deleteItem(name);
  }else if(treeType == "ability"){
    ability.deleteItem(name);
  }else{
    spell.deleteItem(name);
  }
}

void Player::printAllItems(string type){
  if(type == "item"){
    item.printTree();
  }else if(type == "ability"){
    ability.printTree();
  }else{
    spell.printTree();
  }
}

//Currency Data
void Player::setCurrency(int copper, int silver, int electrum, int gold, int platinum){
  currency.copper += copper;
  currency.silver += silver;
  currency.electrum += electrum;
  currency.gold += gold;
  currency.platinum += platinum;
}

int Player::getCurrency(string currencyType){
  if(currencyType == "copper"){
    return currency.copper;
  }else if(currencyType == "silver"){
    return currency.silver;
  }else if(currencyType == "electrum"){
    return currency.electrum;
  }else if(currencyType == "gold"){
    return currency.gold;
  }else{
    return currency.platinum;
  }
}

///////////////////////////////////////////////////////////////////////////////
int statModifierCalc(int stat){
  return floor((stat - 10) / 2);
}

void Player::printCharacter(){
  cout << "##########################################" << endl;
  cout << "##| " << identityInfo.playerName << " '" << identityInfo.characterName << " / " << identityInfo.characterNickname << "'" << endl;
  cout << "##| Level " << stats.totalLevel << " || " << identityInfo.race << " || " << identityInfo.background << endl;
  cout << "##";
  for(int i = 0; i < classes.size(); i++){
    cout << "| Lvl " << classes[i].classLevel << " " << classes[i].className << " (" << classes[i].subClass << ") |";
  }
  cout << endl;
  cout << "##| Health: " << stats.currentHealth << "/" << stats.maxHealth << " || AC: " << stats.AC << " || Initiative: " << stats.initiative << endl;
  cout << "##| Speed: " << stats.speed << " || Passive Wis: " << stats.passiveWis << " || Proficiency Bonus: " << stats.proficiencyBonus << endl;
  cout << "##| Stats| ";
  for(int i = 0; i < 6; i++){
    cout << statArrNames[i] << ": " << stats.statArr[i] << " ";
  }
  cout << endl << "## | Stat Mods | ";
  for(int i = 0; i < 6; i++){
    cout << statArrNames[i] << ": " << statModifierCalc(stats.statArr[i]);
  }
  cout << endl << "##########################################" << endl;
}

void Player::printSkills(){
  for(int i = 0; i < 18; i++){
    cout << skillArrNames[i] << ": " << skills[i].modifier;
    if(skills[i].expertise){
      cout << "(E)";
    }else if(skills[i].proficient){
      cout << "(P)";
    }
    if((i % 3) == 2){
      cout << endl;
    }else{
      cout << " || ";
    }
  }
}

void Player::printCurrency(){
  cout << currencyNames[0] << ": " << currency.copper << endl;
  cout << currencyNames[1] << ": " << currency.silver << endl;
  cout << currencyNames[2] << ": " << currency.electrum << endl;
  cout << currencyNames[3] << ": " << currency.gold << endl;
  cout << currencyNames[4] << ": " << currency.platinum << endl;
}