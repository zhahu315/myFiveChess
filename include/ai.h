//
// Created by Zhang Chi on 2020/11/18.
//

#ifndef MYFIVECHESS_AI_H
#define MYFIVECHESS_AI_H
#include "chessManual.h"

class Ai{
public:
    Ai();
    int situationScore(int role, ChessManual& manual);
    void setLastStep(int x, int y);
    void setNextStep(int x, int y);
    int getNextStepX() const;
    int getNextStepY() const;
private:
    int chessMode[4][4][4][4][4][4];
    int lastStepX{};
    int lastStepY{};
    int nextStepX{};
    int nextStepY{};
};
#endif //MYFIVECHESS_AI_H
