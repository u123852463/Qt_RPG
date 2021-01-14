#include "NovicePlayer.h"
#include "OrcPlayer.h"
#include "KnightPlayer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream file;
	file.open("output.txt", ios::trunc);

	KnightPlayer player1;
	player1.printMembers(file);
	player1.setExp(9487);
	player1.printMembers(file);
	file << "----------------------" << endl;

	KnightPlayer player2(10);
	player2.printMembers(file);
	player2.setHP(10000);
	player2.setHP(-1);
	player2.setMP(10000);
	player2.setMP(-1);
	player2.printMembers(file);
	file << "----------------------" << endl;

	KnightPlayer player3(20, "Ray");
	player3.printMembers(file);
	player3.setHP(75);
	player3.setMP(60);
	player3.setMoney(87);
	player3.printMembers(file);
	file << "----------------------" << endl;

	KnightPlayer player4(player3);
	player4.printMembers(file);
	player4.setName("Bob is God");
	player4.printMembers(file);
	file << "----------------------" << endl;

	KnightPlayer player5(30, "Cold");
	player5.printMembers(file);
	player5.setHP(100);
	player5.setMP(200);
	player5.printMembers(file);
	player5.heal();
	player5.printMembers(file);

	return 0;
}