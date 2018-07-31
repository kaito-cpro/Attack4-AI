#include <iostream>
#include "Game.h"

Game::Game() {
  point = &player0;
}

void Game::show() {
  std::cout << point->get_color() << std::endl;
}
