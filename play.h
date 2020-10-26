//
// Created by 张弛 on 2020/9/20.
//

#ifndef MYFIVECHESS_PLAY_H
#define MYFIVECHESS_PLAY_H

#include "chessManual.h"

int playChess(int isBlack, char arr[16][16], ChessManual& manual);
int initPlay(int isBlack, char arr[16][16], ChessManual& manual);
int computerRun(int gameover, char arr[16][16], ChessManual& manual);

#endif //MYFIVECHESS_PLAY_H
