#include <iostream>

void DisplayBoard(char (*arr)[16]) //画棋盘
{	
	int i, j;
	using namespace std;
	
	for(i = 0; i <= 15; i++)
	{
		for(j = 0; j <= 15; j++)
		{
			switch(arr[i][j] % 100)//%100为了适应将来有分值的情形
			{
			case 1:
				cout <<"┏";
				break;

			case 2:
				cout <<"┓";
				break;

			case 3:
				cout <<"┛";
				break;

			case 4:
				cout <<"┗";
				break;

			case 5:
				cout <<"┠";
				break;

			case 6:
				cout <<"┯";
				break;

			case 7:
				cout <<"┨";
				break;

			case 8:
				cout <<"┷";
				break;

			case 9:
				cout <<"┼";
				break;

			case 10:
				cout <<"●";
				break;

			case 11:
				cout <<"▲";
				break;

			case 20:
				cout <<"◎";
				break;

			case 21:
				cout <<"△";
				break;

				case 22:
			        cout << char(64+j);

			}
			if (j == 14)
			{
                cout << 15 - i << endl;
            }
		}
	}
}

void ClearBoardArray(char (*arr)[16])
{
	int i, j; //i＝行，j＝列
	arr[0][0] = 1;
	arr[0][14] = 2;
	arr[14][14] = 3;
	arr[14][0] = 4;

	for (i = 1; i <= 13; i++)
	{
		arr[i][0] = 5;
	}
	
	for (i = 1; i <= 13; i++)
	{
		arr[i][14] = 7;
	}
	
	for (j = 1; j <= 13; j++)
	{
		arr[0][j] = 6;
	}
	for (j = 1; j <= 13; j++)
	{
		arr[14][j] = 8;
	}

	for (i = 1; i <= 13; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			arr[i][j] = 9;
		}
	}
	for (j = 1;j <= 14; j++)
    {
	    arr[15][j] = 22;
    }
}