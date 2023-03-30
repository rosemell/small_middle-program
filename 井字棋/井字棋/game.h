#pragma once
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void menu();
void DisplayBoard(char a[ROW][COL], int row, int col);
void InitBoard(char a[ROW][COL], int sz);

void game();
void PlayerTurn(char a[ROW][COL], int row, int col);

//��������
void ComputerTurn(char a[ROW][COL], int row, int col);


//�ж���Ӯ
//���Ӯ����*	ƽ�ַ���q
//����Ӯ����#	��������c
char IsWin(char a[ROW][COL], int row, int col);