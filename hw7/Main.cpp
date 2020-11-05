#include "NovicePlayer.h"
#include <iostream>
using namespace std;

int main() {
	NovicePlayer player(-1);
	cout << player.getLevel() << endl;
	cout << player.getName() << endl;
	return 0;
}