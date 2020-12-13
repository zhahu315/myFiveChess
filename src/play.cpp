//
// Created by 张弛 on 2020/9/20.
//
#include <iostream>
#include "../include/draw.h"
#include "../include/chessManual.h"
#include "play.h"
#include "ai.h"

using namespace std;


int initPlay(int isBlack, char arr[16][16], ChessManual& manual, Ai& ai){
    ClearBoardArray(arr);
    DisplayBoard(arr);
    if (isBlack == 1){
        manual.initManual();
        int x = 7;
        int y = 7;
        arr[x][y] = 11;
        manual.record(x, y, 2);
        DisplayBoard(arr);
        arr[x][y] = 10;
        playChess(0, 1, 1, arr, manual, ai);

    }
    else {
        manual.initManual();
        playChess(0, 0, 1, arr, manual, ai);
    }
    return 0;
}

int playChess(int isGameOver, int isBlack, int role , char arr[16][16], ChessManual& manual, Ai& ai){
    role = 1;
    char coordinate[3];

    cout << "请输入坐标按下回车（例如：'H6'，'F12'，不区分大小写）>>>";
    cin >> coordinate;

    int y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
    int x = (coordinate[2] != '\0') ? 15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标

    while (manual.checkIfBan(x, y, role) || manual.checkIfHasChess(x, y)){
        cout << "你选择的落子点犯规，请重新选择。" << endl;
        cin >> coordinate;
        y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
        x = (coordinate[2] != '\0') ? 15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标
    }

    arr[x][y] = isBlack ? 11:21;
    manual.setLastStep(x, y);

    int *computerScore = ai.getNextStepScore();
    isGameOver = manual.checkGameOver(role, computerScore);
    DisplayBoard(arr);
    arr[x][y] = isBlack ? 10:20;

    manual.record(x, y, role);

    for (int j = 0;j<15;++j){
        for (int k = 0;k<15;++k){
            printf("%d",manual.getManualValue(j,k));
        }
        printf("\n");
    }


    if (isGameOver == 1){
        printf("=====你赢了这一局，目前比分 你%d:%d电脑=====\n", manual.getPlayerScore(), manual.getComputerScore());
        cin.get();
        if (manual.getPlayerScore() == 2){
            cout << "=====你输掉了这场游戏!!!=====" << endl;
            cin.get();
        } else initPlay(isBlack, arr, manual, ai);
    }else computerRun(isGameOver, isBlack, role, arr, manual, ai);

    return 0;
}

int computerRun(int isGameOver, int isBlack, int role , char arr[16][16], ChessManual& manual, Ai& ai) {
    role = 2;
    int x, y;
    ai.getNextStep(role, manual);
    x = ai.getNextStepX();
    y = ai.getNextStepY();

    manual.setLastStep(x, y);
    int *computerScore = ai.getNextStepScore();
    isGameOver = manual.checkGameOver(role, computerScore);


    arr[x][y] = isBlack ? 21:11;
    manual.record(x, y, role);
    DisplayBoard(arr);




    for (int j = 0;j<15;++j){
        for (int k = 0;k<15;++k){
            printf("%d",manual.getManualValue(j,k));
        }
        printf("\n");
    }
    printf("score = %d\n", *ai.getNextStepScore());

    arr[x][y] = isBlack ? 20:10;

    if (isGameOver == 1) {
        printf("=====你输了这一局，目前比分 你%d:%d电脑=====\n", manual.getPlayerScore(), manual.getComputerScore());
        cin.get();
        if (manual.getComputerScore() == 2){
            cout << "=====你输了这场游戏!!!=====" << endl;
            cin.get();
        } else{
            initPlay(isBlack, arr, manual, ai);
        }
    }else playChess(isGameOver, isBlack, role, arr, manual, ai);
    return 0;
}
