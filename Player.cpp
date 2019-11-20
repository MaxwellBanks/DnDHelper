#include <iostream>
#include "Player.hpp"
#include <string>

using namespace std;

struct identityInfo{
  string playerName;
  string characterName;
  string characterNickname;
  string race;
  string background;
};

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
};

struct attack{
  string weaponName;
  int hitBonus;
  int damageDice;
  int damageDiceQuantity;
  int damageModifier;
  string type;
  bool thrown;
  int range;
  int disadvantageRange;
}

//BST for items here
//BST for abilities
// BST for spells

struct currency{
  int copper;
  int silver;
  int electrum;
  int gold;
  int platinum;
};

int statModifierCalc(int stat){
  return floor((stat - 10) / 2);
}

struct physicalFeatures{
  int age;
  float height;
  int weight;
  string eyeColor;
  string skinColor;
  string hairColor;
};


#endif
