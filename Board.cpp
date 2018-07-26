#include "../hdr/common.h"
#include "../hdr/Board.h"

Board::Board(){
   memset(board, 0, sizeof(board));
};

void Board::show(){
   printf("      ");
   for (int x = 1; x <= WIDTH; ++x) printf("%d   ",x);
   puts("");
   for (int y = 1; y <= HEIGHT; ++y){
      printf("    |");
      for (int x = 1; x <= WIDTH; ++x){
         printf(" %c |", convert(board[x][y]));
      }
      puts("");
   }
   puts("");
};

char Board::convert(int n){
   switch (n){
      case 0:  return ' ';
      case 1:  return 'o';
      case -1: return 'x';
   }
   return ' ';
};

bool Board::is_4(){
   for (int x = 1; x <= WIDTH; ++x){
      for (int y = HEIGHT; y >= 4; --y){
         if (board[x][y] && board[x][y]==board[x][y-1] && board[x][y-1]==board[x][y-2] && board[x][y-2]==board[x][y-3])
            return true;
         if (board[x][y] && board[x][y]==board[x+1][y-1] && board[x+1][y-1]==board[x+2][y-2] && board[x+2][y-2]==board[x+3][y-3])
            return true;
      }
   }
   for (int y = HEIGHT; y >= 1; --y){
      for (int x = WIDTH; x >= 4; --x){
         if (board[x][y] && board[x][y]==board[x-1][y] && board[x-1][y]==board[x-2][y] && board[x-2][y]==board[x-3][y])
            return true;
         if (board[x][y] && board[x][y]==board[x-1][y-1] && board[x-1][y-1]==board[x-2][y-2] && board[x-2][y-2]==board[x-3][y-3])
            return true;
      }
   }
   return false;
};

bool Board::is_full(){
   for (int x = 1; x <= WIDTH; ++x){
      for (int y = 1; y <= HEIGHT; ++y){
         if (board[x][y]==0) return false;
      }
   }
   return true;
};

bool Board::is_end(){
   return (Board::is_full() || Board::is_4());
};

bool Board::can_select(int x){
   return Board::is_overheight(x)?OK:NG;
};

bool Board::is_overheight(int x){
   return board[x][1]?NG:OK;
};

void Board::put(int x, int F_or_L){
   int y = HEIGHT;
   while (1){
      if (board[x][y]==0){
         board[x][y] = (F_or_L==FORMER)?1:-1;
         break;
      }
      else --y;
   }
};

void Board::remove(int x){
   int y = 1;
   while (1){
      if (board[x][y]!=0){
         board[x][y] = 0;
         break;
      }
      else ++y;
   }
};
