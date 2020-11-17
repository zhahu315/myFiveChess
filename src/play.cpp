//
// Created by 张弛 on 2020/9/20.
//
#include <iostream>
#include "../include/draw.h"
#include "../include/chessManual.h"
#include "play.h"
#include "ai.h"

using namespace std;


int initPlay(int isBlack, char arr[16][16], ChessManual& manual){
    return 0;
};

int playChess(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai){
    role = 1;
    char coordinate[3];

    cout << "enter the coordinate:";
    cin >> coordinate;

    int y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
    int x = (coordinate[2] != '\0') ? 15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标

    while (manual.checkIfBan(x, y, role)){
        cout << "the position is illegal, please enter other coordinate";
        cin >> coordinate;
        y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
        x = (coordinate[2] != '\0') ? 15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标
    }

    arr[x][y] = isBlack ? 11:21;
    manual.checkGameOver(p_isWin);
    DisplayBoard(arr);
    arr[x][y] = isBlack ? 10:20;

    ai.setLastStep(x, y);

    manual.record(x, y, role);

    isGameOver = manual.checkGameOver(p_isWin);

    if (isGameOver == 1){
        cout << "YOU white_win THE ROUND!!!" << endl;
        if (*p_isWin == 2){
            cout << "YOU white_win THE GAME!!!" << endl;
        }
    }


    computerRun(isGameOver, isBlack, role, p_isWin, arr, manual, ai);

    return 0;
}

int computerRun(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai) {
    role = 2;
    int x, y;



    manual.checkIfBan(x, y, role);
    manual.checkGameOver(p_isWin);

    arr[x][y] = isBlack ? 21:11;

    DisplayBoard(arr);
    isGameOver = manual.checkGameOver(p_isWin);

    if (isGameOver == 1) {
        cout << "YOU LOSE THE ROUND!!!" << endl;
        if (*p_isWin == -2){
            cout << "YOU LOSE THE GAME!!!" << endl;
        }
    }

    arr[x][y] = isBlack ? 20:10;

    playChess(isGameOver, isBlack, role, p_isWin, arr, manual, ai);
    return 0;
}

