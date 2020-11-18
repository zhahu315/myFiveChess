//
// Created by Zhang Chi on 2020/11/18.
//
#include "ai.h"


enum mode{none, white_win, black_win, white_4, black_4, white_n4, black_n4, white_3, black_3, white_n3, black_n3, white_2,
    black_2, white_n2, black_n2, white_1, black_1};

using namespace std;
/*
Ai::Ai(){
    memset(chessMode,0,sizeof (chessMode));
    chessMode[2][2][2][2][2][2]=white_win;
    chessMode[2][2][2][2][2][0]=white_win;
    chessMode[0][2][2][2][2][2]=white_win;
    chessMode[2][2][2][2][2][1]=white_win;
    chessMode[1][2][2][2][2][2]=white_win;
    chessMode[3][2][2][2][2][2]=white_win;
    chessMode[2][2][2][2][2][3]=white_win;
    chessMode[1][1][1][1][1][1]=black_win;
    chessMode[1][1][1][1][1][0]=black_win;
    chessMode[0][1][1][1][1][1]=black_win;
    chessMode[1][1][1][1][1][2]=black_win;
    chessMode[2][1][1][1][1][1]=black_win;
    chessMode[3][1][1][1][1][1]=black_win;
    chessMode[1][1][1][1][1][3]=black_win;
    chessMode[0][2][2][2][2][0]=white_4;
    chessMode[0][1][1][1][1][0]=black_4;
    chessMode[0][2][2][2][0][0]=white_3;
    chessMode[0][0][2][2][2][0]=white_3;
    chessMode[0][2][0][2][2][0]=white_3;
    chessMode[0][2][2][0][2][0]=white_3;
    chessMode[0][1][1][1][0][0]=black_3;
    chessMode[0][0][1][1][1][0]=black_3;
    chessMode[0][1][0][1][1][0]=black_3;
    chessMode[0][1][1][0][1][0]=black_3;
    chessMode[0][2][2][0][0][0]=white_2;
    chessMode[0][2][0][2][0][0]=white_2;
    chessMode[0][2][0][0][2][0]=white_2;
    chessMode[0][0][2][2][0][0]=white_2;
    chessMode[0][0][2][0][2][0]=white_2;
    chessMode[0][0][0][2][2][0]=white_2;
    chessMode[0][1][1][0][0][0]=black_2;
    chessMode[0][1][0][1][0][0]=black_2;
    chessMode[0][1][0][0][1][0]=black_2;
    chessMode[0][0][1][1][0][0]=black_2;
    chessMode[0][0][1][0][1][0]=black_2;
    chessMode[0][0][0][1][1][0]=black_2;
    chessMode[0][2][0][0][0][0]=white_1;
    chessMode[0][0][2][0][0][0]=white_1;
    chessMode[0][0][0][2][0][0]=white_1;
    chessMode[0][0][0][0][2][0]=white_1;
    chessMode[0][1][0][0][0][0]=black_1;
    chessMode[0][0][1][0][0][0]=black_1;
    chessMode[0][0][0][1][0][0]=black_1;
    chessMode[0][0][0][0][1][0]=black_1;

    int i1,i2,i3,i4,i5,i6,count_black_left,count_white_left,count_black_right,count_white_right;//count_black:左5中黑个数,y:左5中白个数,ix:右5中黑个数,iy:右5中白个数
    for(i1=0; i1 < 4; ++i1){
        for(i2=0; i2 < 3; ++i2){
            for(i3=0; i3 < 3; ++i3){
                for(i4=0; i4 < 3; ++i4){
                    for(i5=0; i5 < 3; ++i5){
                        for(i6=0; i6 < 4; ++i6){
                            count_black_left= count_white_left= count_black_right= count_white_right=0;

                            if(i1 == 1)count_black_left++;
                            else if(i1 == 2)count_white_left++;

                            if(i2 == 1){count_black_left++;count_black_right++;}
                            else if(i2 == 2){count_white_left++;count_white_right++;}

                            if(i3 == 1){count_black_left++;count_black_right++;}
                            else if(i3 == 2){count_white_left++;count_white_right++;}

                            if(i4 == 1){count_black_left++;count_black_right++;}
                            else if(i4 == 2){count_white_left++;count_white_right++;}

                            if(i5 == 1){count_black_left++;count_black_right++;}
                            else if(i5 == 2){count_white_left++;count_white_right++;}

                            if(i6 == 1)count_black_right++;
                            else if(i6 == 2)count_white_right++;

                            if(i1 == 3 || i6 == 3){
                                if(i1 == 3 && i6 != 3){
                                    if(count_black_right == 0 && count_white_right == 4){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_n4;
                                    }
                                    if(count_black_right == 4 && count_white_right == 0){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=black_n4;
                                    }
                                    if(count_black_right == 0 && count_white_right == 3){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_n3;
                                    }
                                    if(count_black_right == 3 && count_white_right == 0){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=black_n3;
                                    }
                                    if(count_black_right == 0 && count_white_right == 2){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_n2;
                                    }
                                    if(count_black_right == 2 && count_white_right == 0){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=black_n2;
                                    }
                                }else if(i6 == 3 && i1 != 3){
                                    if(count_black_left == 0 && count_white_left == 4){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_n4;
                                    }
                                    if(count_black_left == 4 && count_white_left == 0){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=black_n4;
                                    }
                                    if(count_black_left == 3 && count_white_left == 0){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_n3;
                                    }
                                    if(count_black_left == 0 && count_white_left == 3){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_3;
                                    }
                                    if(count_black_left == 2 && count_white_left == 0){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=white_n2;
                                    }
                                    if(count_black_left == 0 && count_white_left == 2){
                                        if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                            chessMode[i1][i2][i3][i4][i5][i6]=black_n2;
                                    }
                                }
                            }else{
                                if((count_black_left == 0 && count_white_left == 4) || (count_black_right == 0 && count_white_right == 4)){
                                    if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                        chessMode[i1][i2][i3][i4][i5][i6]=white_n4;
                                }
                                if((count_black_left == 4 && count_white_left == 0) || (count_black_right == 4 && count_white_right == 0)){
                                    if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                        chessMode[i1][i2][i3][i4][i5][i6]=black_n4;
                                }
                                if((count_black_left == 0 && count_white_left == 3) || (count_black_right == 0 && count_white_right == 3)){
                                    if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                        chessMode[i1][i2][i3][i4][i5][i6]=white_n3;
                                }
                                if((count_black_left == 3 && count_white_left == 0) || (count_black_right == 3 && count_white_right == 0)){
                                    if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                        chessMode[i1][i2][i3][i4][i5][i6]=black_n3;
                                }
                                if((count_black_left == 0 && count_white_left == 2) || (count_black_right == 0 && count_white_right == 2)){
                                    if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                        chessMode[i1][i2][i3][i4][i5][i6]=white_n2;
                                }
                                if((count_black_left == 2 && count_white_left == 0) || (count_black_right == 2 && count_white_right == 0)){
                                    if(chessMode[i1][i2][i3][i4][i5][i6] == 0)
                                        chessMode[i1][i2][i3][i4][i5][i6]=black_n2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


int Ai::evaluate(int role, ChessManual &manual) {
    int assignValue[]={0,1000000,-10000000,50000,-100000,500,-100000,500,-4000,20,-60,20,-60,1,-3,1,-3};
    int scoreManual[4][17] = {0};
    int extension[17][17] = {0};
    int i, j, chess;
    for (int i=0;i<17;i++){
        for (int j=0;j<17;j++){
            extension[i][j] = (i==0 || i==16 || j==0 || j==16) ? 3 : manual.getManualValue(i-1, j-1);
        }
    }
    for(i=1;i<=15;++i){
        for(j=0;j<12;++j){
            chess=chessMode[extension[i][j]][extension[i][j+1]][extension[i][j+2]][extension[i][j+3]][extension[i][j+4]][extension[i][j+5]];
            scoreManual[0][chess]++;
        }
    }
    for(j=1;j<=15;++j){
        for(i=0;i<12;++i){
            chess=chessMode[extension[i][j]][extension[i+1][j]][extension[i+2][j]][extension[i+3][j]][extension[i+4][j]][extension[i+5][j]];
            scoreManual[1][chess]++;
        }
    }
    for(i=0;i<12;++i){
        for(j=0;j<12;++j){
            chess=chessMode[extension[i][j]][extension[i+1][j+1]][extension[i+2][j+2]][extension[i+3][j+3]][extension[i+4][j+4]][extension[i+5][j+5]];
            scoreManual[2][chess]++;
        }
    }
    for(i=0;i<12;++i){
        for(j=5;j<17;++j){
            chess=chessMode[extension[i][j]][extension[i+1][j-1]][extension[i+2][j-2]][extension[i+3][j-3]][extension[i+4][j-4]][extension[i+5][j-5]];
            scoreManual[3][chess]++;
        }
    }
    for (i=0;i<4;++i){
        for (j = 1; j < 17; ++j) {
            score+= scoreManual[i][j]*assignValue[j];
        }
    }
    return 0;
}


*/

Ai::Ai() =default;

int Ai::findPosition(ChessManual& manual,int i, int j, int role){
    int sum=0;
    Position start;
    Position end;
    Position temp;
    //从左往右
    for(int n=0;n<5;++n) {//每个方向上最多5个五元组
        start.x=i;//五元组顶点位置
        start.y=j+n-4;
        end.x=start.x;//五元组最远位置
        end.y=start.y+4;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
                int blackChess = 0;
                int whiteChess = 0;
                for (int k = 0; k < 5; ++k) {//对五元组5个位置考察
                    temp.x = start.x;
                    temp.y = start.y+k;
                    if (manual.getManualValue(temp.x,temp.y) == 1)blackChess++;
                    if (manual.getManualValue(temp.x,temp.y) == 2)whiteChess++;
                }
                sum += scoreTable(blackChess, whiteChess, role);
            }
        }
    //从上往下
    for(int n=0;n<5;++n) {//每个方向上最多5个五元组
        start.x=i+4-n;//五元组顶点位置
        start.y=j;
        end.x=start.x-4;//五元组最远位置
        end.y=start.y;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {//对五元组5个位置考察
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
        start.x=i+4-n;
        start.y=j+n-4;
        end.x=start.x-4;
        end.y=start.y+4;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {
                temp.x = start.x-k;
                temp.y = start.y-k;
                if (manual.getManualValue(temp.x,temp.y) == 1)blackChess++;
                if (manual.getManualValue(temp.x,temp.y) == 2)whiteChess++;
            }
            sum += scoreTable(blackChess, whiteChess, role);
        }
    }
    //左上斜线
    for(int n=0;n<5;++n) {//每个方向上最多5个五元组
        start.x=+4-n;//五元组顶点位置
        start.y=j+4-n;
        end.x=start.x-4;//五元组最远位置
        end.y=start.y-4;
        if (start.x >= 0 && start.x < 15 && start.y >= 0 && start.y < 15 && end.x >= 0 && end.x < 15 && end.y >= 0 && end.y < 15 ) {
            int blackChess = 0;
            int whiteChess = 0;
            for (int k = 0; k < 5; ++k) {//对五元组5个位置考察
                temp.x = start.x;
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
    //连5
    if(role==1&&black==5)return 9999999;
    if(role==2&&white==5)return 9999999;
    //全空
    if(black==0&&white==0)return 7;
        //polluted
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
            if (manual.getManualValue(i, j) == 0) {
                int tempScore = findPosition(manual, i, j, role);
                if (bestScore < tempScore) {
                    bestScore = tempScore;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    nextStepX = bestRow;
    nextStepY = bestCol;
    return 0;
}
/*

    int Ai::getNextStep(ChessManual &manual) {
        bool btemp[15][15] = {0};
        int itemp[15][15] = {0};
        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                if (manual.getManualValue(i, j) != 0) {
                    for (int k = -3; k <= 3; ++k) {
                        if (i + k >= 0 && i + k < 15) {
                            btemp[i + k][j] = true;
                            if (j + k >= 0 && j + k < 15)btemp[i + k][j + k] = true;
                            if (j - k >= 0 && j - k < 15)btemp[i + k][j - k] = true;
                        }
                        if (j + k >= 0 && j + k < 15)btemp[i][j + k] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 15; ++i) {
            for (int j = 0; j < 15; ++j) {
                itemp[i][j] = -100000000;
                if (manual.getManualValue(i, j) == 0 && btemp[i][j]) {
                    itemp[i][j] = calcOnePosGreedy(manual, i, j, 1);
                }
            }
        }

        int w;
        for (int k = 0; k < 20; ++k) {
            w = -100000000;
            for (int i = 0; i < 15; ++i) {
                for (int j = 0; j < 15; ++j) {
                    if (worth[i][j] > w) {
                        w = worth[i][j];
                        QPoint tmp(i, j);
                        best_points.pos[k] = tmp;
                    }
                }
            }

            int x = best_points.pos[k].x(), y = best_points.pos[k].y();
            board[x][y] = C_WHITE;
            best_points.score[k] = evaluate(board).score;
            board[x][y] = C_NONE;

            worth[best_points.pos[k].x()][best_points.pos[k].y()] = -INT_MAX;//清除掉上一点,计算下一点的位置和分数
        }
        return best_points;
    }


    int Ai::alphaBetaSearch(int alpha, int beta) {

    }


    void Ai::setLastStep(int x, int y) {
        lastStepX = x;
        lastStepY = y;
    }

    void Ai::setNextStep(int x, int y) {

    }
    */
    int Ai::getNextStepX() const {
        return nextStepX;
    }

    int Ai::getNextStepY() const {
        return nextStepY;
    }
