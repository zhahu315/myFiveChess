//
// Created by Zhang Chi on 2020/11/18.
//

#ifndef MYFIVECHESS_AI_H
#define MYFIVECHESS_AI_H
#include "chessManual.h"

class Ai{
public:
    Ai();
    static int findPosition(ChessManual& manual,int i, int j, int role);
    static int scoreTable(int black, int white, int C_ME);
    int getNextStep(int role, ChessManual& manual);
    int getNextStepX() const;
    int getNextStepY() const;
    int* getNextStepScore();
    struct Position{
        int x=0;
        int y=0;
    };
private:
    int nextStepScore;
    int nextStepX{};
    int nextStepY{};
};
#endif //MYFIVECHESS_AI_H
