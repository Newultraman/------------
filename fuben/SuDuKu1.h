#ifndef SuDuKu_h
#define SuDuKu_h
#include <bits/stdc++.h>
#include <time.h>
#include <stddef.h>//malloc等动态分配函数
#include <stdlib.h>//系统清屏函数
#include <stdio.h>//标准输入输出函数
#include <math.h>
#include <limits.h>
#include <string.h>//用于字符串文件读写操作
#include "ShuDuKu1.h"
using namespace std;

#pragma warning(disable:4996)

#define FALSE -1
#define OK 1
#define N 5000
#define numofshuang 1458

typedef int status;
int variable , sentences ;//记录变元数和公式数
int FLAG;//选择策略
int mark_ture[N];//保存正确的解
int mark_1[N];//存储变元出现的次数
int mark_2[N];//存储变元的下标
int a[10][10][10];//三维数组
int counnt ;//记录挖洞数
int hole1[9][9];//记录第一大盘挖过的洞
int hole2[9][9];//记录第二大盘挖过的洞
int shuzu1[9][9];//记录棋盘1
int shuzu2[9][9];//记录棋盘2
int pipei[2000];//记录最后的匹配值


//邻接表一之存储
typedef struct EdgeNode {//小边集合
    int num;
    int mark;
    struct EdgeNode *next;
}EdgeNode, *edgenode;

typedef struct HeadNode {//大边集合
    int count;
    int mark;
    int flag;
    struct HeadNode *next;
    struct EdgeNode *inside;
}HeadNode, *headnode;
//邻接表二之索引

typedef struct SerchNode {//用于直接删除，不需要遍历
    int zheng_mark;//标记正变元
    int fu_mark;//标记负变元
    struct EdgeNode *inside_zheng;//指向正变元
    struct HeadNode *outside_zheng;
    struct EdgeNode *inside_fu;//指向负变元
    struct HeadNode *outside_fu;
    struct  SerchNode*next;
}SerchNode, SerchList[N+1];

typedef struct {//用于删除合适的假设真值
    SerchList serchlist;
    int mark;
} BigNode, *bignode;
int Delete_Num(int arr[][9]);
status  Juge_Hole(int arr[][9], int n, int m, int k,headnode H, bignode  F);
status Dig_Hole(int arr[][9],int n, int m, int k, headnode H, bignode  F);
status resolve_sudoku(int arr[][9], headnode H, bignode  F);

/*int Delete_Num(int arr[][9])
{
    int k = 0;
    for (int i = 0; i < 9; i++)//初始化
        if (i % 2 == 0)
        {
            for (int j = 0; j < 9; j++)
            {
                if (arr[i][j] != 0 && hole[i][j] == 0)
                {
                    k = arr[i][j];
                    arr[i][j] = 0;
                    hole[i][j] = 1;
                    return (i + 1) * 100 + (j + 1) * 10 + k;
                }
            }
        }
        else
        {
            for (int j = 8; j >=0; j--)
                if (arr[i][j] != 0 && hole[i][j] == 0)
                {
                    k = arr[i][j];
                    arr[i][j] = 0;
                    hole[i][j] = 1;
                    return (i + 1) * 100 + (j + 1) * 10 + k;
                }
        }
    return 0;
}*/

//判断洞是否可以挖
/*status  Juge_Hole(int arr[][9], int n, int m, int k,headnode H, bignode  F)
{
    for(int i= 1;i <= 9;i++)
        if (i != k && SuDoKu_Judge(arr, n, m, i)==OK)//判断填入的数是否符合数独规则
        {
            arr[n][m] = i;
            if (resolve_sudoku(arr, H, F) == OK)//判断是否有唯一解
            {
                arr[n][m] = k;
                hole[n][m] = 1;
                return FALSE;
            }
            arr[n][m] = k;
        }
    arr[n][m] = 0;
    hole[n][m] = 1;
    return OK;
}*/
//挖洞法主函数
/*
status Dig_Hole(int arr[][9],int n, int m, int k, headnode H, bignode  F)
{
    counnt--;
    int next_hole=0,sig=4;
    if (counnt == 0) return OK;
    else
    {
        if (Juge_Hole(arr, n-1, m-1, k,H,F) == FALSE )//判断传入的是否有其他解
        {//没解复原
            arr[n-1][m-1] = k;
            hole[n-1][m-1] = 1;
            counnt++;
            return FALSE;
        }
        else
        {
            next_hole = Delete_Num(arr);//找到下一个要删除的数
            if (next_hole == 0)return OK;
            if (Dig_Hole(arr, next_hole / 100, (next_hole / 10) % 10, next_hole % 10, H, F) == OK)
                return OK;
            else
            {
                while (sig--)
                {
                    next_hole = Delete_Num(arr);//找到下一个要删除的数
                    if (next_hole == 0)return OK;
                    if (Dig_Hole(arr, next_hole / 100, (next_hole / 10) % 10, next_hole % 10, H, F) == OK)
                        return OK;
                    else return FALSE;
                }
                return FALSE;
            }
        }
    }
    
}
*/
//调用dpll判断是否有解
/*status resolve_sudoku(int arr[][9], headnode H, bignode  F)
{
    int c[9][9];
    for (int i = 0; i < 9; i++)//初始化
        for (int j = 0; j < 9; j++)
            c[i][j] = 0;
    for (int i = 0; i < 9; i++)//复制
        for (int j = 0; j < 9; j++)
            c[i][j] = arr[i][j];
    
    Tranlate(c, &H, F);
    for (int i = 1; i < variable + 1; i++)
        mark_ture[i] = 0;
    FLAG = 2;
    if (Dpll_youhua(H, 1, F) == OK) return OK;
    else return FALSE;
}*/



#endif 