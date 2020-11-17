//
// Created by 张弛 on 2020/9/20.
//

#ifndef MYFIVECHESS_PLAY_H
#define MYFIVECHESS_PLAY_H

#include "chessManual.h"
#include "ai.h"
#include <vector>
#include <string>


int initPlay(int isBlack, char arr[16][16], ChessManual& manual);
int playChess(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai);
int computerRun(int isGameOver, int isBlack, int role, int *pInt, char arr[16][16], ChessManual& manual, Ai& ai);

#endif //MYFIVECHESS_PLAY_H
