#include "KnightPlayer.h"

KnightPlayer::KnightPlayer() {
	setLevel(1); //set hp as well
	setName("anoymous");
	setMP(0);
	setExp(0);
	setMoney(0);
}

KnightPlayer::KnightPlayer(int lv) {
	setLevel(lv); //set hp as well
	setName("anoymous");
	setMP(0);
	setExp(0);
	setMoney(0);
}

KnightPlayer::KnightPlayer(int lv, string inName) {
	setLevel(lv); //set hp as well
	setName(inName);
	setMP(0);
	setExp(0);
	setMoney(0);
}

KnightPlayer::KnightPlayer(const KnightPlayer& in) {
	setLevel(in.level);
	setName(in.getName());
	setHP(in.getHP()); //since hp may not be full, this line is required
	setMP(in.getMP());
	setExp(in.getExp());
	setMoney(in.getMoney());
}

KnightPlayer& KnightPlayer::setLevel(int lv) {
	if (lv <= 0) {
		cerr << "Error: OrcPlayer::setLevel\n";
		cerr << "  The level must be larger than 0\n";
		cerr << "  But you input " << lv << ".\n";
		cerr << "  Automatically set the level to default: 1\n\n";
		lv = 1;
	}
	level = lv;
	max_hp = 150 + 25 * lv;
	max_mp = 70 + 10 * lv;
	attack = 40 + 10 * lv;
	defense = 20 + 12 * lv;
	lvup_exp = (int)ceil(pow(10, log2(lv + 1)));

	setHP(max_hp); //heal the player to full HP
	return *this;
}

KnightPlayer& KnightPlayer::heal() {
	int lv = getLevel();
	int maxHP = getMaxHP();
	int hp = getHP();
	int mp = getMP();
	
	if (mp >= lv * 5) {
		setMP(mp - lv * 5);
		if (hp + lv * 10 < maxHP)
			setHP(hp + lv * 10);
		else
			setHP(maxHP);
	}
	else {
		cout << "You have not enough " << lv * 5<<" MP\n";
		cout << "to heal yourself.\n";
	}
	return *this;
}