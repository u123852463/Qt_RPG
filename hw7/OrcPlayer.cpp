#include "OrcPlayer.h"

OrcPlayer::OrcPlayer(){
	setLevel(1); //set hp as well
	setName("anoymous");
	setMP(0);
	setExp(0);
	setMoney(0);
}

OrcPlayer::OrcPlayer(int lv){
	setLevel(lv); //set hp as well
	setName("anoymous");
	setMP(0);
	setExp(0);
	setMoney(0);
}

OrcPlayer::OrcPlayer(int lv, string inName){
	setLevel(lv); //set hp as well
	setName(inName);
	setMP(0);
	setExp(0);
	setMoney(0);
}

OrcPlayer::OrcPlayer(const OrcPlayer& inOrc){
	setLevel(inOrc.level);
	setName(inOrc.getName());
	setHP(inOrc.getHP()); //since hp may not be full, this line is required
	setMP(inOrc.getMP());
	setExp(inOrc.getExp());
	setMoney(inOrc.getMoney());
}

OrcPlayer& OrcPlayer::setLevel(int lv) {
	if (lv <= 0) {
		cerr << "Error: OrcPlayer::setLevel\n";
		cerr << "  The level must be larger than 0\n";
		cerr << "  But you input " << lv << ".\n";
		cerr << "  Automatically set the level to default: 1\n\n";
		lv = 1;
	}
	level = lv;
	max_hp = 200 + 20 * lv;
	max_mp = 50 + 5 * lv;
	attack = 50 + 12 * lv;
	defense = 30 + 10 * lv;
	lvup_exp = (int)ceil(pow(10, log2(lv + 1)));

	setHP(max_hp); //heal the player to full HP
	return *this;
}