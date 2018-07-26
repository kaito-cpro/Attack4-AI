#include "../hdr/common.h"
#include "../hdr/Game.h"

Game::Game(){
   F_or_L = FORMER;
};

void Game::play(){
   clock_t start = clock();  //rand()を初期化する用
   display.rule();
   decide_player();
   clock_t end = clock();
   for (int i = 0; i < end-start; ++i) GetRandom_i(1, 7);  //rand()の初期化
   point(valid_player[FORMER]);
   cout << "  ---GAME START---" << endl << endl;
   display.show(board);
   while (!board.is_end()){
      int x = pointer->select(board, F_or_L);
      board.put(x, F_or_L);
      display.show(board);
      change_player();
   }
   set_winner();
   show_result();
};

void Game::show_board(){
   display.show(board);
};

void Game::show_rule(){
   display.rule();
};

void Game::decide_player(){
   cout << "Please select players' type." << endl;
   cout << "   1: Human" << endl;
   cout << "   2: AI" << endl;
   cout << "   3: Random_AI" << endl;
   valid_player[FORMER] = valid_player[LATTER] = 0;
   bool flg = OK;
   do {
      cout << ">Player_A: ";
      int pA = Input();
      valid_player[FORMER] = pA;
      if (valid_player[FORMER]<=0 || valid_player[FORMER]>PLAYER_NUM){
         cout << "Error! Invalid player." << endl;
         flg = NG;
      }
      else flg = OK;
   } while (flg==NG);
   do {
      cout << ">Player_B: ";
      int pB = Input();
      valid_player[LATTER] = pB;
      if (valid_player[LATTER]<=0 || valid_player[LATTER]>PLAYER_NUM){
         cout << "Error! Invalid player." << endl;
         flg = NG;
      }
      else flg = OK;
   } while (flg==NG);
   cout << endl;
   point(valid_player[FORMER]);
};

void Game::change_player(){
   int type;  //次のターンのplayerタイプを取得
   if (F_or_L==FORMER){
      type = valid_player[LATTER];
      F_or_L = LATTER;
   }
   else if (F_or_L==LATTER){
      type = valid_player[FORMER];
      F_or_L = FORMER;
   }
   point(type);
};

void Game::set_winner(){
   if (board.is_4()){
      change_player();
      record.set_winner(F_or_L, valid_player[F_or_L]);
   }
   else {
      record.set_winner(F_or_L, 0);  //ドローの場合
   }
};

void Game::show_result(){
   display.result(record);
};

void Game::point(int i){
	switch (i){
		case 1:
			pointer = &player1;
			break;
		case 2:
			pointer = &player2;
			break;
		case 3:
			pointer = &player3;
			break;
	}
};

P Game::get_winner(){
   return record.get_winner();
};
