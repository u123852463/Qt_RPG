#include "NovicePlayer.h"
#include <iostream>
using namespace std;

int main() {
	NovicePlayer player(10, "test");
	player.printMembers(cout);
	player.setExp(2880).printMembers(cout);
	player.setExp(2881).printMembers(cout);
	return 0;
}