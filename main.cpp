#include <iostream>
#include <string>
#include "draw.h"

using namespace std;

int main(){
	char arr[16][16];
	char coordinate[3];
	cout << "Welcome the five chess!\n "
         "please choose which white or black chess\n "
         "enter 1 for black and 2 for white [1 or 2]" << endl;
	int isBlack;
	cin >> isBlack;
    ClearBoardArray(arr);
    DisplayBoard(arr);
	if (isBlack == 1) {

        cout << "You go first, enter the coordinate (for example 'A6'), end with space\n" << endl;
        cin >> coordinate;
    }
	for (int i=0;i<=3;i++)
	    cout << coordinate[i]<<endl;
    int x = int(toupper(coordinate[0]))-65;//将输入的字母改为横坐标
	int y = (coordinate[2]!='\0') ? 15-((coordinate[1]-48)*10+(coordinate[2]-48)) : 15-(coordinate[1]-48);//将后面输入的数字转为纵坐标
	//cout << x << endl <<y << endl;
	arr [x][y] = 11;
    DisplayBoard(arr);
    return 0;
}
