//
// Created by 张弛 on 2020/9/20.
//
#include <iostream>
#include "draw.h"
#include "chessManual.h"

using namespace std;
int initPlay(int isBlack, char (*arr)[16]);
int playChess(int gameover, char (*arr)[16]);
int computerRun(int gameover, char (*arr)[16]);



int initPlay(int isBlack, char (*arr)[16]){
    if (isBlack == 1) {

        cout << "You go first, enter the coordinate (for example 'A6')\n" << endl;
        playChess(0, arr);
    }
    return 0;
}

int playChess(int gameover, char (*arr)[16]){
    char coordinate[3];
    ChessManual manual;//创建棋盘类
    while (gameover == 0) {
        cout << "enter the coordinate:";
        cin >> coordinate;
//    for (int i=0;i<=3;i++)
//        cout << coordinate[i]<<endl;
        int y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
        int x = (coordinate[2] != '\0') ?
                15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 -(coordinate[1] - 48);//将后面输入的数字转为纵坐标
        //cout << x << endl <<y << endl;
        arr[x][y] = 11;

        DisplayBoard(arr);
        checkGameOver();
        arr[x][y] = 10;
        manual.step += 1;
        gameover = 0;
        computerRun(0, arr);
    }
    return 0;
}

int computerRun(int gameover, char (*arr)[16]) {
    char coordinate[3];
    while (gameover == 0) {
        cout << "enter the coordinate:";
        cin >> coordinate;
//    for (int i=0;i<=3;i++)
//        cout << coordinate[i]<<endl;
        int y = int(toupper(coordinate[0])) - 65;//将输入的字母改为列坐标，并强制大写
        int x = (coordinate[2] != '\0') ?
                15 - ((coordinate[1] - 48) * 10 + (coordinate[2] - 48)) : 15 - (coordinate[1] - 48);//将后面输入的数字转为纵坐标
        //cout << x << endl <<y << endl;
        arr[x][y] = 21;

        DisplayBoard(arr);
        checkGameOver();
        arr[x][y] = 20;
        playChess(0, arr);
    }
    return 0;
}