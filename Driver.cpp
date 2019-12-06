#include "Player.hpp"
#include <iostream>

using namespace std;

Player test;

int main(){
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
    test.setSkills(i, i % 2, i % 4, 6);
  }
  test.setCurrency(10, 20, 30, 40, 50);
  test.printCharacter();
}
