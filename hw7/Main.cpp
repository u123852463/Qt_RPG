#include "NovicePlayer.h"
#include <iostream>
using namespace std;

int main() {
	NovicePlayer player1(65);
	cout << player1.getLevel() << endl;
	cout << player1.getName() << endl;
	NovicePlayer player2(-57);
	cout << player2.getLevel() << endl;
	cout << player2.getName() << endl;
	NovicePlayer player3(0);
	cout << player3.getLevel() << endl;
	cout << player3.getName() << endl;
	return 0;
}