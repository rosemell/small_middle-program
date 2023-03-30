#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char a[ROW][COL];
	InitBoard(a, sizeof(a[0][0]) * ROW * COL);
	DisplayBoard(a, ROW, COL);
	while (1)
	{
		//�������
		PlayerTurn(a, ROW, COL);
		DisplayBoard(a, ROW, COL);


		char ret = IsWin(a,ROW,COL);
		if ( '*'==ret)
		{	printf("��һ�ʤ\n");
			break;
		}
		if ('#' == ret)
		{
			printf("���Ի�ʤ\n");
			break;
		}
		if ('q'==ret)
		{
			printf("ƽ��\n");
			break;
		}
		// ��������
 		ComputerTurn(a,ROW,COL);
		DisplayBoard(a, ROW, COL);
		ret = IsWin(a, ROW, COL);
		if ('#' == ret)
		{
			printf("���Ի�ʤ\n");
			break;
		}
		if ('*' == ret)
		{
			printf("��һ�ʤ\n");
			break;
		}
		if ( 'q'==ret)
		{
			printf("ƽ��\n");
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
		printf("�Ƿ����\n");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			game(); 
			break;
		case 2:
			printf("�˳�");
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;
		}
	} while(select);

}