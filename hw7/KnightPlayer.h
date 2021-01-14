#ifndef KNIGHT_PLAYER
#define KNIGHT_PLAYER

#include "NovicePlayer.h"

class KnightPlayer : public NovicePlayer {
public:
	KnightPlayer();
	KnightPlayer(int);
	KnightPlayer(int, string);
	KnightPlayer(const KnightPlayer&);
	KnightPlayer& setLevel(int);
	KnightPlayer& heal();//increasing HP (level*10) points by decreasing MP (level*5) points

};

#endif //KNIGHT_PLAYER
