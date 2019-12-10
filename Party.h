#ifndef PARTY_H
#define PARTY_H
#include "Player.h"
#include "BST.h"
#include <string>
#include <vector>

using namespace std;

struct currencyStructParty{
  int copper;
  int silver;
  int electrum;
  int gold;
  int platinum;
};

class Party{
    private:
        vector <Player> players;
        currencyStructParty currency;
        BST items;
        string currencyNamesParty[5] = {"Copper", "Silver", "Electrum", "Gold", "Platinum"};

    public:
        Party();
        void modifyMoney(int copper, int silver, int electrum, int gold, int platinum);
        void addItem(string name, int data);
        void deleteItem(string name);
        void modifyItem(string name, int newData);
        int getPartySize();
        void addPlayer(string playerName, string charName, string charNickname, string race, string background,
                        vector<int> classLevel, vector<string> className, vector<string> subClass,
                        bool savingThrowProf[6], bool savingThrowExpert[6], int savingThrowMod[6],
                        bool skillProf[18], bool skillExpert[18], int skillMod[18],
                        int currHealth, int maxHealth, int ac, int initiative, int speed, int passiveWis,
                        int totalLevel, int profBonus, int statArr[6], vector<string> items, vector<int> itemsData, vector<string> spells, vector<int> spellData,
                        vector<string> abilities, vector<int> abilitiesData, int currency[5]);
        void addPlayerByInput(Player player);
        int getPlayerStats(string statType, int index);
        void editPlayer(string playerName);
        void deletePlayer(string playerName);
        void printMoney();
        void printAllItems();
        void printPlayers();
};
#endif