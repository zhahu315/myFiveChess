#include <iostream>
#include <string>
#include "draw.h"

using namespace std;

int main(){
	char arr[16][16];
	cout << "Welcome the five chess!\n "
         "please choose which white or black chess\n "
         "enter 1 for black and 2 for white [1 or 2]" << endl;
	int isBlack;
	cin >> isBlack;
	if(isBlack == 1)
	    cout << "You go first\n" << endl;

    ClearBoardArray(arr);
	DisplayBoard(arr);
    return 0;
}
