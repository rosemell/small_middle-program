#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include"game.h"
void menu()
{
	printf("**************************************\n");
	printf("***************  1. play  ************\n");
	printf("***************  0. exit  ************\n");
	printf("**************************************\n");
}

void InitBoard(char board[ROWS][COLS], int row, int col, char init)
{
	//Ϊ�����ThunderCount�����еģ���ֹ����Խ�磬�ʽ��������ܵ����ݳ�ʼ��Ϊ��'*',Ϊ��Ӱ��ThunderBoard���ݹʸ�Ϊ�ַ�'0'
	
	int i, j;
	int row_1 = row - 1, col_1 = col - 1;
	for (i = 1; i < row_1;i++)
	{
		for (j = 1; j < col_1; j++)
		{
			board[i][j] = init;
		}
	}
	for (i = row_1; i>=0; i--)
	{
		board[i][0] = '0';
		board[i][col_1] = '0';
	}
	for (j = col_1; j>=0; j--)
	{
		board[0][j]='0';
		board[row_1][j]='0';
	}
	//for (i =0;i<=row_1;i++)
	//{
	//	board[i][0] = '0';
	//	board[i][col_1] = '0';
	//}
	//for (j = 0; j <= col_1; j++)
	//{
	//	board[0][j] = '0';
	//	board[row_1][j] = '0';
	//}
}
void ThunderSet(char board[ROWS][COLS], int row, int col, int tn)
{
	srand((unsigned int)time(NULL));
	int r, c;
	
	while(tn)
	{
		r = rand() % row + 1;
		c = rand() % col + 1;
		if (board[r][c] == '0')
		{
			board[r][c] = '1';
				tn--;
		}
	}
}
void SBoard(char Board[ROWS][COLS],int row,int col)
{
	int i,j;
	//printf(" ");
	printf("************** ɨ�� ****************\n");
	for (i = 0; i < row - 1;i++)
	{
		printf(" %d ", i);
	}
	printf("\n\n");
	for (i = 1; i < row - 1;i++)
	{
		printf("%d  ", i);
		
		for (j = 1; j < col - 1; j++)
		{
			printf(" %c ",Board[i][j]);
		}
		printf("\n\n");
	}
}

//void input(char Board[ROWS][COLS],int row,int col)
//{
//	printf("1.���");
//	printf("2.����");
//	int input;
//	scanf("%d", &input);
//	switch (input)
//	{
//	case 1:
//		Mark();
//		break;
//	case 2:
//		Sweep();
//		break;
//	default:
//		printf("�������");
//	}
//}
//void Mark()
//{
//
//}
//int ThunderCount(char Board[ROWS][COLS], int Ir, int Ic)
//{
//	//��������Ϊ0������Ϊ1
//	//��Ŀ��λ�õ���Χ�˸��е��ַ�ת��Ϊ����0��1��ӣ����ս�������׵�����
//	return (Board[Ir - 1][Ic] +
//			Board[Ir - 1][Ic - 1] +
//			Board[Ir - 1][Ic + 1] +
//			Board[Ir][Ic - 1] +
//			Board[Ir][Ic + 1] +
//			Board[Ir + 1][Ic] +
//			Board[Ir + 1][Ic - 1] +
//			Board[Ir + 1][Ic + 1] - 7 * '0');
//	
//}
//void input(char Board[ROWS][COLS],char TBoard[ROWS][COLS], int row, int col)
//{
//	int Ir, Ic,win=0;
//	while(win<row*col- ThunderNum)
//	{
//		printf("����������λ������:");
//		scanf("%d%d", &Ir, &Ic);
//		if(Ir>=1&&Ir<=row&&Ic>=1&&Ic<=col)
//		{
//			if (TBoard[Ir][Ic] == '1')
//			{
//				SBoard(TBoard, ROWS, COLS);
//				printf("���ź����˴����ף���Ϸ����\n");
//				break;
//			}
//			else
//			{
//				/*int count = ThunderCount(TBoard, Ir, Ic);
//				Board[Ir][Ic] = count; */
//				Board[Ir][Ic] = ThunderCount(TBoard, Ir, Ic);
//				win++;
//
//			}
//		}
//		else
//		{
//			printf("�Ƿ����꣬�������\n");
//		}
//		SBoard(Board, ROWS, COLS);
//	}
//	if (win == row * col - ThunderNum)
//	{
//		printf("��ϲ�㣡�������׳ɹ�����\n");
//		SBoard(TBoard, ROWS, COLS);
//	}
//}
void Choice(char Board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col)
{
	int win = ThunderNum,lose=1;
	while (win * lose)
	{
		printf("��ѡ������Ҫ��ǻ���Ҫ����\n1.����\n2.��ǻ�ȡ������׵�λ��\n");
		int input;
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Sweep(ShowBoard, Board, ROW, COL,&lose);
			SBoard(ShowBoard, ROWS, COLS);
			break;
		case 2: 	
			Mark(ShowBoard, Board, ROW, COL,&win);
			SBoard(ShowBoard, ROWS, COLS);
		
			break;
		}

	}
	if (lose == 0)
	{
		printf("���ź����˴����ף���Ϸ����\n");
		SBoard(Board, ROWS, COLS);

	}
	else
	{
		printf("��ϲ�㣡�ų��������ף����ʤ��!\n");
	}
}
void ThunderCount(char Board[ROWS][COLS],char SBoard[ROWS][COLS], int Ir, int Ic)
{
	//��������Ϊ0������Ϊ1
	//��Ŀ��λ�õ���Χ�˸��е��ַ�ת��Ϊ����0��1��ӣ����ս�������׵�����
	int count = (Board[Ir - 1][Ic] +
		Board[Ir - 1][Ic - 1] +
		Board[Ir - 1][Ic + 1] +
		Board[Ir][Ic - 1] +
		Board[Ir][Ic + 1] +
		Board[Ir + 1][Ic] +
		Board[Ir + 1][Ic - 1] +
		Board[Ir + 1][Ic + 1] - 7 * '0');
	if (count == '0')
	{
		int i, j;
		for (i = Ir - 1; i <= Ir + 1; i++)
		{
			for (j = Ic - 1; j <= Ic + 1; j++)
				if (SBoard[i][j] == '*')
				{
					SBoard[Ir][Ic] = count;
					ThunderCount(Board, SBoard, i, j);
				}
		}
	}
	SBoard[Ir][Ic] = count;

}
void Sweep(char Board[ROWS][COLS], char TBoard[ROWS][COLS], int row, int col,int *lose)
{
	int Ir, Ic = 0;
	//while (win < row * col - ThunderNum)
	{
		printf("����������λ������:");
		scanf("%d%d", &Ir, &Ic);
		if (Ir >= 1 && Ir <= row && Ic >= 1 && Ic <= col)
		{
			if (TBoard[Ir][Ic] == '1')
			{
				(*lose)--;
				//printf("���ź����˴����ף���Ϸ����\n");
				//break;
			}
			else
			{
				/*int count = ThunderCount(TBoard, Ir, Ic);
				Board[Ir][Ic] = count; */
				//Board[Ir][Ic] = ThunderCount(TBoard,Board, Ir, Ic);
				ThunderCount(TBoard, Board, Ir, Ic);
			}
		}
		else
		{
			printf("�Ƿ����꣬�������\n");
		}
		SBoard(Board, ROWS, COLS);
	}
	//��ɾ
	//if (win == row * col - ThunderNum)
	//{
	//	printf("��ϲ�㣡�������׳ɹ�����\n");
	//	SBoard(TBoard, ROWS, COLS);
	//}
}
void Mark(char Board[ROWS][COLS], char TBoard[ROWS][COLS], int row, int col,int *win)
{
	printf("��������Ҫ��ǻ���Ҫȡ����ǵ�����\n");
	int Ir, Ic;
	scanf("%d%d", &Ir, &Ic);
	if (Board[Ir][Ic] == '*')
	{
		Board[Ir][Ic] = '#';
		if (TBoard[Ir][Ic] == '1')
		{
			(*win)--;
		}
	}
	else if (Board[Ir][Ic] == '#')
	{
		Board[Ir][Ic] = '*';
		if (TBoard[Ir][Ic] == '1')
		{
			(*win)++;
		}
	}
	else
	{
		printf("����Ƿ�������������");
	}
}