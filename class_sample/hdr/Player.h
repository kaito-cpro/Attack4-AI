#ifndef _INC_PLAYER_
#define _INC_PLAYER_
#include <iostream>

class Player {
  private:
    int color;
  public:
    Player();
    int get_color();
    int select();
};
#endif
