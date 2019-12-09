#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct identityInfoStruct{
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

struct statsStruct{
  int currentHealth;//
  int maxHealth;//
  int AC;//
  int initiative;//
  int speed;
  int passiveWis;
  int totalLevel;//
  int proficiencyBonus;
  //str/dex/con/int/wis/cha
  int statArr[6];
};

struct currencyStruct{
  int copper;
  int silver;
  int electrum;
  int gold;
  int platinum;
};


class Player{
  private:
    identityInfoStruct identityInfo;
    vector <classType> classes;
    skillData savingThrows[6];
    skillData skills[18];
    statsStruct stats;
    currencyStruct currency;
    string statArrNames[6] = {"Str", "Dex", "Con", "Int", "Wis", "Cha"};
    string skillArrNames[18] = {"Acrobatics", "Animal Handling", "Arcana", "Athletics", "Deception", "History",
                              "Insight", "Intimidation", "Investigation", "Medicine", "Nature", "Perception",
                              "Performance", "Persuasion", "Religion", "Sleight of Hand", "Stealth", "Survival"};
    string currencyNames[5] = {"Copper", "Silver", "Electrum", "Gold", "Platinum"};

  public:
    Player();
    void deletePlayer();

    void setIdentityInfo(string playerName, string charName, string charNickname, string race, string background);
    string getIdentityInfo(string infoType);

    void addClass(int classLevel, string className, string subClass);
    vector <classType> getClasses();

    void setSavingThrows(int index, bool proficient, bool expertise, int modifier);
    skillData getSavingThrows(int index);

    void setSkills(int index, bool proficient, bool expertise, int modifier);
    skillData getSkills(int index);

    void setStats(int currHealth, int maxHealth, int ac, int initiative, int speed, int passiveWis, int totalLevel, int profBonus, int* statArr);
    int getStats(string statType);

    void addItem(string name, int data, string treeType);
    void modifyItem(string name, int newData, string treeType);
    void deleteItem(string name, string treeType);
    void printAllItems(string type);

    void setCurrency(int copper, int silver, int electrum, int gold, int platinum);
    int getCurrency(string currencyType);

    void printCharacter();
    void printSkills();
    void printCurrency();

};
#endif