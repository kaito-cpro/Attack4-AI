#include "../hdr/common.h"
#include "../hdr/Game.h"
#include "../hdr/Board.h"
#include "../hdr/Player.h"
#include "../hdr/player/Human.h"
#include "../hdr/player/AI.h"
#include "../hdr/player/Random_AI.h"
#include "../hdr/Display.h"
#include "../hdr/Record.h"
#include "../hdr/Test.h"

int main(){
   cout << " 1: Playing" << endl;
   cout << " 2: Development" << endl;
   cout << " 3: Learning" << endl;
   switch (Input()){
      case 1: {
         Game game;
         game.play();
         break;
      }
      case 2:
         Test test;
         test.test();
         break;
      case 3:
         break;
      default:
         cout << "Error! Invalid number." << endl;
   }
}
