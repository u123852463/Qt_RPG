#include "NovicePlayer.h"
#include "OrcPlayer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream file;
	file.open("output.txt", ios::trunc);

	OrcPlayer orc1;
	orc1.printMembers(file);
	orc1.setExp(9487);
	orc1.printMembers(file);
	file << "----------------------" << endl;

	OrcPlayer orc2(10);
	orc2.printMembers(file);
	orc2.setHP(10000);
	orc2.setHP(-1);
	orc2.setMP(10000);
	orc2.setMP(-1);
	orc2.printMembers(file);
	file << "----------------------" << endl;

	OrcPlayer orc3(20, "Ray");
	orc3.printMembers(file);
	orc3.setHP(75);
	orc3.setMP(60);
	orc3.setMoney(87);
	orc3.printMembers(file);
	file << "----------------------" << endl;

	OrcPlayer orc4(orc3);
	orc4.printMembers(file);
	orc4.setName("Bob is God");
	orc4.printMembers(file);

	return 0;
}