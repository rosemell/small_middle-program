#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include"game.h"
void menu()
{
	printf("\t****************\n");
	printf("\t**** 1.play ****\n");
	printf("\t**** 0.exit ****\n");
	printf("\t****************\n");
 }
void DisplayBoard(char a[ROW][COL],int row,int col)
{
	int i;
	for (i = 0; i < row; i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", a[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
//��ʼ������
void InitBoard(char a[ROW][COL],int sz)
{
	memset(a, ' ', sz);
}
void PlayerTurn(char a[ROW][COL], int row, int col)
{
	printf("��һغ�,����������λ������:");
	int r, c;
	while(1)
	{
		scanf("%d%d", &r, &c);
		c--; r--;
		if (r >= 0 && r < ROW && c >=0 && c < COL)
		{
			if (a[r][c] == ' ')
			{
				a[r][c] = '*';
				break;
			}
			else
			{
				printf("�˴�������,����������:");
			}
		}
		else
		{
			printf("����Ƿ������������룺");

		}
	}
}
//�����£������
void ComputerTurn(char a[ROW][COL], int row, int col)
{
	int r, c;
	printf("��������λ��\n");
	while(1)
	{
		r = rand() % row;
		c = rand() % col;
		if (a[r][c] == ' ')
		{
			a[r][c] = '#';
			break;
		}
	}
}
//�ж���Ӯ
//���Ӯ����*	ƽ�ַ���q
//����Ӯ����#	��������c

int IsFault(char a[ROW][COL],int row, int col)
{
	int i, j;
	for (i = 0; i <= row; i++)
	{
		for (j = 0; j < col; j++)
			if (a[i][j] == ' ')
				return 0;
	}
	return 1;
}

char IsWin(char a[ROW][COL], int row, int col)
{
	int i;
	for (i = 0; i < ROW; i++)
	{
		if (a[i][0] == a[i][1] && a[i][0] == a[i][2] && a[i][0] != ' ')
		{
			return a[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != ' ')
		{
			return a[0][i];
		}
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != ' ')
	{
		return a[0][0];
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[0][0] != ' ')
	{
		return a[0][2];
	}
	if (IsFault(a, row, col))
		return 'q';
	return 'c';
}