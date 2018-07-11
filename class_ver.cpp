#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;
const int OK = 1;  //気にしなくて大丈夫なとき
const int PLAYER_NUM = 3;  //登録しているplayerの数
                           //変更 -> Game::decide_player(), Game::play()
const int NG = 0;  //立ち止まって気にする必要あるとき

//----------------------------------------------------------------------------

int main(){
   Human player0;
   AI player1;
   Random_AI player2;
   int valid_player[2];  //PLAYER_NUM個の登録playerのうちどの2つを対戦させるか

   Game game;  //クラスGame型オブジェクト
   game.play();
}


class Learning {
private:
   static int won_count[PLAYER_NUM];  //各playerの勝数
public:
};

class Game {
private:
public:
   Game(){  //コンストラクタ
      set_grid();
      disp_rule();
      decide_player();
      play();
      disp_result();
   };
   void set_grid(){
      initialize_grid();
   };
   void disp_board();
   void disp_rule();
   void decide_player(){
      int p0, p1;
      cout << "Please select players' type." << endl;
      cout << " ~ Human: '0', AI: '1', Random_AI: '2' ~" << endl;
      cout << "Player_A: " << endl;  cin >> p0;  valid_player[0] = p0;
      cout << "Player_B: " << endl;  cin >> p1;  valid_player[1] = p1;
   };
   void change_player();
   void put_stone(int x);
   void disp_result();
   bool is_end();
   virtual int select();
   void play(){
      Game* cur_player;  //Playerオブジェクトを指向するポインタ
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
   };
};

class Board : public Game {
private:
   static int grid[HEIGHT+2][WIDTH+2];
public:
   void initialize_grid(){
      for (int y = 0; y <= HEIGHT+1; ++y){
         for (int x = 0; x <= WIDTH+1; ++x){
            grid[x][y] = 0;
         }
      }
   };
   bool is_4();
   bool is_3();
   bool is_overheight();
   bool is_fulled();
   bool is_end();
   bool can_select();
};

class Player : public Game {
private:
   int color;
   int board[HEIGHT+2][WIDTH+2];  //各playerにboardを持たせる
   int stone_num;
public:

};

class Human : public Player {
private:
public:
   int select();
};

class AI : public Player {
   //盤面評価値etc....
public:
   int select();
};

class Random_AI : public Player {
public:
   int select();
};
