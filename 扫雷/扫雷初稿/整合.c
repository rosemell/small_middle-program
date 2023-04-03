#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include"game.h"




void game()
{
	char ThunderBoard[ROWS][COLS]={0};
	char ShowBoard[ROWS][COLS]={0};
	InitBoard(ThunderBoard, ROWS, COLS, '0');
	InitBoard(ShowBoard, ROWS, COLS, '*');

	ThunderSet(ThunderBoard, ROW, COL, ThunderNum);
	
	SBoard(ShowBoard, ROWS, COLS);
	SBoard(ThunderBoard, ROWS, COLS);
	Choice(ThunderBoard, ShowBoard,ROW,COL);
}



int main()
{

	int input;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				printf("开始游戏：\n");
				game();
				break;
		case 0:
				printf("结束游戏：\n");
				break;
		default:
				printf("输入错误，请重新选择：\n");
				break;
		}

	} while (input);

	return 0;
}