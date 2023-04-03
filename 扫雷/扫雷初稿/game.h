#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define ThunderNum 10
//#define ThunderNum 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();

void InitBoard(char board[ROWS][COLS], int row, int col, char init);
//void ThunderSet(char board[ROWS][COLS], int row, int col, int tn)
void ThunderSet(char board[ROWS][COLS],int row,int col, int tn);
void SBoard(char Board[ROWS][COLS], int row, int col);
void input(char Board[ROWS][COLS], int row, int col);
void ThunderCount(char Board[ROWS][COLS], char SBoard[ROWS][COLS], int Ir, int Ic);
//int ThunderCount(char Board[ROWS][COLS], int ir, int ic);
void Sweep(char Board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col,int *lose);
void Choice(char Board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col);
void Mark(char Board[ROWS][COLS], char ShowBoard[ROWS][COLS], int row, int col,int *win);








