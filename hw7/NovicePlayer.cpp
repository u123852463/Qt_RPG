#include "NovicePlayer.h"
#include <iostream>
#include <cmath>
using namespace std;

NovicePlayer::NovicePlayer() {
	(*this).setLevel(1)
		.setName("anonymous")
		.init();
}

NovicePlayer::NovicePlayer(int inLevel) {
	(*this).setLevel(inLevel)
		.setName("anonymous")
		.init();
}

NovicePlayer::NovicePlayer(int inLevel, string inName) {
	(*this).setLevel(inLevel)
		.setName(inName)
		.init();
}

NovicePlayer::NovicePlayer(const NovicePlayer& inNovice) {
	(*this).setLevel(inNovice.getLevel())
		.setName(inNovice.getName())
		.init(inNovice);
}

NovicePlayer& NovicePlayer::setName(string input) {
	this->name = input;
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
	hp = max_hp = 100 + 10 * lv;
	max_mp = 40 + 5 * lv;
	attack = 20 + 5 * lv;
	defense = 20 + 5 * lv;
	lvup_exp = (int)ceil(pow(10, log2(lv + 1)));

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
		hp = in;
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

NovicePlayer& NovicePlayer::init() {
	hp = max_hp;
	mp = 0;
	exp = 0;
	money = 0;
	return *this;
}

NovicePlayer& NovicePlayer::init(const NovicePlayer& inNovice) {
	hp = inNovice.hp;
	mp = inNovice.mp;
	exp = inNovice.exp;
	money = inNovice.money;
	return *this;
}

void NovicePlayer::printMembers(ostream& out) const {
	out << "Novice Player Member data:\n";
	out << "  Name    : " << name     << "\n";
	out << "  Level   : " << level    << "\n";
	out << "  Attack  : " << attack   << "\n";
	out << "  Defense : " << defense  << "\n";
	out << "  HP      : " << hp  << " / " << max_hp   << "\n";
	out << "  MP      : " << mp  << " / " << max_mp   << "\n";
	out << "  Exp     : " << exp << " / " << lvup_exp << "\n";
	out << "  Money   : " << money    << "\n";
}