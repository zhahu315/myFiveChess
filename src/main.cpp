#include <iostream>
#include "../include/draw.h"
#include "../include/play.h"

using namespace std;
//全局变量
char board[16][16];
int isWin = 0;
int isGameOver = 0;
int role = 0;

int main(){
	cout << "Welcome the five chess!\n "
         "please choose which white or black chess\n "
         "enter '0' for white and '1' for black\n";
	ChessManual manual;
	int* p_isWin = &isWin;
	Ai ai;
	int isBlack;
	cin >> isBlack;
    ClearBoardArray(board);
    DisplayBoard(board);
    initPlay(isBlack, board, manual);
    playChess(isGameOver, board, manual);
    return 0;
}



