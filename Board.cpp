#include "define.hpp"
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "extern.hpp"

void Board::set_grid(){
   for (int y = 0; y <= HEIGHT+1; ++y){
      for (int x = 0; x <= WIDTH+1; ++x){
         grid[x][y] = 0;
      }
   }
};
bool Board::is_4(){
   return true;
};
bool Board::is_3(){
   return true;
};
bool Board::is_overheight(){
   return true;
};
bool Board::is_fulled(){
   return true;
};
bool Board::can_select(){
   return true;
};
