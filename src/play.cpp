//
// Created by 张弛 on 2020/9/20.
//
#include <iostream>
#include "../include/draw.h"
#include "../include/chessManual.h"
#include "play.h"
#include "ai.h"

using namespace std;


int initPlay(int isBlack, int* p_isWin, char board[16][16], ChessManual& manual, Ai& ai){
    ClearBoardArray(board);
    if (isBlack == 1){
        playChess(0, 1, 1, p_isWin, board, manual, ai);
    }
    else {
        playChess(0, 0, 1, p_isWin, board, manual, ai);
    }
    return 0;
}

int playChess(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai){
    role = 1;
    char coordinate[3];

    cout << "enter the coordinate:";
    cin >> coordinate;

    int y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
    int x = (coordinate[2] != '\0') ? 15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标

    while (manual.checkIfBan(x, y, role) || manual.checkIfHasChess(x, y)){
        cout << "This point is banned, please choose the point again." << endl;
        cin >> coordinate;
        y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
        x = (coordinate[2] != '\0') ? 15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标
    }

    arr[x][y] = isBlack ? 11:21;
    manual.checkGameOver(p_isWin);
    DisplayBoard(arr);
    arr[x][y] = isBlack ? 10:20;


    manual.record(x, y, role);

//    for (int j = 0;j<15;++j){
//        for (int k = 0;k<15;++k){
//            printf("%d",manual.getManualValue(j,k));
//        }
//        printf("\n");
//    }


    isGameOver = manual.checkGameOver(p_isWin);

    if (isGameOver == 1){
        cout << "YOU WIN THIS ROUND!!!" << endl;
        if (*p_isWin == 2){
            cout << "YOU WIN THE GAME!!!" << endl;
        }
        initPlay(isBlack, p_isWin, arr, manual, ai);
    }


    computerRun(isGameOver, isBlack, role, p_isWin, arr, manual, ai);

    return 0;
}

int computerRun(int isGameOver, int isBlack, int role , int* p_isWin, char arr[16][16], ChessManual& manual, Ai& ai) {
    role = 2;
    int x, y;
    ai.getNextStep(role, manual);
    x = ai.getNextStepX();
    y = ai.getNextStepY();

    manual.checkIfBan(x, y, role);
    manual.checkGameOver(p_isWin);
    isGameOver = manual.checkGameOver(p_isWin);

    if (isGameOver == 1) {
        cout << "YOU LOSE THE ROUND!!!" << endl;
        if (*p_isWin == -2){
            cout << "YOU LOSE THE GAME!!!" << endl;
        }
    }

    arr[x][y] = isBlack ? 21:11;
    manual.record(x, y, role);
    DisplayBoard(arr);


//    for (int j = 0;j<15;++j){
//        for (int k = 0;k<15;++k){
//            printf("%d",manual.getManualValue(j,k));
//        }
//        printf("\n");
//    }

//    printf("score = %d\n", ai.getNextStepScore());
    arr[x][y] = isBlack ? 20:10;

    playChess(isGameOver, isBlack, role, p_isWin, arr, manual, ai);
    return 0;
}

