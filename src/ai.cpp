//
// Created by Zhang Chi on 2020/11/18.
//
#include "ai.h"

using namespace std;

Ai::Ai() =default;

int Ai::findPosition(ChessManual& manual,int i, int j, int role){
    int sum=0;
    Position start;
    Position end;
    Position temp;
    //从左往右
    for(int n=0;n<5;++n) {
        start.x=i;
        start.y=j+n-4;
        end.x=start.x;
        end.y=start.y+4;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {
                temp.x = start.x;
                temp.y = start.y+k;
                if (manual.getManualValue(temp.x,temp.y) == 1)blackChess++;
                if (manual.getManualValue(temp.x,temp.y) == 2)whiteChess++;
            }
            sum += scoreTable(blackChess, whiteChess, role);
        }
    }
    //从上往下
    for(int n=0;n<5;++n) {
        start.x=i+4-n;
        start.y=j;
        end.x=start.x-4;
        end.y=start.y;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {
                temp.x = start.x-k;
                temp.y = start.y;
                if (manual.getManualValue(temp.x,temp.y) == 1)blackChess++;
                if (manual.getManualValue(temp.x,temp.y) == 2)whiteChess++;
            }
            sum += scoreTable(blackChess, whiteChess, role);
        }
    }

    //右上斜线
    for(int n=0;n<5;++n) {
        start.x=i-4+n;
        start.y=j+4-n;
        end.x=start.x-4;
        end.y=start.y+4;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {
                temp.x = start.x+k;
                temp.y = start.y-k;
                if (manual.getManualValue(temp.x,temp.y) == 1)blackChess++;
                if (manual.getManualValue(temp.x,temp.y) == 2)whiteChess++;
            }
            sum += scoreTable(blackChess, whiteChess, role);
        }
    }
    //左上斜线
    for(int n=0;n<5;++n) {
        start.x=i-4+n;
        start.y=j-4+n;
        end.x=start.x+4;
        end.y=start.y+4;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {
                temp.x = start.x+k;
                temp.y = start.y+k;
                if (manual.getManualValue(temp.x,temp.y) == 1)blackChess++;
                if (manual.getManualValue(temp.x,temp.y) == 2)whiteChess++;
            }
            sum += scoreTable(blackChess, whiteChess, role);
        }
    }

    return sum;
}

int Ai::scoreTable(int black, int white, int role){
    if(role==1&&black==5)return 10000000;
    if(role==2&&white==5)return 10000000;
    if(black==0&&white==0)return 7;
    else if(black>=1&&white>=1)return 0;
    else if(role==1){
        if(black==1&&white==0)return 35;
        else if(black==2&&white==0)return 800;
        else if(black==3&&white==0)return 15000;
        else if(black==4&&white==0)return 800000;
        else if(black==0&&white==1)return 15;
        else if(black==0&&white==2)return 400;
        else if(black==0&&white==3)return 1800;
        else return 100000;
    }else{
        if(black==1&&white==0)return 15;
        else if(black==2&&white==0)return 400;
        else if(black==3&&white==0)return 1800;
        else if(black==4&&white==0)return 100000;
        else if(black==0&&white==1)return 35;
        else if(black==0&&white==2)return 800;
        else if(black==0&&white==3)return 15000;
        else return 800000;
    }
}


int Ai::getNextStep(int role, ChessManual& manual) {
    int bestScore = 0;
    int bestRow = 0, bestCol = 0;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (manual.getManualValue(i, j) == 0 && !manual.checkIfHasChess(i, j) && !manual.checkIfBan(i, j, role)) {
                int tempScore = findPosition(manual, i, j, role);
                if (bestScore < tempScore) {
                    bestScore = tempScore;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    nextStepScore = bestScore;
    nextStepX = bestRow;
    nextStepY = bestCol;
    return 0;
}

int Ai::getNextStepX() const {
    return nextStepX;
}

int Ai::getNextStepY() const {
    return nextStepY;
}

int Ai::getNextStepScore() const{
    return nextStepScore;
}
