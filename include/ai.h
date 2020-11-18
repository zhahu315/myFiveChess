//
// Created by Zhang Chi on 2020/11/18.
//

#ifndef MYFIVECHESS_AI_H
#define MYFIVECHESS_AI_H
#include "chessManual.h"

class Ai{
public:
    Ai();
    int findPosition(ChessManual& manual,int i, int j, int role);
    static int scoreTable(int black, int white, int C_ME);

    int evaluate(int role, ChessManual& manual);
    int alphaBetaSearch(int alpha, int beta);
    void setLastStep(int x, int y);
    int getNextStep(int role, ChessManual& manual);
    void setNextStep(int x, int y);
    int getNextStepX() const;
    int getNextStepY() const;

    struct Position{
        int x=0;
        int y=0;
    };
private:
    int score;
    int nextPosition[15];
    int mode[8]={};
    int chessMode[4][4][4][4][4][4]{};
    int totalScore=0;
    int lastStepX{};
    int lastStepY{};
    int nextStepX{};
    int nextStepY{};
};
#endif //MYFIVECHESS_AI_H
