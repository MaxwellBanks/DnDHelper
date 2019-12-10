#include "Party.h"
#include "Player.h"
#include "BST.h"
#include <iostream>

using namespace std;

BST partyItems("item");

Party::Party(){
}

void Party::modifyMoney(int copper, int silver, int electrum, int gold, int platinum){
    currency.copper += copper;
    currency.silver += silver;
    currency.electrum += electrum;
    currency.gold += gold;
    currency.platinum += platinum;
}

void Party::addItem(string name, int data){
    partyItems.addItem(name, data);
}

void Party::deleteItem(string name){
    partyItems.deleteItem(name);
}

void Party::modifyItem(string name, int newData){
    partyItems.modifyItem(name, newData);
}

void Party::addPlayer(string playerName, string charName, string charNickname, string race, string background,
                        vector<int> classLevel, vector<string> className, vector<string> subClass,
                        bool savingThrowProf[6], bool savingThrowExpert[6], int savingThrowMod[6],
                        bool skillProf[18], bool skillExpert[18], int skillMod[18],
                        int currHealth, int maxHealth, int ac, int initiative, int speed, int passiveWis,
                        int totalLevel, int profBonus, int statArr[6], vector<string> items, vector<int> itemsData, vector<string> spells, vector<int> spellData,
                        vector<string> abilities, vector<int> abilitiesData, int currency[5]){
    Player newPlayer;
    newPlayer.setIdentityInfo(playerName, charName, charNickname, race, background);
    for(int i = 0; i < classLevel.size(); i++){
        newPlayer.addClass(classLevel[i], className[i], subClass[i]);
    }
    for(int i = 0; i < 6; i++){
        newPlayer.setSavingThrows(i, savingThrowProf[i], savingThrowExpert[i], savingThrowMod[i]);
    }
    for(int i = 0; i < 18; i++){
        newPlayer.setSkills(i, skillProf[i], skillExpert[i], skillMod[i]);
    }
    newPlayer.setStats(currHealth, maxHealth, ac, initiative, speed, passiveWis, totalLevel, profBonus, statArr);
    for(int i = 0; i < items.size(); i++){
        newPlayer.addItem(items[i], itemsData[i], "item");
    }
    for(int i = 0; i < abilities.size(); i++){
        newPlayer.addItem(abilities[i], abilitiesData[i], "ability");
    }
    for(int i = 0; i < spells.size(); i++){
        newPlayer.addItem(spells[i], spellData[i], "spell");
    }
    newPlayer.setCurrency(currency[0], currency[1], currency[2], currency[3], currency[4]);
    players.push_back(newPlayer);
}

void Party::addPlayerByInput(Player player){
    players.push_back(player);
}

void Party::editPlayer(string playerName){
    Player* toEdit = new Player;
    toEdit = NULL;
    for(int i = 0; i < players.size(); i++){
        if(players[i].getIdentityInfo("playerName") == playerName){
            toEdit = &players[i];
        }
    }
    if(!toEdit){
        cout << "Sorry, that's not a valid player!" << endl;
        return;
    }
    cout << "Please input what you'd like to edit ('help' for help)" << endl;
    string userInput = "";
    string userInput2 = "";
    string newName = "";
    string newData = "";
    string newData2 = "";
    int newStats[6] = {0, 0, 0, 0, 0, 0};
    cin >> userInput;
    if(userInput == "help"){
        cout << "Format: <What to edit>: <command>" << endl;
        cout << "Character Name: charname" << endl;
        cout << "Character Nickname: charnickname" << endl;
        cout << "Race: race" << endl;
        cout << "Background: background" << endl;
        cout << "Class Info: classinfo" << endl;
        cout << "Saving Throws: savingthrows" << endl;
        cout << "Skills: skills" << endl;
        cout << "Max Health: maxhealth" << endl; 
        cout << "Current Health: currhealth" << endl;
        cout << "Armor Class: ac" << endl;
        cout << "Initiative: initiative" << endl;
        cout << "Speed: speed" << endl;
        cout << "Passive Wisdom: passivewis" << endl;
        cout << "Proficiency Bonus: profbonus" << endl;
        cout << "Stats: stats" << endl;
        cout << "Items: items" << endl;
        cout << "Abilities: abilities" << endl;
        cout << "Spells: spells" << endl;
        cout << "Currency: currency" << endl;
        editPlayer(playerName);
    }else if(userInput == "charname"){
        cout << "Please input new character name" << endl;
        cin >> newName;
        cout << "Name " << toEdit->getIdentityInfo("playerName") << " has been changed to " << newName << endl;
        toEdit->setIdentityInfo("", newName, "", "", "");
    }else if(userInput == "charnickname"){
        cout << "Please input new character nickname" << endl;
        cin >> newName;
        cout << "Nickname " << toEdit->getIdentityInfo("playerName") << " has been changed to " << newName << endl;
        toEdit->setIdentityInfo("", "", newName, "", "");
    }else if(userInput == "race"){
        cout << "Please input new character race" << endl;
        cin >> newName;
        cout << "Race " << toEdit->getIdentityInfo("playerName") << " has been changed to " << newName << endl;
        toEdit->setIdentityInfo("", "", "", newName, "");
    }else if(userInput == "background"){
        cout << "Please input new character background" << endl;
        cin >> newName;
        cout << "Background " << toEdit->getIdentityInfo("playerName") << " has been changed to " << newName << endl;
        toEdit->setIdentityInfo("", "", "", "", newName);
    }else if(userInput == "classinfo"){
        while(true){
            cout << "Would you like to add a class (add) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "add"){
                cout << "Input Class Name" << endl;
                cin >> newName;
                cout << "Input Class Level" << endl;
                cin >> newData;
                cout << "Input SubClass" << endl;
                cin >> newData2;
                toEdit->addClass(stoi(newData), newName, newData2);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "savingthrows"){
        string profex = "";
        bool prof;
        bool expert;
        while(true){
            cout << "Woud you like to edit saving throws (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                while(true){
                    newData = "";
                    newData2 = "";
                    cout << "Which saving throw would you like to edit? (str/dex/con/int/wis/cha)" << endl;
                    cin >> newData;
                    cout << "Input new modifier: " << endl;
                    cin >> newData2;
                    cout << "If expertise, type e. Otherwise, if proficient type p." << endl;
                    cin >> profex;
                    if(profex == "e"){
                        expert = true;
                        prof = true;
                    }else if(profex == "p"){
                        expert = false;
                        prof = true;
                    }else{
                        expert = false;
                        prof = false;
                    }
                    if(newData == "str"){
                        toEdit->setSavingThrows(0, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "dex"){
                        toEdit->setSavingThrows(1, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "con"){
                        toEdit->setSavingThrows(2, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "int"){
                        toEdit->setSavingThrows(3, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "wis"){
                        toEdit->setSavingThrows(4, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "cha"){
                        toEdit->setSavingThrows(5, prof, expert, stoi(newData2));
                        break;
                    }else{
                        cout << "That's not a valid option! Please try again." << endl;
                        newData = "";
                        newData2 = "";
                        profex = "";
                    }
                }
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "skills"){
        string profex = "";
        bool prof;
        bool expert;
        while(true){
            cout << "Woud you like to edit skills (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                while(true){
                    newData = "";
                    newData2 = "";
                    cout << "Which skill would you like to edit? (acrobatics/animalhandling/arcana/athletics/deception/history/)" << endl;
                    cout << "insight/intimidation/investigation/medicine/nature/perception/" << endl;
                    cout << "performance/persuasion/religion/sleightofhand/stealth/survival" << endl;
                    cin >> newData;
                    cout << "Input new modifier: " << endl;
                    cin >> newData2;
                    cout << "If expertise, type e. Otherwise, if proficient type p." << endl;
                    cin >> profex;
                    if(profex == "e"){
                        expert = true;
                        prof = true;
                    }else if(profex == "p"){
                        expert = false;
                        prof = true;
                    }else{
                        expert = false;
                        prof = false;
                    }
                    if(newData == "acrobatics"){
                        toEdit->setSkills(0, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "animalhandling"){
                        toEdit->setSkills(1, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "arcana"){
                        toEdit->setSkills(2, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "athletics"){
                        toEdit->setSkills(3, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "deception"){
                        toEdit->setSkills(4, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "history"){
                        toEdit->setSkills(5, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "insight"){
                        toEdit->setSkills(6, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "intimidation"){
                        toEdit->setSkills(7, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "investigation"){
                        toEdit->setSkills(8, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "medicine"){
                        toEdit->setSkills(9, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "nature"){
                        toEdit->setSkills(10, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "perception"){
                        toEdit->setSkills(11, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "performance"){
                        toEdit->setSkills(12, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "persuasion"){
                        toEdit->setSkills(13, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "religion"){
                        toEdit->setSkills(14, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "sleightofhand"){
                        toEdit->setSkills(15, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "stealth"){
                        toEdit->setSkills(16, prof, expert, stoi(newData2));
                        break;
                    }else if(newData == "survival"){
                        toEdit->setSkills(17, prof, expert, stoi(newData2));
                        break;
                    }else{
                        cout << "That's not a valid option! Please try again." << endl;
                        newData = "";
                        newData2 = "";
                        profex = "";
                    }
                }
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "maxhealth"){
        while(true){
            cout << "Would you like to edit max health (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Max Health" << endl;
                cin >> newData;
                toEdit->setStats(0, stoi(newData), 0, 0, 0, 0, 0, 0, newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "currhealth"){
        while(true){
            cout << "Would you like to edit current health (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Current Health" << endl;
                cin >> newData;
                toEdit->setStats(stoi(newData), 0, 0, 0, 0, 0, 0, 0, newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "ac"){
        while(true){
            cout << "Would you like to edit armor class (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Armor Class" << endl;
                cin >> newData;
                toEdit->setStats(0, 0, stoi(newData), 0, 0, 0, 0, 0, newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "initiative"){
        while(true){
            cout << "Would you like to edit initiative (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Initative" << endl;
                cin >> newData;
                toEdit->setStats(0, 0, 0, stoi(newData), 0, 0, 0, 0, newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "speed"){
        while(true){
            cout << "Would you like to edit speed (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Speed" << endl;
                cin >> newData;
                toEdit->setStats(0, 0, 0, 0, stoi(newData), 0, 0, 0, newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "passiveWis"){
        while(true){
            cout << "Would you like to edit passive wisdom (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Passive Wisdom" << endl;
                cin >> newData;
                toEdit->setStats(0, 0, 0, 0, 0, stoi(newData), 0, 0, newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "profbonus"){
        while(true){
            cout << "Would you like to edit proficiency bonus (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input New Proficiency Bonus" << endl;
                cin >> newData;
                toEdit->setStats(0, 0, 0, 0, 0, 0, 0, stoi(newData), newStats);
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "stats"){
        while(true){
            cout << "Woud you like to edit stats (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                while(true){
                    newData = "";
                    newData2 = "";
                    cout << "Which stat would you like to edit? (str/dex/con/int/wis/cha)" << endl;
                    cin >> newData;
                    cout << "Input new value: " << endl;
                    cin >> newData2;
                    if(newData == "str"){
                        newStats[0] = stoi(newData2);
                        break;
                    }else if(newData == "dex"){
                        newStats[1] = stoi(newData2);
                        break;
                    }else if(newData == "con"){
                        newStats[2] = stoi(newData2);
                        break;
                    }else if(newData == "int"){
                        newStats[3] = stoi(newData2);
                        break;
                    }else if(newData == "wis"){
                        newStats[4] = stoi(newData2);
                        break;
                    }else if(newData == "cha"){
                        newStats[5] = stoi(newData2);
                        break;
                    }else{
                        cout << "That's not a valid option! Please try again." << endl;
                        newData = "";
                        newData2 = "";
                    }
                }
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "items"){
        while(true){
            cout << "Would you like to add an item (add), edit an item's quantity (edit), delete an item (delete), or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "add"){
                cout << "Input item name: " << endl;
                cin >> newData;
                cout << "Input item quantity: ";
                cin >> newData2;
                toEdit->addItem(newData, stoi(newData2), "item");
                break;
            }else if(userInput2 == "edit"){
                cout << "Input item name to edit: " << endl;
                cin >> newData;
                cout << "Input new quantity: ";
                cin >> newData2;
                toEdit->modifyItem(newData, stoi(newData2), "item");
                break;
            }else if(userInput2 == "delete"){
                cout << "Input item name to delete: " << endl;
                cin >> newData;
                toEdit->deleteItem(newData, "item");
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "abilities"){
        while(true){
            cout << "Would you like to add an ability (add), edit an ability's charges (edit), delete an ability (delete), or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "add"){
                cout << "Input ability name: " << endl;
                cin >> newData;
                cout << "Input ability charges: ";
                cin >> newData2;
                toEdit->addItem(newData, stoi(newData2), "ability");
                break;
            }else if(userInput2 == "edit"){
                cout << "Input ability name to edit: " << endl;
                cin >> newData;
                cout << "Input new charge count: ";
                cin >> newData2;
                toEdit->modifyItem(newData, stoi(newData2), "ability");
                break;
            }else if(userInput2 == "delete"){
                cout << "Input ability name to delete: " << endl;
                cin >> newData;
                toEdit->deleteItem(newData, "ability");
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "spells"){
        while(true){
            cout << "Would you like to add an spell (add), edit an spell's level (edit), delete an spell (delete), or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "add"){
                cout << "Input spell name: " << endl;
                cin >> newData;
                cout << "Input spell level: ";
                cin >> newData2;
                toEdit->addItem(newData, stoi(newData2), "spell");
                break;
            }else if(userInput2 == "edit"){
                cout << "Input spell name to edit: " << endl;
                cin >> newData;
                cout << "Input new level: ";
                cin >> newData2;
                toEdit->modifyItem(newData, stoi(newData2), "spell");
                break;
            }else if(userInput2 == "delete"){
                cout << "Input spell name to delete: " << endl;
                cin >> newData;
                toEdit->deleteItem(newData, "spell");
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else if(userInput == "currency"){
        while(true){
            cout << "Would you like to edit currency (edit) or go back (back)?" << endl;
            cin >> userInput2;
            if(userInput2 == "edit"){
                cout << "Input Copper Difference" << endl;
                cin >> newData;
                toEdit->setCurrency(stoi(newData), 0, 0, 0, 0);
                newData = "";
                cout << "Input Silver Difference" << endl;
                cin >> newData;
                toEdit->setCurrency(0, stoi(newData), 0, 0, 0);
                newData = "";
                cout << "Input Electrum Difference" << endl;
                cin >> newData;
                toEdit->setCurrency(0, 0, stoi(newData), 0, 0);
                newData = "";
                cout << "Input Gold Difference" << endl;
                cin >> newData;
                toEdit->setCurrency(0, 0, 0, stoi(newData), 0);
                newData = "";
                cout << "Input Platinum Difference" << endl;
                cin >> newData;
                toEdit->setCurrency(0, 0, 0, 0, stoi(newData));
                newData = "";
                break;
            }else if(userInput2 == "back"){
                break;
            }else{
                cout << "That's not a valid option! Please try again." << endl;
                userInput2 == "";
            }
        }
    }else{
        cout << "Invalid command, please try again" << endl;
        editPlayer(playerName);
    }
}

void Party::deletePlayer(string playerName){
    cout << "Are you sure you would like to delete " << playerName << "? (y/n) This cannot be undone.";
    string playerInput = "";
    cin >> playerInput;
    if(playerInput == "y"){
        for(int  i = 0; i < players.size(); i++){
            if(players[i].getIdentityInfo("playerName") == playerName){
                players[i].deletePlayer();
                players.erase(players.begin() + i);
                return;
            }
        }
        cout << "Player " << playerName << " does not exist!" << endl;
    }else{
        cout << playerName << " lives to see another day." << endl;
    }
}

void Party::printMoney(){
    cout << currencyNamesParty[0] << ": " << currency.copper << endl;
    cout << currencyNamesParty[1] << ": " << currency.silver << endl;
    cout << currencyNamesParty[2] << ": " << currency.electrum << endl;
    cout << currencyNamesParty[3] << ": " << currency.gold << endl;
    cout << currencyNamesParty[4] << ": " << currency.platinum << endl;
}

void Party::printAllItems(){
    partyItems.printTree();
}

void Party::printPlayers(){
    for(int i = 0; i < players.size(); i++){
        players[i].printCharacter();
    }
}

int Party::getPartySize(){
    return players.size();
}

int Party::getPlayerStats(string statType, int index){
    return players[index].getStats(statType);
}