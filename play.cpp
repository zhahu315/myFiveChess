//
// Created by 张弛 on 2020/9/20.
//
#include <iostream>
#include "draw.h"
#include "chessManual.h"

using namespace std;
int initPlay(int isBlack, char arr[16][16]);
int playChess(int gameover, char arr[16][16], ChessManual& manual);
int computerRun(int gameover, char arr[16][16], ChessManual& manual);



int initPlay(int isBlack, char arr[16][16], ChessManual& manual){
    if (isBlack == 1) {

        cout << "You go first, enter the coordinate (for example 'A6')\n" << endl;
        playChess(0, arr, manual);
    }
    return 0;
}

//判断禁手
int ifBan(char arr[16][16]){

    return 0;
}

int playChess(int gameover, char arr[16][16], ChessManual& manual){
    char coordinate[3];
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
        arr[x][y] = 10;

        manual.getManual();
        manual.record(x, y);
        manual.count();

        gameover = checkGameOver(manual);
        if (gameover == 1){
            cout << "YOU WIN !!!" << endl;
            break;
        }
        computerRun(0, arr, manual);
    }
    cout << "YOU LOSE !!!" << endl;
    return 0;
}

int computerRun(int gameover, char arr[16][16], ChessManual& manual) {
    char coordinate[3];
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
    checkGameOver(manual);
    arr[x][y] = 20;
    return 0;
}