//
// Created by 张弛 on 2020/9/20.
//

#include "chessManual.h"

bool ChessManual::checkIfHasChess(int x, int y) {
    if (iManual[x][y] != 0) {
        return true;
    }
    else return false;
}

bool ChessManual::checkIfBan(int x, int y, int role) {
    int count =0;
    int temp[21][21] ={0};
    for (int i=0;i<15;i++){
        for (int j=0;j<15;j++){
            temp[i+3][j+3] = iManual[i][j];
        }
    }
    if ((temp[x][y+1]==role && temp[x][y+2]==role) || (temp[x][y+2]==role && temp[x][y+3]==role) || (temp[x][y+1]==role && temp[x][y+3]==role)) count++;
    if ((temp[x][y-1]==role && temp[x][y-2]==role) || (temp[x][y-2]==role && temp[x][y-3]==role) || (temp[x][y-1]==role && temp[x][y-3]==role)) count++;

    if ((temp[x+1][y]==role && temp[x+2][y]==role) || (temp[x+2][y]==role && temp[x+3][y]==role) || (temp[x+1][y]==role && temp[x+3][y]==role)) count++;
    if ((temp[x-1][y]==role && temp[x-2][y]==role) || (temp[x-2][y]==role && temp[x-3][y]==role) || (temp[x-1][y]==role && temp[x-3][y]==role)) count++;

    if ((temp[x+1][y-1]==role && temp[x+2][y-2]==role) || (temp[x+2][y-2]==role && temp[x+3][y-3]==role) || (temp[x+1][y-1]==role && temp[x+3][y-3]==role)) count++;
    if ((temp[x-1][y-1]==role && temp[x-2][y-2]==role) || (temp[x-2][y-2]==role && temp[x-3][y-3]==role) || (temp[x-1][y-1]==role && temp[x-3][y-3]==role)) count++;

    if ((temp[x+1][y+1]==role && temp[x+2][y+2]==role) || (temp[x+2][y+2]==role && temp[x+3][y+3]==role) || (temp[x+1][y+1]==role && temp[x+3][y+3]==role)) count++;
    if ((temp[x-1][y+1]==role && temp[x-2][y+2]==role) || (temp[x-2][y+2]==role && temp[x-3][y+3]==role) || (temp[x-1][y+1]==role && temp[x-3][y+3]==role)) count++;

    if (count >=2) {
        return true;}
    else return false;
}

int ChessManual::checkGameOver(int role, int* pInt) {
    if (role ==1) {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if ((iManual[i][j] == 1 && iManual[i - 1][j - 1] == 1 && iManual[i - 2][j - 2] == 1 &&
                     iManual[i - 3][j - 3] == 1 && iManual[i - 4][j - 4] == 1) ||
                    (iManual[i][j] == 1 && iManual[i + 1][j - 1] == 1 && iManual[i + 2][j - 2] == 1 &&
                     iManual[i + 3][j - 3] == 1 && iManual[i + 4][j - 4] == 1) ||
                    (iManual[i][j] == 1 && iManual[i - 1][j + 1] == 1 && iManual[i - 2][j + 2] == 1 &&
                     iManual[i - 3][j + 3] == 1 && iManual[i - 4][j + 4] == 1) ||
                    (iManual[i][j] == 1 && iManual[i + 1][j + 1] == 1 && iManual[i + 2][j + 2] == 1 &&
                     iManual[i + 3][j + 3] == 1 && iManual[i + 4][j + 4] == 1) ||
                    (iManual[i][j] == 1 && iManual[i][j - 1] == 1 && iManual[i][j - 2] == 1 && iManual[i][j - 3] == 1 &&
                     iManual[i][j - 4] == 1) ||
                    (iManual[i][j] == 1 && iManual[i][j + 1] == 1 && iManual[i][j + 2] == 1 && iManual[i][j + 3] == 1 &&
                     iManual[i][j + 4] == 1) ||
                    (iManual[i][j] == 1 && iManual[i - 1][j] == 1 && iManual[i - 2][j] == 1 && iManual[i - 3][j] == 1 &&
                     iManual[i - 4][j] == 1) ||
                    (iManual[i][j] == 1 && iManual[i + 1][j] == 1 && iManual[i + 2][j] == 1 && iManual[i + 3][j] == 1 &&
                     iManual[i + 4][j] == 1)) {
                    playerScore += 1;
                    return 1;
                }
            }
        }
    }
//    else {
//        if ((iManual[i][j] == 2 && iManual[i - 1][j - 1] == 2 && iManual[i - 2][j - 2] == 2 &&
//             iManual[i - 3][j - 3] == 2 && iManual[i - 4][j - 4] == 2) ||
//            (iManual[i][j] == 2 && iManual[i + 1][j - 1] == 2 && iManual[i + 2][j - 2] == 2 &&
//             iManual[i + 3][j - 3] == 2 && iManual[i + 4][j - 4] == 2) ||
//            (iManual[i][j] == 2 && iManual[i - 1][j + 1] == 2 && iManual[i - 2][j + 2] == 2 &&
//             iManual[i - 3][j + 3] == 2 && iManual[i - 4][j + 4] == 2) ||
//            (iManual[i][j] == 2 && iManual[i + 1][j + 1] == 2 && iManual[i + 2][j + 2] == 2 &&
//             iManual[i + 3][j + 3] == 2 && iManual[i + 4][j + 4] == 2) ||
//            (iManual[i][j] == 2 && iManual[i][j - 1] == 2 && iManual[i][j - 2] == 2 &&
//             iManual[i][j - 3] == 2 && iManual[i][j - 4] == 2) ||
//            (iManual[i][j] == 2 && iManual[i][j + 1] == 2 && iManual[i][j + 2] == 2 &&
//             iManual[i][j + 3] == 2 && iManual[i][j + 4] == 2) ||
//            (iManual[i][j] == 2 && iManual[i - 1][j] == 2 && iManual[i - 2][j] == 2 &&
//             iManual[i - 3][j] == 2 && iManual[i - 4][j] == 2) ||
//            (iManual[i][j] == 2 && iManual[i + 1][j] == 2 && iManual[i + 2][j] == 2 &&
//             iManual[i + 3][j] == 2 && iManual[i + 4][j] == 2)) {
//            pInt += 1;
//            return 1;
//            }
//        else return 0;
//    }
    else if (*pInt > 800000)
    {
        computerScore +=1;
        return 1;
    }
}


void ChessManual::record(int x, int y, int role) {
    iManual[x][y] = role;
}


int ChessManual::getManualValue(int x, int y) {
    return iManual[x][y];
}

ChessManual::ChessManual() {
        lastStepY = 0;
        lastStepX = 0;
        playerScore = 0;
        computerScore = 0;
}

void ChessManual::setLastStep(int x, int y) {
    lastStepX = x;
    lastStepY = y;
}

int ChessManual::getComputerScore() const {
    return computerScore;
}

int ChessManual::getPlayerScore() const {
    return playerScore;
}

void ChessManual::initManual() {
    for (auto & i : iManual){
        for (int & j : i){
            j = 0;
        }
    }

}
