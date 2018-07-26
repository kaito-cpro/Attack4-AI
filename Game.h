#ifndef _INC_GAME_
#define _INC_GAME_
#include "common.h"
#include "Board.h"
#include "player/Human.h"
#include "player/AI.h"
#include "player/Random_AI.h"
#include "Display.h"
#include "Record.h"

class Game {
private:
   Human player1;
   AI player2;
   Random_AI player3;
   Player* pointer;
   Board board;
   Display display;
   Record record;
   int valid_player[2];  //有効playerタイプを管理
   int F_or_L;  //現在のplayerの先攻か後攻かを管理(put_stone()などで利用)
public:
   Game();
   void play();
   void show_board();
   void show_rule();
   void decide_player();
   void change_player();
   void set_winner();
   void show_result();
   void point(int i);
   P get_winner();
};

#endif
