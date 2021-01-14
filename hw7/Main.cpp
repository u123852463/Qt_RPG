#include "NovicePlayer.h"
#include "OrcPlayer.h"
#include "KnightPlayer.h"
#include "MagicianPlayer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream file;
	file.open("output.txt", ios::trunc);

	MagicianPlayer p1(10, "Cold");
	file << "Initial: \n";
	p1.printMembers(file);

	p1.pray();
	file << "\nPrayed\n";
	p1.printMembers(file);

	p1.setMP(p1.getMaxMP());
	file << "\nSet MP to full\n";
	p1.printMembers(file);

	p1.pray();
	file << "\nPrayed\n";
	p1.printMembers(file);

	p1.setHP(1);
	p1.setMP(1);
	file << "\nSet HP,MP to 1\n";
	p1.printMembers(file);

	p1.pray();
	file << "\nPrayed\n";
	p1.printMembers(file);

	return 0;
}