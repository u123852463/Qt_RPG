#ifndef NOVICE_H
#define NOVICE_H
#include <string>
#include <iostream>
using namespace std;

class NovicePlayer{
public:
	NovicePlayer(); // default constructor
	NovicePlayer(int); // normal constructor
	NovicePlayer(int, string); // normal constructor
	NovicePlayer(const NovicePlayer&); // copy constructor

	//filter unexpected value and
	//set protected data and hp based on the level
	NovicePlayer& setLevel(int);
	NovicePlayer& setName(string);
	NovicePlayer& setHP(int);
	NovicePlayer& setMP(int);
	NovicePlayer& setExp(int);
	NovicePlayer& setMoney(int);

	string getName() const { return name; }
	int getLevel()   const { return level; }
	int getAttack()  const { return attack; }
	int getDefense() const { return defense; }
	int getMaxHP()   const { return max_hp; }
	int getMaxMP()   const { return max_mp; }
	int getLvupExp() const { return lvup_exp; }
	int getHP()      const { return hp; }
	int getMP()      const { return mp; }
	int getExp()     const { return exp; }
	int getMoney()   const{ return money; }

	void printMembers(ostream&) const;

protected:
	int level;  // The level of the player, >=1
	int attack; // Attack of the player
	int defense;// Defense of the player
	int max_hp; // Max HP of the player
	int max_mp; // Max MP of the player
	int lvup_exp; //Experience needed for leveling-up

private:
	int hp;  // Current HP of the player, range: [0,max_hp], initialized in setLevel()
	string name; // Name of the player
	int mp;  // Current MP of the player, range: [0,max_mp]
	int exp; // Cumulative experience of the player, >=0
	         // It will not reset to zero after leveling-up
	int money;// Current amount of money that player carries, >=0
};

#endif // NOVICE_H