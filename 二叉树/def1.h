#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

	typedef int status;
	typedef int KeyType; 
	typedef struct {
         KeyType  key;
         char others[20];
	} TElemType; //二叉树结点类型定义

	typedef struct BiTNode{  //二叉链表结点的定义
	      TElemType  data;
	      struct BiTNode *lchild,*rchild;
	} BiTNode, *BiTree;

int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}

typedef struct{  //二叉树的管理表定义
     struct { char name[30];
     		  BiTree T;	
      } elem[10];
      int length;
      int listsize=50;
 }BITREES;
 
 typedef struct {
    int pos;
    TElemType data;
} DEF;



