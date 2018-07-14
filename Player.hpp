#ifndef PLAYER_HPP  //インクルードガード
#define PLAYER_HPP
#include "define.hpp"

class Player : public Game {
private:
   int color;
   int grid[HEIGHT+2][WIDTH+2];  //各playerにgridを持たせる
   int stone_num;
public:
   virtual int select();
   void put_stone(int x);
};

class Human : public Player {
private:
public:
   int select();
};

class AI : public Player {
   //盤面評価値etc....
private:
public:
   int select();
};

class Random_AI : public Player {
private:
public:
   int select();
};

#endif
