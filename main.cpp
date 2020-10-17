#include <iostream>
#include "draw.h"
#include "play.h"
#include "chessManual.h"

using namespace std;
//全局变量
char board[16][16];
int gameOver = 0;

int main(){
	cout << "Welcome the five chess!\n "
         "please choose which white or black chess\n "
         "enter '0' for white and '1' for black\n";
	ChessManual manual;
	int isBlack;
	cin >> isBlack;
    ClearBoardArray(board);
    DisplayBoard(board);
    initPlay(isBlack, board);
    playChess(gameOver, board);
    return 0;
}



