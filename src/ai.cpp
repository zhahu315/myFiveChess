//
// Created by Zhang Chi on 2020/11/18.
//
#include "ai.h"
#include <cstring>
#include <string>

enum {none, white_win, black_win, white_4, black_4, white_n4, black_n4, white_3, black_3, white_n3, black_n3, white_2,
    black_2, white_n2, black_n2, white_1, black_1};

using namespace std;

Ai::Ai(){
    memset(chessMode,0,sizeof (chessMode));//初始化棋型
    //
    chessMode[2][2][2][2][2][2]=white_win;
    chessMode[2][2][2][2][2][0]=white_win;
    chessMode[0][2][2][2][2][2]=white_win;
    chessMode[2][2][2][2][2][1]=white_win;
    chessMode[1][2][2][2][2][2]=white_win;
    chessMode[3][2][2][2][2][2]=white_win;
    chessMode[2][2][2][2][2][3]=white_win;
    //黑连5,ai输
    chessMode[1][1][1][1][1][1]=black_win;
    chessMode[1][1][1][1][1][0]=black_win;
    chessMode[0][1][1][1][1][1]=black_win;
    chessMode[1][1][1][1][1][2]=black_win;
    chessMode[2][1][1][1][1][1]=black_win;
    chessMode[3][1][1][1][1][1]=black_win;
    chessMode[1][1][1][1][1][3]=black_win;
    //白活4
    chessMode[0][2][2][2][2][0]=white_4;
    //黑活4
    chessMode[0][1][1][1][1][0]=black_4;
    //白活3
    chessMode[0][2][2][2][0][0]=white_3;
    chessMode[0][0][2][2][2][0]=white_3;
    chessMode[0][2][0][2][2][0]=white_3;
    chessMode[0][2][2][0][2][0]=white_3;
    //黑活3
    chessMode[0][1][1][1][0][0]=black_3;
    chessMode[0][0][1][1][1][0]=black_3;
    chessMode[0][1][0][1][1][0]=black_3;
    chessMode[0][1][1][0][1][0]=black_3;
    //白活2
    chessMode[0][2][2][0][0][0]=white_2;
    chessMode[0][2][0][2][0][0]=white_2;
    chessMode[0][2][0][0][2][0]=white_2;
    chessMode[0][0][2][2][0][0]=white_2;
    chessMode[0][0][2][0][2][0]=white_2;
    chessMode[0][0][0][2][2][0]=white_2;
    //黑活2
    chessMode[0][1][1][0][0][0]=black_2;
    chessMode[0][1][0][1][0][0]=black_2;
    chessMode[0][1][0][0][1][0]=black_2;
    chessMode[0][0][1][1][0][0]=black_2;
    chessMode[0][0][1][0][1][0]=black_2;
    chessMode[0][0][0][1][1][0]=black_2;
    //白活1
    chessMode[0][2][0][0][0][0]=white_1;
    chessMode[0][0][2][0][0][0]=white_1;
    chessMode[0][0][0][2][0][0]=white_1;
    chessMode[0][0][0][0][2][0]=white_1;
    //黑活1
    chessMode[0][1][0][0][0][0]=black_1;
    chessMode[0][0][1][0][0][0]=black_1;
    chessMode[0][0][0][1][0][0]=black_1;
    chessMode[0][0][0][0][1][0]=black_1;

}

int Ai::situationScore(int role, ChessManual &manual) {

    string player[4];
    string computer[4];
    int i, j;
    //读取横向特征
    for (i = max(0, lastStepX - 4); i < min(15, lastStepX + 5); i++){
        if (i != lastStepX){
            player[0].push_back(manual.getManualValue(i, lastStepY));
        }
    }
    return 0;
}

void Ai::setLastStep(int x, int y) {
    lastStepX = x;
    lastStepY = y;
}

void Ai::setNextStep(int x, int y) {

}

int Ai::getNextStepX() const {
    return nextStepX;
}

int Ai::getNextStepY() const{
    return nextStepY;
}
