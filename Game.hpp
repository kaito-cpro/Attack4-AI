#ifndef GAME_HPP  //インクルードガード
#define GAME_HPP
#include "define.hpp"

class Game {
private:
   int valid_player[2];  //PLAYER_NUM個の登録playerのうちどの2つを対戦させるか
   int grid[HEIGHT+2][WIDTH+2];
   int winner;
public:
   Game();
   void disp_board();
   void disp_rule();
   void decide_player();
   void change_player();
   void disp_result();
   bool is_end();
   virtual int select();
   void play();
   int get_winner();
};

#endif
