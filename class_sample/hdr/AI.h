#ifndef _INC_AI_
#define _INC_AI_
#include <iostream>
#include "Player.h"

class AI : public Player
{
  public:
    int select();
};
#endif
