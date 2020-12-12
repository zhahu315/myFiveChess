#include <iostream>

void DisplayBoard(char arr[16][16])
{	
	int i, j;
	using namespace std;

	for(i = 0; i <= 15; i++)
	{
		for(j = 0; j <= 15; j++)
		{
			switch(arr[i][j])
			{
                case 1:
                    printf("©³");
                    break;

                case 2:
                    printf("©·");
                    break;

                case 3:
                    printf("©¿");
                    break;

                case 4:
                    printf("©»");
                    break;

                case 5:
                    printf("©Ä");
                    break;

                case 6:
                    printf("©Ó");
                    break;

                case 7:
                    printf("©Ì");
                    break;

                case 8:
                    printf("©Û");
                    break;

                case 9:
                    printf("©à");
                    break;

                case 10:
                    printf("¡ñ");
                    break;

                case 11:
                    printf("¡ø");
                    break;

                case 20:
                    printf("¡ò");
                    break;

                case 21:
                    printf("¡÷");
                    break;

				case 22:
				    printf("%c ", char(64+j));
			}
			if (j == 14)
			{
                cout << 15 - i << endl;
            }
		}
	}
}

void ClearBoardArray(char arr[16][16])
{
	int i, j; //i£½ÐÐ£¬j£½ÁÐ
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