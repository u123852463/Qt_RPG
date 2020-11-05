#ifndef NOVICE_H
#define NOVICE_H
#include <string>
using namespace std;
class NovicePlayer{
public:
	NovicePlayer(); // default constructor
	NovicePlayer(int); // normal constructor
	NovicePlayer(int, string); // normal constructor
	NovicePlayer(const NovicePlayer&); // copy constructor

	string getName() const { return name; }
	int getLevel() const { return level; }
	int getAttack() const { return attack; }
	int getDefense() const { return defense; }
	int getMax_hp() const { return max_hp; }
	int getMax_mp() const { return max_mp; }
	int getLvup_exp() const { return lvup_exp; }

protected:
	NovicePlayer& setName(string);
	NovicePlayer& setLevel(int);
	NovicePlayer& setAttack(int);
	NovicePlayer& setDefense(int);
	NovicePlayer& setMax_hp(int);
	NovicePlayer& setMax_mp(int);
	NovicePlayer& setLvup_exp(int);

	int level;  // The level of the player, >=1
	int attack; // Attack of the player
	int defense;// Defense of the player
	int max_hp; // Max HP of the player
	int max_mp; // Max MP of the player
	int lvup_exp; //Experience needed for leveling-up

private:
	string name; // Name of the player
	int hp;  // Current HP of the player, range: [0,max_hp]
	int mp;  // Current MP of the player, range: [0,max_mp]
	int exp; // Cumulative experience of the player, >=0
	         // It will not reset to zero after leveling-up
	int money;// Current amount of money that player carries, >=0
};

#endif // NOVICE_H