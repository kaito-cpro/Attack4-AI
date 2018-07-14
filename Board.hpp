#ifndef BOARD_HPP  //インクルードガード
#define BOARD_HPP
#include "define.hpp"

class Board {
private:
   int grid[HEIGHT+2][WIDTH+2];
public:
   void set_grid();
   bool is_4();
   bool is_3();
   bool is_overheight();
   bool is_fulled();
   bool can_select();
};

#endif
