#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char a[ROW][COL];
	InitBoard(a, sizeof(a[0][0]) * ROW * COL);
	DisplayBoard(a, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerTurn(a, ROW, COL);
		DisplayBoard(a, ROW, COL);


		char ret = IsWin(a,ROW,COL);
		if ( '*'==ret)
		{	printf("玩家获胜\n");
			break;
		}
		if ('#' == ret)
		{
			printf("电脑获胜\n");
			break;
		}
		if ('q'==ret)
		{
			printf("平局\n");
			break;
		}
		// 电脑下棋
 		ComputerTurn(a,ROW,COL);
		DisplayBoard(a, ROW, COL);
		ret = IsWin(a, ROW, COL);
		if ('#' == ret)
		{
			printf("电脑获胜\n");
			break;
		}
		if ('*' == ret)
		{
			printf("玩家获胜\n");
			break;
		}
		if ( 'q'==ret)
		{
			printf("平局\n");
			break;
		}
	}

}
int main()
{
	srand((unsigned int)time(NULL));
	int select;
	do
	{
		menu();
		printf("是否继续\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game(); 
			break;
		case 2:
			printf("退出");
			break;
		default:
			printf("选择错误，请重新选择");
			break;
		}
	} while(select);

}