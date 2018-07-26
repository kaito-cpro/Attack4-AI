#ifndef _INC_PLAYER_
#define _INC_PLAYER_
#include "common.h"
#include "Board.h"

class Player {
public:
   virtual int select(Board& board_g, int F_or_L) = 0;
};

#endif
