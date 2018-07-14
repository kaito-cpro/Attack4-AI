#include "define.hpp"
#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "extern.hpp"

Game::Game(){  //コンストラクタ
};
void Game::disp_rule(){
};
void Game::decide_player(){
   int p0, p1;
   cout << "Please select players' type." << endl;
   cout << " ~ Human: '0', AI: '1', Random_AI: '2' ~" << endl;
   cout << "Player_A: " << endl;  cin >> p0;  valid_player[0] = p0;
   cout << "Player_B: " << endl;  cin >> p1;  valid_player[1] = p1;
};
void change_player(){
};
void Game::disp_result(){
};
bool Game::is_end(){
   return true;
};
void Game::play(){
   Board::set_grid();
   disp_rule();
   decide_player();
   Player* cur_player;  //Playerオブジェクトを指向するポインタ
   switch (valid_player[0]){  //先攻を指向
      case 0:
         cur_player = &player0;
         break;
      case 1:
         cur_player = &player1;
         break;
      case 2:
         cur_player = &player2;
         break;
   }
   while (is_end()==OK){
      int x = cur_player->select();
      cur_player->put_stone(x);
      change_player();
   }
   disp_result();
};
int Game::get_winner(){
   return winner;
};
