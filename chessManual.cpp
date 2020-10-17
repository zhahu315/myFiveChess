//
// Created by 张弛 on 2020/9/20.
//

#include "chessManual.h"


int checkGameOver(ChessManual manual){
    int (*arr)[16] = new int[16][16];

    **arr = manual.getManual();


    return 0;
}

ChessManual::ChessManual() {
    manual[16][16] = {0};
}

void ChessManual::record(int x, int y) {
    manual[x][y] = 1;
}

void ChessManual::count() {
    step += 1;
}

int ChessManual::getManual() {
    return **manual;
}