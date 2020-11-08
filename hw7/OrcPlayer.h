#ifndef ORC_PLAYER
#define ORC_PLAYER

using namespace std;

#include "NovicePlayer.h"
class OrcPlayer : public NovicePlayer{
public:
	OrcPlayer();
	OrcPlayer(int);
	OrcPlayer(int, string);
	OrcPlayer(const OrcPlayer&);
	OrcPlayer& setLevel(int);
};

#endif //ORC_PLAYER
