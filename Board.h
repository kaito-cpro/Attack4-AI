#ifndef _INC_BOARD_
#define _INC_BOARD_
#include "common.h"

class Board {
private:
   int board[WIDTH+2][HEIGHT+2];
public:
   Board();
   void show();
   char convert(int n);
   bool is_4();
   bool is_full();
   bool is_end();
   bool can_select(int x);
   bool is_overheight(int x);
   void put(int x, int F_or_L);
   void remove(int x);
};

#endif
