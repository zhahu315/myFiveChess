#include <iostream>
#include "../include/draw.h"
#include "../include/play.h"

using namespace std;
//全局变量
char board[16][16];
int isGameOver = 0;
int role = 0;

int main(){
	cout << "=========五子棋游戏========== \n "
         "=====请选择先手还是后手===== \n "
         "输入'0'并回车执白棋，输入'1'并回车执黑棋>>> \n";
	ChessManual manual;
	Ai ai;
	int isBlack;
	cin >> isBlack;
    ClearBoardArray(board);
    initPlay(isBlack, board, manual, ai);
    return 0;
}
