#include <bits/stdc++.h>
#ifndef SuduKu_h
#define SuduKu_h
#include "File.h"
#include "DPLL.h"
#include "SuDuKu1.h"
using namespace std;

//                    数独函数部分

//输出数独棋盘
void Print_SuDoKu(int arr[][9]);
//匹配棋盘
void ShuChu_match(int shuzu[][9]);
//调用读取函数
status Read_SuDoKu(headnode *Head, bignode  G, int mid);
//读入邻接表之初始化邻接表操作
status Isinit_SuDoKu(headnode *Head, bignode G);
//数独之判断填入的数字是否正确
status SuDoKu_Judge(int arr[][9], int row, int col, int n);
//匹配函数
void Match(int arr[9][9], int a[][10][10]);
//每空取值组合
void  Create_Cnf_Position(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每行取值组合
void  Create_Cnf_Row(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每列取值组合
void Create_Cnf_Col(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每小方块取值组合
void Create_Cnf_Block(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每空取值保证
void Insure_Cnf_Position(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每行取值保证
void  Insure_Cnf_Row(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每列取值保证
void  Insure_Cnf_Col(int arr[][9], int a[][10][10], headnode *H, bignode G);
//每小方块取值保证
void  Insure_Cnf_Block(int arr[][9], int a[][10][10], headnode *H, bignode G);
//数独转换成函数
status Tranlate(int arr[9][9], headnode *H, bignode  F);
//调用数独的函数
string  Create_sudoku(headnode *H, bignode  F, int arr1[9][9], int arr2[9][9]);


//数独函数部分

//输出数独棋盘
void Print_SuDoKu(int arr[][9])
{
    int i, j;
    printf("-------------------------------\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (j % 3 == 0) printf("|");
            if (arr[i][j] != 0) printf("%2d ", arr[i][j]);
            else printf(" _ ");
            if (j == 8) printf("|\n");
        }
        if ((i + 1) % 3 == 0) printf("-------------------------------\n");
    }
}
//调用读取函数
status Read_SuDoKu(headnode *Head, bignode  G, int mid)
{
    //读取公式部分
    EdgeNode *p = NULL, *t = NULL;
    HeadNode *r = NULL, *q = NULL;
    SerchNode *n = NULL, *x = NULL;
    q = *Head;
    while (q->next)
    {
        q = q->next;
    }
    if (mid != 0)
    {
        //读入变元
        p = (EdgeNode*)malloc(sizeof(EdgeNode));
        p->next = NULL;
        p->num = mid;
        p->mark = 1;
        if (q->inside == NULL)  q->inside = p;
        else
        {
            t = q->inside;
            while (t->next)
                t = t->next;
            t->next = p;
        }
        q->count++;
        
        //索引表的建立
        n = (SerchNode*)malloc(sizeof(SerchNode));
        if (mid > 0)
        {
            n->zheng_mark = 1;
            n->inside_zheng = p;
            n->outside_zheng = q;
            n->inside_fu = NULL;
            n->outside_fu = NULL;
            n->fu_mark = 0;
            n->next = NULL;
            x = G->serchlist[mid].next;
            if (!x) G->serchlist[mid].next = n;
            else
            {
                while (x->next)
                    x = x->next;
                x->next = n;
            }
        }
        else
        {
            n->zheng_mark = 0;
            n->next = NULL;
            n->inside_zheng = NULL;
            n->outside_zheng = NULL;
            n->inside_fu = p;
            n->outside_fu = q;
            n->fu_mark = 1;
            x = G->serchlist[-mid].next;
            if (!x) G->serchlist[-mid].next = n;
            else
            {
                while (x->next)
                    x = x->next;
                x->next = n;
            }
        }
    }
    else
    {
        //读入下一个公式
        r = (HeadNode*)malloc(sizeof(HeadNode));
        r->next = NULL;
        r->inside = NULL;
        r->count = 0;
        r->mark = 0;
        r->flag = 0;
        if (q->inside != NULL) q->mark = 1;
        q->next = r;
        q = r;
    }
    return OK;
}
//读入邻接表之初始化邻接表操作
status Isinit_SuDoKu(headnode *Head, bignode G)
{
    HeadNode *r = NULL, *q = NULL;
    //初始化索引表
    for (int i = 1; i < N; i++)
    {
        G->mark = 0;
        G->serchlist[i].fu_mark = 0;
        G->serchlist[i].zheng_mark = 0;
        G->serchlist[i].inside_fu = NULL;
        G->serchlist[i].inside_zheng = NULL;
        G->serchlist[i].next = NULL;
        G->serchlist[i].outside_fu = NULL;
        G->serchlist[i].outside_zheng = NULL;
    }
    //初始化存储表
    r = (HeadNode*)malloc(sizeof(HeadNode));
    q = r;
    (*Head) = r;
    r->next = NULL;
    r->inside = NULL;
    r->count = 0;
    r->mark = 0;
    r->flag = 0;
    return OK;
}
//数独之判断填入的数字是否正确
status SuDoKu_Judge(int arr[][9], int row, int col, int n)       //传入的n是拟填入的数，row是行，col是列
{
    int i, j;
    
    for (i = 0; i < 9; i++) {// 判断行重复
        if (arr[row][i] == n) {
            return FALSE;
        }
    }
    for (j = 0; j < 9; j++) {// 判断列重复
        if (arr[j][col] == n) {
            return FALSE;
        }
    }
    // 判断所在小九宫格重复
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for (i = x; i < x + 3; i++)
        for (j = y; j < y + 3; j++)
            if (arr[i][j] == n) return FALSE;
    
    return OK;
}             //函数返回OK代表此时这个数可以填，否则不能填

//匹配函数
void Match(int arr[9][9], int a[][10][10])
{
    int order = 1;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (SuDoKu_Judge(arr, i, j, k) == OK)
                    {
                        a[i + 1][j + 1][k] = order;
                        order++;
                    }
                }
            }
        }
    }
    variable = order - 1;
}
//每空取值组合
void  Create_Cnf_Position(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t;
    int part_1[10];
    for (int i = 1; i <= 9; i++)//初始化
        part_1[i] = 0;
    
    for (i = 0; i < 9; i++) //遍历数独列表
    {
        for (j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)//找到空格
            {
                for (k = 1; k <= 9; k++)//找出可能的取值
                    if (arr[i][j] == 0 && SuDoKu_Judge(arr, i, j, k) == OK)
                        part_1[k] = 1;
                //输出可能的两两取值
                for (k = 1; k <= 9; k++)
                    if (part_1[k] == 1)
                    {
                        for (t = k + 1; t <= 9; t++)
                        {
                            if (part_1[t] == 1)
                            {
                                Read_SuDoKu(H, G, -a[i + 1][j + 1][k]);
                                Read_SuDoKu(H, G, -a[i + 1][j + 1][t]);
                                Read_SuDoKu(H, G, 0);
                            }
                        }
                        part_1[k] = 0;
                    }
            }
        }
    }
}
//每行取值组合
void  Create_Cnf_Row(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t;
    int part_2[10], sign_2[10];
    for (int i = 1; i <= 9; i++)//初始化
    {
        part_2[i] = 0;
        sign_2[i] = 1;//记录每列还需要填的数
    }
    
    for (i = 0; i<9; i++) //遍历数独列表
    {
        for (j = 0; j < 9; j++)//找到可能要补的数
        {
            if (arr[i][j] != 0)
                sign_2[arr[i][j]] = 0;
        }
        for (t = 1; t <= 9; t++)//找到可能补数x的位置
        {
            if (sign_2[t] == 1)//需要补数t，查找可能补t的位置
            {
                for (k = 1; k <= 9; k++)
                    if (arr[i][k - 1] == 0 && SuDoKu_Judge(arr, i, k - 1, t) == OK)
                        part_2[k] = 1;
                for (k = 1; k <= 9; k++)//全部输出
                {
                    if (part_2[k] == 1)
                    {
                        for (int r = k + 1; r <= 9; r++)
                        {
                            if (part_2[r] == 1)
                            {
                                Read_SuDoKu(H, G, -a[i + 1][k][t]);
                                Read_SuDoKu(H, G, -a[i + 1][r][t]);
                                Read_SuDoKu(H, G, 0);
                            }
                        }
                        part_2[k] = 0;
                    }
                }
            }
            sign_2[t] = 1;
        }
    }
}
//每列取值组合
void Create_Cnf_Col(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t;
    int part_3[10], sign_3[10];
    for (int i = 1; i <= 9; i++)//初始化
    {
        part_3[i] = 0;
        sign_3[i] = 1;//记录每列还需要填的数
    }
    
    for (j = 0; j<9; j++) //遍历数独列表
    {
        for (i = 0; i < 9; i++)//找到可能要补的数
        {
            if (arr[i][j] != 0)
                sign_3[arr[i][j]] = 0;
        }
        for (t = 1; t <= 9; t++)//找到可能补数x的位置
        {
            if (sign_3[t] == 1)//需要补数t，查找可能补t的位置
            {
                for (k = 1; k <= 9; k++)//
                    if (arr[k - 1][j] == 0 && SuDoKu_Judge(arr, k - 1, j, t) == OK)
                        part_3[k] = 1;
                for (k = 1; k <= 9; k++)//全部输出
                {
                    if (part_3[k] == 1)
                    {
                        for (int r = k + 1; r <= 9; r++)
                        {
                            if (part_3[r] == 1)
                            {
                                Read_SuDoKu(H, G, -a[k][j + 1][t]);
                                Read_SuDoKu(H, G, -a[r][j + 1][t]);
                                Read_SuDoKu(H, G, 0);
                            }
                        }
                        part_3[k] = 0;
                    }
                }
            }
            sign_3[t] = 1;
        }
    }
}
//每小方块取值组合
void Create_Cnf_Block(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t, n;
    int part_4[10], sign_4[10];
    for (int i = 1; i <= 9; i++)//初始化
    {
        sign_4[i] = 1;//记录每个小方块还需要填的数
        part_4[i] = 0;//记录可以填的位置
    }
    
    for (i = 0; i < 9; i += 3)
    {
        for (j = 0; j < 9; j += 3)
        {
            for (k = i; k < i + 3; k++)//找到小方块中可能填充的数字
            {
                for (t = j; t < j + 3; t++)
                {
                    if (arr[k][t] != 0)
                        sign_4[arr[k][t]] = 0;
                }
            }
            for (n = 1; n <= 9; n++)
            {
                if (sign_4[n] == 1)//接下来找出可能填入k的位置
                {
                    for (k = i; k < i + 3; k++)//找到可能放入的位置
                    {
                        for (t = j; t < j + 3; t++)
                            if (arr[k][t] == 0 && SuDoKu_Judge(arr, k, t, n) == OK)
                            {
                                if (k % 3 == 0) part_4[(t % 3) + 1] = 1;
                                else if (k % 3 == 1)part_4[4 + (t % 3)] = 1;
                                else part_4[7 + (t % 3)] = 1;
                            }
                    }
                    for (k = 1; k <= 9; k++)//全部输出
                        if (part_4[k] == 1)
                        {
                            for (t = k + 1; t <= 9; t++)
                                if (part_4[t] == 1)
                                {
                                    if (k >= 1 && k <= 3)
                                        Read_SuDoKu(H, G, -a[i + 1][j + k][n]);
                                    else if (k >= 4 && k <= 6)
                                        Read_SuDoKu(H, G, -a[i + 2][j + k - 3][n]);
                                    else
                                        Read_SuDoKu(H, G, -a[i + 3][j + k - 6][n]);
                                    
                                    if (t >= 1 && t <= 3)
                                        Read_SuDoKu(H, G, -a[i + 1][j + t][n]);
                                    else if (t >= 4 && t <= 6)
                                        Read_SuDoKu(H, G, -a[i + 2][j + t - 3][n]);
                                    else
                                        Read_SuDoKu(H, G, -a[i + 3][j + t - 6][n]);
                                    Read_SuDoKu(H, G, 0);
                                }
                            part_4[k] = 0;
                        }
                }
                sign_4[n] = 1;
            }
        }
    }
}
//每空取值保证
void Insure_Cnf_Position(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k;
    int part_5[10];
    for (int i = 1; i <= 9; i++)//初始化
        part_5[i] = 0;
    
    for (i = 0; i < 9; i++) //遍历数独列表
    {
        for (j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)//找到空格
            {
                for (k = 1; k <= 9; k++)//找出可能的取值
                    if (arr[i][j] == 0 && SuDoKu_Judge(arr, i, j, k) == OK)
                        part_5[k] = 1;
                //输出可能的取值
                for (k = 1; k <= 9; k++)
                {
                    if (part_5[k] == 1)
                    {
                        Read_SuDoKu(H, G, a[i + 1][j + 1][k]);
                    }
                    part_5[k] = 0;
                }
                Read_SuDoKu(H, G, 0);
            }
        }
    }
}
//每行取值保证
void  Insure_Cnf_Row(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t;
    int part_6[10], sign_6[10];
    for (int i = 1; i <= 9; i++)//初始化
    {
        part_6[i] = 0;
        sign_6[i] = 1;//记录每列还需要填的数
    }
    
    for (i = 0; i<9; i++) //遍历数独列表
    {
        for (j = 0; j < 9; j++)//找到可能要补的数
        {
            if (arr[i][j] != 0)
                sign_6[arr[i][j]] = 0;
        }
        for (t = 1; t <= 9; t++)//找到可能补数x的位置
        {
            if (sign_6[t] == 1)//需要补数t，查找可能补t的位置
            {
                for (k = 1; k <= 9; k++)
                    if (arr[i][k - 1] == 0 && SuDoKu_Judge(arr, i, k - 1, t) == OK)
                        part_6[k] = 1;
                for (k = 1; k <= 9; k++)//全部输出
                {
                    if (part_6[k] == 1)
                    {
                        Read_SuDoKu(H, G, a[i + 1][k][t]);
                    }
                    part_6[k] = 0;
                }
                Read_SuDoKu(H, G, 0);
            }
            sign_6[t] = 1;
        }
    }
}

//每列取值保证
void  Insure_Cnf_Col(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t;
    int part_7[10], sign_7[10];
    for (int i = 1; i <= 9; i++)//初始化
    {
        part_7[i] = 0;
        sign_7[i] = 1;//记录每列还需要填的数
    }
    
    for (j = 0; j < 9; j++) //遍历数独列表
    {
        for (i = 0; i < 9; i++)//找到可能要补的数
        {
            if (arr[i][j] != 0)
                sign_7[arr[i][j]] = 0;
        }
        for (t = 1; t <= 9; t++)//找到可能补数x的位置
        {
            if (sign_7[t] == 1)//需要补数t，查找可能补t的位置
            {
                for (k = 1; k <= 9; k++)
                    if (arr[k - 1][j] == 0 && SuDoKu_Judge(arr, k - 1, j, t) == OK)
                        part_7[k] = 1;
                for (k = 1; k <= 9; k++)
                {
                    if (part_7[k] == 1)
                    {
                        Read_SuDoKu(H, G, a[k][j + 1][t]);
                    }
                    part_7[k] = 0;
                }
                Read_SuDoKu(H, G, 0);
            }
            sign_7[t] = 1;
        }
    }
}

//每小方块取值保证
void  Insure_Cnf_Block(int arr[][9], int a[][10][10], headnode *H, bignode G)
{
    int i, j, k, t, n;
    int part_8[10][10], sign_8[10];
    for (int i = 1; i <= 9; i++)//初始化
        sign_8[i] = 1;//记录每个小方块还需要填的数
    
    for (i = 0; i < 9; i++)//初始化
        for (j = 0; j < 9; j++)
            part_8[i][j] = 0;
    
    for (i = 0; i < 9; i += 3)
        for (j = 0; j < 9; j += 3)
        {
            for (k = i; k < i + 3; k++)//找到小方块中可能填充的数字
            {
                for (t = j; t < j + 3; t++)
                {
                    if (arr[k][t] != 0)
                        sign_8[arr[k][t]] = 0;
                }
            }
            for (n = 1; n <= 9; n++)
            {
                if (sign_8[n] == 1)//接下来找出可能填入k的位置
                {
                    for (k = i; k < i + 3; k++)//找到可能放入的位置
                    {
                        for (t = j; t < j + 3; t++)
                        {
                            if (arr[k][t] == 0 && SuDoKu_Judge(arr, k, t, n) == OK)
                                part_8[k][t] = 1;
                        }
                    }
                    for (k = i; k < i + 3; k++)//全部输出
                    {
                        for (t = j; t < j + 3; t++)
                        {
                            if (part_8[k][t] == 1)
                            {
                                Read_SuDoKu(H, G, a[k + 1][t + 1][n]);
                            }
                            part_8[k][t] = 0;
                        }
                    }
                    Read_SuDoKu(H, G, 0);
                }
                sign_8[n] = 1;
            }
        }
}

//填充双数独
string Tranlateshuang(int arr1[][9], int arr2[][9], headnode *H, bignode F)    //传入的是两个二维数组，
{
    ofstream shuangfp;
    printf("请输入文件名作为双数独模型的cnf文件！\n");
    string filename;
    cin >> filename;       //自定义一个双数独的cnf文件
    shuangfp.open(filename,ios::trunc);
    int base=24138;        //基础个数
    int extra=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr1[i][j]!=0) extra++;
            if(arr2[i][j]!=0) extra++;
        }
    }
    shuangfp << "p cnf " << 2000 << ' ' << base+extra << endl;
    //单子句部分 
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr1[i][j]!=0)
            {
                shuangfp << (i+1)*100+(j+1)*10+arr1[i][j] << ' ' << 0 << endl;
            }
            if(arr2[i][j]!=0)
            {
                shuangfp << 1000+(i+1)*100+(j+1)*10+arr2[i][j] << ' ' << 0 << endl;
            }
        }
    }
    //单元格部分 162*37
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            //第一部分
            for(int k=1;k<=9;k++)
            {
                shuangfp << i*100+j*10+k << ' ';
            }
            shuangfp << 0 << endl;
            for(int k=1;k<=8;k++)
            {
                for(int kk=k+1;kk<=9;kk++)       //总共36个
                {
                    shuangfp << -(i*100+j*10+k) << " " << -(i*100+j*10+kk) << " " << 0 <<endl;
                }
            }
            //第二部分
            for(int k=1;k<=9;k++)
            {
                shuangfp << 1000+i*100+j*10+k << ' ';
            }
            shuangfp << 0 << endl;
            for(int k=1;k<=8;k++)
            {
                for(int kk=k+1;kk<=9;kk++)       //总共36个
                {
                    shuangfp << -(1000+i*100+j*10+k) << " " << -(1000+i*100+j*10+kk) << " " << 0 <<endl;
                }
            }
        }
    }
    //行约束部分
    for(int i=1;i<=9;i++)  //第i行
    {
        for(int j=1;j<=9;j++) //数字
        {
            for(int k=1;k<=9;k++)   //列数
            {
                shuangfp << i*100+k*10+j << " ";
            }
            shuangfp << 0 <<endl;
        }
        for(int j=1;j<=9;j++)      //不同时为j
        {
            for(int k=1;k<=8;k++)
            {
                for(int kk=k+1;kk<=9;kk++)
                shuangfp << -(i*100+k*10+j) << " " << -(i*100+kk*10+j) << " " << 0 << endl;
            }
        }
        for(int j=1;j<=9;j++) //数字
        {
            for(int k=1;k<=9;k++)   //列数
            {
                shuangfp << 1000+i*100+k*10+j << " ";
            }
            shuangfp << 0 <<endl;
        }
        for(int j=1;j<=9;j++)      //不同时为j
        {
            for(int k=1;k<=8;k++)
            {
                for(int kk=k+1;kk<=9;kk++)
                shuangfp << -(1000+i*100+k*10+j) << " " << -(1000+i*100+kk*10+j) << " " << 0 << endl;
            }
        }
    }
    //列约束部分
    for(int i=1;i<=9;i++)  //第i列
    {
        for(int j=1;j<=9;j++) //数字
        {
            for(int k=1;k<=9;k++)   //行数
            {
                shuangfp << k*100+i*10+j << " ";
            }
            shuangfp << 0 <<endl;
        }
        for(int j=1;j<=9;j++)      //不同时为j
        {
            for(int k=1;k<=8;k++)
            {
                for(int kk=k+1;kk<=9;kk++)
                shuangfp << -(k*100+i*10+j) << " " << -(kk*100+i*10+j) << " " << 0 << endl;
            }
        }
        for(int j=1;j<=9;j++) //数字
        {
            for(int k=1;k<=9;k++)   //行数
            {
                shuangfp << 1000+k*100+i*10+j << " ";
            }
            shuangfp << 0 <<endl;
        }
        for(int j=1;j<=9;j++)      //不同时为j
        {
            for(int k=1;k<=8;k++)
            {
                for(int kk=k+1;kk<=9;kk++)
                shuangfp << -(1000+k*100+i*10+j) << " " << -(1000+kk*100+i*10+j) << " " << 0 << endl;
            }
        }
    }
    //单元格部分
    for(int i=1;i<=9;i+=3)         //第i个九宫格的第一行
    {
        for(int j=1;j<=9;j+=3)    //第j个九宫格的第一列
        {
            for(int k=1;k<=9;k++)  //k是数
            {
                for(int ii=i;ii<=i+2;ii++)
                {
                    for(int jj=j;jj<=j+2;jj++)
                    {
                        shuangfp << ii*100+jj*10+k << " ";
                    }
                }
                shuangfp << 0 << endl;
            }
            for(int n=1;n<=9;n++)       //数      
            {
                for(int jj=j;jj<=j+2;jj++)    //去分析每一列的第一个的比较状况
                {
                    shuangfp << -(i*100+j*10+n) << " " << -(i*100+j*10+n+100) << " " << 0 << endl;
                    shuangfp << -(i*100+j*10+n) << " " << -(i*100+j*10+n+200) << n << " " << 0 << endl;
                    for(int k=jj+1;k<=j+2;k++)
                    {
                        shuangfp << -i << j << n << " " << -i << k << n << " " << 0 << endl;
                        shuangfp << -i << j << n << " " << -(i+1) << k << n << " " << 0 << endl;
                        shuangfp << -i << j << n << " " << -(i+2) << k << n << " " << 0 << endl;
                    }
                }
                for(int jj=j;jj<=j+2;jj++)    //去分析每一列的第二个的比较状况
                {
                    shuangfp << -(i+1) << j << n << " " << -(i+2) << j << n << " " << 0 << endl;
                    for(int k=jj+1;k<=j+2;k++)
                    {
                        shuangfp << -(i+1) << j << n << " " << -i << k << n << " " << 0 << endl;
                        shuangfp << -(i+1) << j << n << " " << -(i+1) << k << n << " " << 0 << endl;
                        shuangfp << -(i+1) << j << n << " " << -(i+2) << k << n << " " << 0 << endl;
                    }
                }
                for(int jj=j;jj<=j+2;jj++)    //去分析每一列的第三个的比较状况
                {
                    for(int k=jj+1;k<=j+2;k++)
                    {
                        shuangfp << -(i+2) << j << n << " " << -i << k << n << " " << 0 << endl;
                        shuangfp << -(i+2) << j << n << " " << -(i+1) << k << n << " " << 0 << endl;
                        shuangfp << -(i+2) << j << n << " " << -(i+2) << k << n << " " << 0 << endl;
                    }
                }
            }
            for(int k=1;k<=9;k++)  //k是数
            {
                for(int ii=i;ii<=i+2;ii++)
                {
                    for(int jj=j;jj<=j+2;jj++)
                    {
                        shuangfp << 1000+ii*100+jj*10+k << " ";
                    }
                }
                shuangfp << 0 << endl;
            }
            for(int n=1;n<=9;n++)       //数      
            {
                for(int jj=j;jj<=j+2;jj++)    //去分析每一列的第一个的比较状况
                {
                    shuangfp << -1 << i << j << n << " " << -1 << i+1 << j << n << " " << 0 << endl;
                    shuangfp << -1 << i << j << n << " " << -1 << i+2 << j << n << " " << 0 << endl;
                    for(int k=jj+1;k<=j+2;k++)
                    {
                        shuangfp << -1 << i << j << n << " " << -1 << i << k << n << " " << 0 << endl;
                        shuangfp << -1 << i << j << n << " " << -1 << i+1 << k << n << " " << 0 << endl;
                        shuangfp << -1 << i << j << n << " " << -1 << i+2 << k << n << " " << 0 << endl;
                    }
                }
                for(int jj=j;jj<=j+2;jj++)    //去分析每一列的第二个的比较状况
                {
                    shuangfp << -1 << i+1 << j << n << " " << -1 << i+2 << j << n << " " << 0 << endl;
                    for(int k=jj+1;k<=j+2;k++)
                    {
                        shuangfp << -1 << i+1 << j << n << " " << -1 << i << k << n << " " << 0 << endl;
                        shuangfp << -1 << i+1 << j << n << " " << -1 << i+1 << k << n << " " << 0 << endl;
                        shuangfp << -1 << i+1 << j << n << " " << -1 << i+2 << k << n << " " << 0 << endl;
                    }
                }
                for(int jj=j;jj<=j+2;jj++)    //去分析每一列的第三个的比较状况
                {
                    for(int k=jj+1;k<=j+2;k++)
                    {
                        shuangfp << -1 << i+2 << j << n << " " << -1 << i << k << n << " " << 0 << endl;
                        shuangfp << -1 << i+2 << j << n << " " << -1 << i+1 << k << n << " " << 0 << endl;
                        shuangfp << -1 << i+2 << j << n << " " << -1 << i+2 << k << n << " " << 0 << endl;
                    }
                }
            }
        }
    }
    //关联部分
    for(int i=7;i<=9;i++)
    {
        for(int j=7;j<=9;j++)        
        {
            for(int k=1;k<=9;k++)
            {
                shuangfp << -(i*100+j*10+k) << " " << 1000+(i-6)*100+(j-6)*10+k << " " << 0 << endl;
                shuangfp << i*100+j*10+k << " " << -(1000+(i-6)*100+(j-6)*10+k) << " " << 0 << endl;
            }
        }
    }
    shuangfp << 0 << endl;
    shuangfp.close();
    return filename;
}

//数独转换成函数
status Tranlate(int arr[][9], headnode *H, bignode  F)
{
    int a[10][10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                a[i][j][k] = 0;
    Match(arr, a);
    Isinit_SuDoKu(H, F);
    Create_Cnf_Position(arr, a, H, F);
    Create_Cnf_Row(arr, a, H, F);
    Create_Cnf_Col(arr, a, H, F);
    Create_Cnf_Block(arr, a, H, F);
    Insure_Cnf_Position(arr, a, H, F);
    Insure_Cnf_Row(arr, a, H, F);
    Insure_Cnf_Col(arr, a, H, F);
    Insure_Cnf_Block(arr, a, H, F);
    return 1;
}
//调用数独的函数
string  Create_sudoku(headnode *H, bignode  F, int arr1[9][9], int arr2[9][9])   //arr是一个棋盘，需要传入恋歌棋盘arr1，arr2.
{
    int n, m, k, count = 0;
    srand((int)time(0));
    printf("正在创建数独棋盘！\n");
    while (count <= 17)
    {
        
        n = rand() % 9;      //0-8
        m = rand() % 9;      //0-8
        k = (rand() % 9) + 1;    //1-9
        if (arr1[n][m] == 0 && SuDoKu_Judge(arr1, n, m, k) == OK) //随机填入第一个内，填17个
        {
            count++;
            arr1[n][m] = k;
        }         //随机生成17个数，生成时满足合法
    }
    count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr2[i][j] = arr1[i+6][j+6];         //把重叠的格子赋值
        }
    }
    while (count <= 17)
    {
        
        n = rand() % 9;      //0-8
        m = rand() % 9;      //0-8
        k = (rand() % 9) + 1;    //1-9
        if (arr2[n][m] == 0 && SuDoKu_Judge(arr2, n, m, k) == OK) //随机填入第一个内，填17个
        {
            count++;
            arr2[n][m] = k;
        }         //随机生成17个数，生成时满足合法
    }
    Print_SuDoKu(arr1);
    printf("\n");
    Print_SuDoKu(arr2);
    string fanhui;
    fanhui=Tranlateshuang(arr1,arr2, H, F);   //生成完整的合法填充
    //Tranlate(arr, H, F);
    return fanhui;
}

/*判断洞是否可以挖
status  Juge_Hole(int arr[][9], int n, int m, int k,headnode H, bignode  F)
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

//调用dpll判断是否有解
status resolve_sudoku(int arr[][9], headnode H, bignode  F)
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
}

//形成完整合法填充
void fillblanks()           //
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(shuzu1[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(pipei[(i+1)*100+(j+1)*10+k]==1)
                    shuzu1[i][j]=k;
                }
            }
            if(shuzu2[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(pipei[1000+(i+1)*100+(j+1)*10+k]==1)
                    shuzu2[i][j]=k;
                }
            }
        }
    }
    return ;
}

#endif 