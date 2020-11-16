//
// Created by 张弛 on 2020/9/20.
//
#include <iostream>
#include "../include/draw.h"
#include "../include/chessManual.h"
#include "play.h"
#include <algorithm>
#include <string>

using namespace std;
int initPlay(int isBlack, char arr[16][16], ChessManual& manual){
    return 0;
};

Ai::Ai() {

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


int playChess(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai){
    role = 1;
    char coordinate[3];

    cout << "enter the coordinate:";
    cin >> coordinate;
//    for (int i=0;i<=3;i++)
//        cout << coordinate[i]<<endl;
    int y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
    int x = (coordinate[2] != '\0') ?
            15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 -(coordinate[1] - 48);//将后面输入的数字转为纵坐标
    //cout << x << endl <<y << endl;
    manual.checkIfBan(role);
    arr[x][y] = isBlack ? 11:21;
    manual.checkGameOver(p_isWin);
    DisplayBoard(arr);
    arr[x][y] = isBlack ? 10:20;

    ai.setLastStep(x, y);

    manual.record(x, y, role);

    isGameOver = manual.checkGameOver(p_isWin);

    if (isGameOver == 1){
        cout << "YOU WIN THE ROUND!!!" << endl;
        if (*p_isWin == 2){
            cout << "YOU WIN THE GAME!!!" << endl;
        }
    }
    else {
        cout << "YOU LOSE THE ROUND!!!" << endl;
        if (*p_isWin == -2){
            cout << "YOU LOSE THE GAME!!!" << endl;
        }
    }

    computerRun(isGameOver, isBlack, role, p_isWin, arr, manual, ai);

    return 0;
}

int computerRun(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai) {
    role = 2;
    int x, y;
    manual.checkIfBan(role);
    manual.checkGameOver(p_isWin);

    arr[x][y] = isBlack ? 21:11;

    DisplayBoard(arr);
    isGameOver = manual.checkGameOver(p_isWin);

    arr[x][y] = isBlack ? 20:10;
    if (isGameOver == 1){
        cout << "YOU WIN !!!" << endl;
    }
    return 0;
}

