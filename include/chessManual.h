//
// Created by 张弛 on 2020/9/20.
//

#ifndef MYFIVECHESS_CHESSMANUAL_H
#define MYFIVECHESS_CHESSMANUAL_H


class ChessManual {
public:
    ChessManual();
    int getManualValue(int x, int y);
    void record(int x, int y, int role);
    int checkGameOver(int role, int* pInt);
    bool checkIfBan(int x, int y, int role);
    bool checkIfHasChess(int x, int y);
    void setLastStep(int x, int y);
    void initManual();
    int getComputerScore() const;
    int getPlayerScore() const;
private:
    int lastStepX;
    int lastStepY;
    int iManual[15][15]={0};
    int computerScore;
    int playerScore;
};


#endif //MYFIVECHESS_CHESSMANUAL_H