#include "define.hpp"

#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"

#include "Game.cpp"
#include "Board.cpp"
#include "Player.cpp"

//クラスGame型オブジェクトの生成
Game game;
//クラスBoard型オブジェクトの生成
Board board;

//Playerクラスの派生クラス型オブジェクトの生成
Human player0;
AI player1;
Random_AI player2;


int main(){
   game.play();
   int winner = game.get_winner();
}
