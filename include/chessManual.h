//
// Created by 张弛 on 2020/9/20.
//

#ifndef MYFIVECHESS_CHESSMANUAL_H
#define MYFIVECHESS_CHESSMANUAL_H

class ChessManual {
public:
    ChessManual();
    int getManualValue(int x, int y);//返回数组指针
    void record(int x, int y, int role);
    int checkGameOver(int* isWin);
    bool checkIfBan(int x, int y, int role);

private:
    int iManual[15][15];
    int playerScore = 0;
    int computerScore = 0;

};


#endif //MYFIVECHESS_CHESSMANUAL_H