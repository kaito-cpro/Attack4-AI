#ifndef _INC_HUMAN_
#define _INC_HUMAN_
#include <iostream>
#include "Player.h"

class Human : public Player
{
  public:
    int select();
};
#endif
