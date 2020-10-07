#include <iostream>
#include "draw.h"
#include "play.h"
#include "chessManual.h"

using namespace std;

char arr[16][16];
int main(){
    int gameOver = 0;
	cout << "Welcome the five chess!\n "
         "please choose which white or black chess\n "
         "enter 1 for black and 2 for white [1 or 2]" << endl;
	int isBlack;
	cin >> isBlack;
    ClearBoardArray(arr);
    DisplayBoard(arr);
    initPlay(0, arr);
    playChess(gameOver, arr);
    return 0;
}



