#include "NovicePlayer.h"
#include <iostream>
using namespace std;

NovicePlayer::NovicePlayer() {
	(*this).setLevel(1)
		.setName("anonymous");
}

NovicePlayer::NovicePlayer(int inLevel) {
	(*this).setLevel(inLevel)
		.setName("anonymous");
}

NovicePlayer& NovicePlayer::setLevel(int input) {
	if (input <= 0){
		cerr << "Error: NovicePlayer::setLevel\n";
		cerr << "The level must be larger than 0\n";
		cerr << "You input " << input << ".\n\n";
		return *this;
	}
	//else
	this->level = input;
	//todo: set all member data
	return *this;
}

NovicePlayer& NovicePlayer::setName(string input) {
	this->name = input;
	
	return *this;
}