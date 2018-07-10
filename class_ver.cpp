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
const int NG = 0;  //立ち止まって気にする必要あるとき

class Game {
private:
   int grid[HEIGHT+2][WIDTH+2];
   int player;
public:
   static void set_grid();
   static void disp_rule();
   static void decide_first();  //先攻を決める
   static void disp_board();
   static void disp_result();
   static void change_player();
   bool is_4();
   bool is_3();
   bool is_overheight();
   static bool is_fulled();
   static bool is_finish();
   bool is_select();
   int select_num();
};

class Player : public Game {
private:
public:
   static void play();
};

class Human : public Player {
private:
public:
   static void play();
};

class AI : public Player {
private:
public:
   static void play();
};

class Random_Player : public Player {
private:
public:
   static void play();
};

int main(){
   Game::set_grid();
   Game::disp_rule();
   Game::decide_first();
   while (1) {
      Player::play();
      if (Game::is_finish()==OK) Game::change_player();
      else break;
   }
   Game::disp_result();
}
