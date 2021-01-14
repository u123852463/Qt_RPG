#include "MagicianPlayer.h"

MagicianPlayer::MagicianPlayer() {
	setLevel(1); //set hp as well
	setName("anoymous");
	setMP(0);
	setExp(0);
	setMoney(0);
}

MagicianPlayer::MagicianPlayer(int lv) {
	setLevel(lv); //set hp as well
	setName("anoymous");
	setMP(0);
	setExp(0);
	setMoney(0);
}

MagicianPlayer::MagicianPlayer(int lv, string inName) {
	setLevel(lv); //set hp as well
	setName(inName);
	setMP(0);
	setExp(0);
	setMoney(0);
}

MagicianPlayer::MagicianPlayer(const MagicianPlayer& in) {
	setLevel(in.level);
	setName(in.getName());
	setHP(in.getHP()); //since hp may not be full, this line is required
	setMP(in.getMP());
	setExp(in.getExp());
	setMoney(in.getMoney());
}

MagicianPlayer& MagicianPlayer::setLevel(int lv) {
	if (lv <= 0) {
		cerr << "Error: MagicianPlayer::setLevel\n";
		cerr << "  The level must be larger than 0\n";
		cerr << "  But you input " << lv << ".\n";
		cerr << "  Automatically set the level to default: 1\n\n";
		lv = 1;
	}
	level = lv;
	max_hp = 120 + 15 * lv;
	max_mp = 100 + 15 * lv;
	attack = 30 + 8 * lv;
	defense = 20 + 7 * lv;
	lvup_exp = (int)ceil(pow(10, log2(lv + 1)));

	setHP(max_hp); //heal the player to full HP
	return *this;
}

MagicianPlayer& MagicianPlayer::pray() {
	int hp = getHP();
	int mp = getMP();
	int maxMP = getMaxMP();
	int lv = getLevel();

	if (hp > lv * 5) {
		setHP(hp - lv * 5);
		if (mp + lv * 10 >= maxMP)
			setMP(maxMP);
		else
			setMP(mp + lv * 10);
	}
	else {
		cout << "Not enough HP to pray\n";
		cout << "Have: " << hp << "   Required: " << lv * 5 << "\n";
	}
	return *this;
}