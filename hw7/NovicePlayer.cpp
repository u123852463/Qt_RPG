#include "NovicePlayer.h"
#include <iostream>
#include <cmath>
using namespace std;

NovicePlayer::NovicePlayer() {
	setLevel(1); //initialize protected data & hp
	name = "anonymous";
	mp = 0;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(int inLevel) {
	setLevel(inLevel); //initialize protected data & hp
	name = "anonymous";
	mp = 0;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(int inLevel, string inName) {
	setLevel(inLevel); //initialize protected data & hp
	name = inName;
	mp = 0;
	exp = 0;
	money = 0;
}

NovicePlayer::NovicePlayer(const NovicePlayer& inNovice) {
	setLevel(inNovice.level); //initialize protected data & hp
	name = inNovice.name;
	mp = inNovice.mp;
	exp = inNovice.exp;
	money = inNovice.money;
}

NovicePlayer& NovicePlayer::setName(string input) {
	name = input;
	return *this;
}

NovicePlayer& NovicePlayer::setLevel(int lv) {
	if (lv <= 0){
		cerr << "Error: NovicePlayer::setLevel\n";
		cerr << "  The level must be larger than 0\n";
		cerr << "  But you input " << lv << ".\n";
		cerr << "  Automatically set the level to default: 1\n\n";
		lv = 1;
	}
	level = lv;
	max_hp = 100 + 10 * lv;
	max_mp = 40 + 5 * lv;
	attack = 20 + 5 * lv;
	defense = 20 + 5 * lv;
	lvup_exp = (int)ceil(pow(10, log2(lv + 1)));

	hp = max_hp;//heal the player to full HP
	return *this;
}

NovicePlayer& NovicePlayer::setHP(int in) {
	if (in >= 0 && in <= max_hp) {
		hp = in;
	}
	else {
		cerr << "Error: NovicePlayer::setHP\n";
		cerr << "  HP should be in the range of\n";
		cerr << "  [0,max_hp] = [0," << max_hp << "].\n";
		cerr << "  But you input " << in << ".\n\n";
	}
	return *this;
}

NovicePlayer& NovicePlayer::setMP(int in) {
	if (in >= 0 && in <= max_mp) {
		mp = in;
	}
	else {
		cerr << "Error: NovicePlayer::setMP\n";
		cerr << "  HP should be in the range of\n";
		cerr << "  [0,max_mp] = [0," << max_mp << "].\n";
		cerr << "  But you input " << in << ".\n\n";
	}
	return *this;
}

NovicePlayer& NovicePlayer::setExp(int in) {
	if (in < 0) {
		cerr << "Error: NovicePlayer::setExp\n";
		cerr << "  Exp should be larger than or equal to 0.\n";
		cerr << "  But you input " << in << ".\n\n";
	}
	else {
		exp = in;
		if (exp >= lvup_exp) {
			this->setLevel((int)round(pow(2, log10(in))));
		}
	}
	return *this;
}

NovicePlayer& NovicePlayer::setMoney(int in) {
	if (in < 0) {
		cerr << "Error: NovicePlayer::setMoney\n";
		cerr << "  Money should be larger than or equal to 0.\n";
		cerr << "  But you input " << in << ".\n\n";
	}
	else {
		money = in;
	}
	return *this;
}

void NovicePlayer::printMembers(ostream& out) const {
	out << "Novice Player Data:\n";
	out << "  Name    : " << name     << "\n";
	out << "  Level   : " << level    << "\n";
	out << "  Attack  : " << attack   << "\n";
	out << "  Defense : " << defense  << "\n";
	out << "  HP      : " << hp  << " / " << max_hp   << "\n";
	out << "  MP      : " << mp  << " / " << max_mp   << "\n";
	out << "  Exp     : " << exp << " / " << lvup_exp << "\n";
	out << "  Money   : " << money    << "\n";
}