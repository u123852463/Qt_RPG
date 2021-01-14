#ifndef MAGICIAN_PLAYER
#define MAGICIAN_PLAYER

#include "NovicePlayer.h"

class MagicianPlayer : public NovicePlayer {
public:
	MagicianPlayer();
	MagicianPlayer(int);
	MagicianPlayer(int, string);
	MagicianPlayer(const MagicianPlayer&);
	MagicianPlayer& setLevel(int);
	MagicianPlayer& pray(); // increasing MP (level*10) points by decreasing HP (level*5) points
};

#endif //MAGICIAN_PALYER