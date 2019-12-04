#include <iostream>
#include "Player.hpp"
#include <string>

using namespace std;

struct identityInfoStruct{
  string playerName;
  string characterName;
  string characterNickname;
  string race;
  string background;
};

identityInfoStruct identityInfo;

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
  if(infoType) == "playerName"{
    return identityInfo.playerName;
  }
  if(infoType) == "charName"{
    return identityInfo.characterName;
  }
  if(infoType) == "charNickname"{
    return identityInfo.characterNickname;
  }
  if(infoType) == "race"{
    return identityInfo.race;
  }
  if(infoType) == "background"{
    return identityInfo.background;
  }
}

struct classType{
  int classLevel;
  string className;
  string subClass;
};

struct skillData{
  bool proficient;
  bool expertise;
  int modifier;
};

skillData savingThrows[6];

skillData skills[18];

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

struct stats{
  int currentHealth;
  int maxHealth;
  int AC;
  int initiative;
  int speed;
  int passiveWis;
  int totalLevel;
  //str/dex/con/int/wis/cha
  int statArr[6];
  vector <classType> classes;
};

void setStats(int currHealth, int maxHealth, int ac, int initiative, int speed, int passiveWis, int totalLevel, int* statArr, vector <classType> classVect){
  stats.currentHealth
}



//BST for items here
//BST for abilities
// BST for spells

struct currencyStruct{
  int copper;
  int silver;
  int electrum;
  int gold;
  int platinum;
};

currencyStruct currency;

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

int statModifierCalc(int stat){
  return floor((stat - 10) / 2);
}

#endif
