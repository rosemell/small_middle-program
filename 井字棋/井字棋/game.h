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

//电脑下棋
void ComputerTurn(char a[ROW][COL], int row, int col);


//判断输赢
//玩家赢返回*	平局返回q
//电脑赢返回#	继续返回c
char IsWin(char a[ROW][COL], int row, int col);