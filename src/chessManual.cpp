//
// Created by 张弛 on 2020/9/20.
//

#include "../include/chessManual.h"

bool ChessManual::checkIfBan(int x, int y, int role) {
    if(iManual[x][y] != 0) return true;
    return false;
}

int ChessManual::checkGameOver(int* p_isWin) {
    for (int i=0; i<15; i++) {
        for (int j=0; j<15; j++) {
            if ((iManual[i][j] == 1 && iManual[i - 1][j - 1] == 1 && iManual[i - 2][j - 2] == 1 &&
                 iManual[i - 3][j - 3] == 1 && iManual[i - 4][j - 4] == 1) ||        // 左上角
                (iManual[i][j] == 1 && iManual[i + 1][j - 1] == 1 && iManual[i + 2][j - 2] == 1 &&
                 iManual[i + 3][j - 3] == 1 && iManual[i + 4][j - 4] == 1) ||        // 右上角
                (iManual[i][j] == 1 && iManual[i - 1][j + 1] == 1 && iManual[i - 2][j + 2] == 1 &&
                 iManual[i - 3][j + 3] == 1 && iManual[i - 4][j + 4] == 1) ||        // 左下角
                (iManual[i][j] == 1 && iManual[i + 1][j + 1] == 1 && iManual[i + 2][j + 2] == 1 &&
                 iManual[i + 3][j + 3] == 1 && iManual[i + 4][j + 4] == 1) ||        // 右下角
                (iManual[i][j] == 1 && iManual[i][j - 1] == 1 && iManual[i][j - 2] == 1 && iManual[i][j - 3] == 1 &&
                 iManual[i][j - 4] == 1) ||                // 上
                (iManual[i][j] == 1 && iManual[i][j + 1] == 1 && iManual[i][j + 2] == 1 && iManual[i][j + 3] == 1 &&
                 iManual[i][j + 4] == 1) ||                // 下
                (iManual[i][j] == 1 && iManual[i - 1][j] == 1 && iManual[i - 2][j] == 1 && iManual[i - 3][j] == 1 &&
                 iManual[i - 4][j] == 1) ||                // 左
                (iManual[i][j] == 1 && iManual[i + 1][j] == 1 && iManual[i + 2][j] == 1 && iManual[i + 3][j] == 1 &&
                 iManual[i + 4][j] == 1)) {                // 右
                *p_isWin += 1;
                return 1;
            } else if ((iManual[i][j] == 2 && iManual[i - 1][j - 1] == 2 && iManual[i - 2][j - 2] == 2 &&
                        iManual[i - 3][j - 3] == 2 && iManual[i - 4][j - 4] == 2) ||        // 左上角
                       (iManual[i][j] == 2 && iManual[i + 1][j - 1] == 2 && iManual[i + 2][j - 2] == 2 &&
                        iManual[i + 3][j - 3] == 2 && iManual[i + 4][j - 4] == 2) ||        // 右上角
                       (iManual[i][j] == 2 && iManual[i - 1][j + 1] == 2 && iManual[i - 2][j + 2] == 2 &&
                        iManual[i - 3][j + 3] == 2 && iManual[i - 4][j + 4] == 2) ||        // 左下角
                       (iManual[i][j] == 2 && iManual[i + 1][j + 1] == 2 && iManual[i + 2][j + 2] == 2 &&
                        iManual[i + 3][j + 3] == 2 && iManual[i + 4][j + 4] == 2) ||        // 右下角
                       (iManual[i][j] == 2 && iManual[i][j - 1] == 2 && iManual[i][j - 2] == 2 &&
                        iManual[i][j - 3] == 2 && iManual[i][j - 4] == 2) ||                // 上
                       (iManual[i][j] == 2 && iManual[i][j + 1] == 2 && iManual[i][j + 2] == 2 &&
                        iManual[i][j + 3] == 2 && iManual[i][j + 4] == 2) ||                // 下
                       (iManual[i][j] == 2 && iManual[i - 1][j] == 2 && iManual[i - 2][j] == 2 &&
                        iManual[i - 3][j] == 2 && iManual[i - 4][j] == 2) ||                // 左
                       (iManual[i][j] == 2 && iManual[i + 1][j] == 2 && iManual[i + 2][j] == 2 &&
                        iManual[i + 3][j] == 2 && iManual[i + 4][j] == 2)) {                // 右
                *p_isWin -= 1;
                return 2;
            }
        }
    }
    if (computerScore == 2){
        *p_isWin = 2;
    } else if (playerScore == 2){
        *p_isWin = 1;
    }
    return 0;
}


ChessManual::ChessManual() {
    iManual[15][15] = {0};
}

void ChessManual::record(int x, int y, int role) {
    iManual[x][y] = role;
}


int ChessManual::getManualValue(int x, int y) {
    return iManual[x][y];
}