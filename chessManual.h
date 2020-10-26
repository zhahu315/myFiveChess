//
// Created by 张弛 on 2020/9/20.
//

#ifndef MYFIVECHESS_CHESSMANUAL_H
#define MYFIVECHESS_CHESSMANUAL_H
class ChessManual {
public:
    ChessManual();
    int getManual();
    void record(int x, int y);
    void count();
private:
    char manual[16][16];
    int step = 0;

};

int checkGameOver(ChessManual& manual);

#endif //MYFIVECHESS_CHESSMANUAL_H
