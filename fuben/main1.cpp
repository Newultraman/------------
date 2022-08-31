
#include <bits/stdc++.h>
#include "File.h"
#include "ShuDuKu1.h"
#include "DPLL.h"
#include "SuDuKu1.h"
using namespace std;

//主函数部分
int main(void)
{
    int fuben[9][9];
    for (int i = 0; i < 9; i++)//初始化数独棋盘以及其副本
        for (int j = 0; j < 9; j++)
        {
            shuzu1[i][j] = 0;
            shuzu2[i][j] = 0;
        }
    headnode T;
    HeadNode ARR;
    T = &ARR;
    BigNode arr;
    bignode G;
    G = &arr;
    FILE  *fp;//文件指针
    char filename[70],filename_fuben[70],name[20];
    int op = 1,Selet_Sudoku = 1,Selet_Sat=1;
    clock_t t1, t2,t3 = 0;
    int  isinit = 0, flag = 0, Flag = 0,sign=0,sigg=1;
    string samename;
    string cnfname;
    int pipeishu;
    int num_of_hole=0;
    int holeposition=0;
    int ge,shi,bai;
    int holenum;
    int tianshu;
    while (op) {
        printf("\n               Menu for SuDoku or SAT              \n");
        printf("------------------------------------------------------\n");
        printf("            1.SAT                  2.SuDoKu           \n");
        printf("            0.Exit                                    \n");
        printf("------------------------------------------------------\n");
        if (scanf("%d", &op))
        {
            switch (op) {
                case 1:
                    while (Selet_Sat) {
                        printf("\n              SAT菜单                \n");
                        printf("-------------------------------------------\n");
                        printf("     1.读取文件           2.遍历文件  \n");
                        printf("     3.存储文件           4.使用DPLL   \n");
                        printf("     0.退出                                   \n");
                        printf("--------------------------------------------\n");
                        if (scanf("%d", &Selet_Sat))
                            switch (Selet_Sat) {
                                case 1:
                                    printf("input file name: ");
                                    scanf("%s", filename);
                                    strcpy(filename_fuben, filename);//保存副本
                                    if(isinit == 1)Realse_Link(&T);
                                    if (ReadFile(&T, G, filename) == OK)
                                    {
                                        isinit = 1;
                                        printf("cnf文件读取成功！\n");
                                    }
                                    else printf("cnf文件读取失败！\n");
                                    getchar(); getchar();
                                    break;
                                case 2:
                                    if (isinit == 1)
                                    {
                                        Traverse(T);
                                        printf("cnf文件输出成功！\n");
                                    }
                                    else printf("cnf文件输出失败！\n");
                                    getchar(); getchar();
                                    break;
                                case 3:
                                    if (isinit == 1)
                                    {
                                        if (Save_File(T) == OK)
                                            printf("保存为cnf文件成功！\n");
                                        else printf("保存为cnf文件失败！\n");
                                    }
                                    else printf("保存为cnf文件失败！\n");
                                    getchar(); getchar();
                                    break;
                                case 4:
                                    if (isinit == 1)
                                    {
                                        for (int i = 1; i < variable + 1; i++)
                                            mark_ture[i] = 0;
                                        printf("请选择你需要的策略：\n");
                                        printf("1：选择出现次数多！   2:暴力求解!\n");
                                        scanf("%d", &Flag);
                                        if (Flag == 1)//选择策略
                                        {
                                            FLAG = 1;
                                            Strategy(T, mark_1, mark_2);
                                            t1 = clock();
                                            flag = Dpll_youhua(T, 1, G);
                                            t2 = clock();
                                            t3 = (int)((t2 - t1)*1000/CLOCKS_PER_SEC);
                                            printf("时间：%4d ms\n", t3);
                                            
                                        }
                                        else if (Flag == 2)
                                        {
                                            FLAG = 2;
                                            t1 = clock();
                                            flag = Dpll_youhua(T, 1, G);
                                            t2 = clock();
                                            t3 = (int)((t2 - t1)*1000/CLOCKS_PER_SEC);
                                            printf("时间：%4d ms\n\n", t3);
                                        }
                                        if (flag == 1)
                                        {
                                            for (int i = 0; i < 70; i++)
                                            {
                                                if (filename_fuben[i] == '.')
                                                {
                                                    filename_fuben[i + 1] = 'r';
                                                    filename_fuben[i + 2] = 'e';
                                                    filename_fuben[i + 3] = 's';
                                                    break;
                                                }
                                            }
                                            fp = fopen(filename_fuben, "wb");
                                            fprintf(fp, "%d\n", 1);
                                            printf("cnf文件的解为：\n");
                                            //printf("%d\n",variable);
                                            for(int i = 1; i < variable+1; i++)
                                            {
                                                if(mark_ture[i] == 0) mark_ture[i] = 1;
                                            }
                                            fprintf(fp,"%s ", "answer:");
                                            for (int i = 1; i < variable + 1; i++)
                                            {
                                                if (mark_ture[i] == 1)
                                                {
                                                    fprintf(fp, "%d  ", i);
                                                    printf("%6d", i);
                                                }
                                                else if (mark_ture[i] == -1)
                                                {
                                                    fprintf(fp, "%d  ", -i);
                                                    printf("%6d", -i);
                                                }
                                                if (i % 10 == 0) printf("\n");
                                            }
                                            fprintf(fp, "\n%s ", "time:");
                                            fprintf(fp, "%d\n", t3);
                                            printf("\ncnf的解输出成功！\n");
                                            fclose(fp);
                                        }
                                        else
                                        {
                                            for (int i = 0; i < 70; i++)
                                            {
                                                if (filename_fuben[i] == '.')
                                                {
                                                    filename_fuben[i + 1] = 'r';
                                                    filename_fuben[i + 2] = 'e';
                                                    filename_fuben[i + 3] = 's';
                                                    break;
                                                }
                                            }
                                            fp = fopen(filename_fuben, "wb");
                                            fprintf(fp, "%d\n", 0);
                                            fprintf(fp, "%s ", "time:");
                                            fprintf(fp, "%d\n", t3);
                                            fclose(fp);
                                            printf("dpll算法处理失败，cnf文件无解！\n");
                                        }
                                        flag = 0;
                                        isinit = 0;
                                    }
                                    else printf("操作失败！\n");
                                    getchar(); getchar();
                                    break;
                                case 0:
                                    break;
                                default:
                                    printf("输入错误！\n");
                                    getchar(); getchar();
                                    break;
                            }
                    }
                    getchar(); getchar();
                    break;
                case 2:
                    while (Selet_Sudoku)
                    {
                        printf("\n              数独菜单                \n");
                        printf("-------------------------------------------\n");
                        printf("     1.生成完整棋盘    2.根据玩家选择挖洞    \n");
                        printf("     3.玩游戏       0.退出  \n");
                        printf("-------------------------------------------\n");
                        ifstream ressname;
                        if (scanf("%d", &Selet_Sudoku))
                            switch (Selet_Sudoku) {
                                case 1:{
                                    //ifstream ressname;
                                    int Yes_or_no = 0;
                                    //string samename;
                                    do
                                    {
                                        //string cnfname;
                                        for(int i=0;i<9;i++)        //初始化数组
                                        {
                                            for(int j=0;j<9;j++)
                                            {
                                                shuzu1[i][j]=0;
                                                shuzu2[i][j]=0;
                                            }
                                        }
                                        cnfname = Create_sudoku(&T,G,shuzu1,shuzu2);   //生成一个cnf文件
                                        cout << cnfname << endl;
                                        //char name[20];
                                        strcpy(name,cnfname.c_str());
                                        if (ReadFile(&T, G, name) == OK)           //读取文件
                                        {
                                            isinit = 1;
                                            printf("cnf文件读取成功！\n");
                                        }
                                        else printf("cnf文件读取失败！\n");
                                        Strategy(T, mark_1, mark_2);
                                        Dpll_youhua(T, 1, G);          //会输出一个同名文件
                                        cin >> samename;      //手动输入同名文件
                                        ressname.open(samename,ios::in);
                                        ressname >> Yes_or_no;         //判断是不是可解
                                    }while(Yes_or_no==0);  //发现成功为止
                                    memset(pipei,0,sizeof(int)*2001);     //重置匹配数组
                                    //int pipeishu;
                                    ressname >> samename;                  //吞掉answer
                                    for(int i=1;i<=2000;i++)
                                    {
                                        ressname >> pipeishu;
                                        if(pipeishu>0) pipei[i]=1;   //0代表没有，1代表有
                                    }
                                    //ressname.close();
                                    fillblanks();  //完整填充
                                    getchar();
                                    getchar();
                                    break;
                                }
                                case 2:
                                    //int num_of_hole=0;
                                    //int holeposition=0;
                                    //int ge,shi,bai;
                                    printf("请输入你要挖洞的数量！\n");
                                    printf("温馨提示：挖洞不要太多，会由于执行太久影响游戏体验。\n");
                                    cin >> num_of_hole;
                                    //printf("请选择挖洞具体位置，请输入对应数量的三位数，如115表示第一个棋盘的第一行第五个挖洞。\n");
                                    for(int i=0;i<num_of_hole;i++)
                                    {
                                        ge=rand()%9+1;
                                        shi=rand()%9+1;
                                        bai=rand()%2+1;
                                        holeposition=bai*100+shi*10+ge;
                                        if(holeposition<200)
                                        {
                                            if(holeposition%10 >= 7&&(holeposition/10)%10 >= 7)
                                            {
                                                shuzu1[(holeposition/10)%10-1][holeposition%10-1]=0;
                                                shuzu2[(holeposition/10)%10-7][holeposition%10-7]=0;
                                            }
                                            else
                                            {
                                                shuzu1[(holeposition/10)%10-1][holeposition%10-1]=0;
                                            }   
                                        }
                                        else
                                        {
                                            shuzu2[(holeposition/10)%10-1][holeposition%10-1]=0;
                                        }
                                    }
                                    getchar();getchar();
                                    break;
                                case 3:
                                    holenum=0;
                                    //int tianshu;
                                    printf("您选择了玩游戏，正在为您展示格局！\n");
                                    printf("棋盘一：\n");
                                    for(int i=0;i<9;i++)
                                    {
                                        for(int j=0;j<9;j++)
                                        {
                                            if(!shuzu1[i][j]) holenum++;
                                            cout << shuzu1[i][j] << " ";
                                        }
                                        cout << " " << endl;
                                    }
                                    printf("棋盘二：\n");
                                    for(int i=0;i<9;i++)
                                    {
                                        for(int j=0;j<9;j++)
                                        {
                                            if(!shuzu2[i][j]) holenum++;
                                            cout << shuzu2[i][j] << " ";
                                        }
                                        cout << " " << endl;
                                    }
                                    printf("\n开玩吧！\n");
                                    printf("填入一个四位数，例如“1117”表示在第一个棋盘第一行第一列填入,注意如果重叠的部分需要两次输入！\n");
                                    for(int i=0;i<holenum;i++)
                                    {
                                        cin >> tianshu;
                                        tianshu=tianshu-1000;
                                        if(tianshu<1000)  //填在第一个 
                                        {
                                            if(pipei[tianshu]==1) {printf("好耶，填对了！\n");
                                            //shuzu1[tianshu/100-1][(tianshu/10)%10-1]=tianshu%10;
                                            }
                                            else printf("呜呜呜，没有填对，再来一次，不要放弃呀！\n");
                                        }
                                        else
                                        {
                                            if(pipei[tianshu]==1) {printf("好耶，填对了！\n");
                                            //shuzu2[(tianshu-1000)/100-1][((tianshu-1000)/10)%10-1]=tianshu%10;
                                            }
                                            else printf("呜呜呜，没有填对，再来一次，不要放弃呀！\n");
                                        }
                                    }
                                    printf("游戏完成！\n");
                                    fillblanks();
                                    printf("棋盘一：\n");
                                    for(int i=0;i<9;i++)
                                    {
                                        for(int j=0;j<9;j++)
                                        {
                                            cout << shuzu1[i][j] << " ";
                                        }
                                        cout << " " << endl;
                                    }
                                    printf("棋盘二：\n");
                                    for(int i=0;i<9;i++)
                                    {
                                        for(int j=0;j<9;j++)
                                        {
                                            cout << shuzu2[i][j] << " ";
                                        }
                                        cout << " " << endl;
                                    }
                    getchar(); getchar();
                    break;
                case 0:
                    break;
                default:
                    printf("输入错误！\n");
                    getchar(); getchar();
                    break;
            }
            ressname.close();
            }//end of while
            }//end of big switch
        }
        else
        {
            printf("输入错误！\n");
            getchar(); getchar(); getchar();
        }
    }//end of while
    printf("欢迎下次再使用本系统！\n");
    return 0;
}//end of main()