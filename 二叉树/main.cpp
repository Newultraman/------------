#include "BiTree.h"


status CreateBiTree(BiTree &T,DEF definition[])
//参数为 BiTree &T,DEF definition[]
//二叉树T不存在,根据definition建立一个二叉树. 
{
	if(T!=NULL) return ERROR; 
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	 p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   {
			   if(p[j/2]) p[j/2]->rchild=p[j];
			   else return ERROR;
						}
       	   else      {
			  if(p[j/2]) p[j/2]->lchild=p[j];
			  else return ERROR;
			}
       i++;
    }
    T=p[1];
    return OK;
}

status ClearBiTree(BiTree &T)
//参数为 BiTree &T
//将二叉树设置成空，并删除所有结点，释放结点空间
{
	BiTree p=NULL;
	if(set==0)
	{
		if(T==NULL) return ERROR;
		p=(BiTNode *)malloc(sizeof(BiTNode));
		p->data.key=0;
		p->rchild=NULL;
		p->lchild=NULL;
		set=1;
	}
	if(T==NULL) return OK;
    if(T!=NULL)
    {
        ClearBiTree(T->lchild);
        ClearBiTree(T->rchild);
    free(T);
    }
    T=p;
    return OK;
}

status AddBiTree(BITREES &BiTrees,char BiTreeName[],DEF definition[])
//参数为 BITREES &BiTrees,char BiTreename[],DEF definition[]
//增添一个二叉树 
{
	BiTrees.elem[BiTrees.length].T=NULL;
	int creat;
	creat=CreateBiTree(BiTrees.elem[BiTrees.length].T,definition);
	int i=0;
    while(BiTreeName[i]!='\0')
    {
    BiTrees.elem[BiTrees.length].name[i]=BiTreeName[i];
    i++;
    }
    BiTrees.elem[BiTrees.length].name[i]='\0';
    BiTrees.length++;
    if(creat==ERROR) return ERROR;
    return OK;
}

status RemoveBiTree(BITREES &BiTrees,char BiTreeName[])
//参数为BITREES &BiTrees,char BiTreeName[]
// BiTrees中删除一个名称为BiTreeName的二叉树 
{
    int i,num=BiTrees.length;
    for(i=0;i<BiTrees.length;i++)
    {
        int j=0;
        if(BiTrees.elem[i].name[j]==BiTreeName[j])
        { 
            int str=0;
            while(BiTreeName[str]!='\0') str++;
        while(BiTrees.elem[i].name[j]==BiTreeName[j])
            {
                if(j==str) break;
                j++;
            }
            if(j==str)
            {
            	DestroyBiTree(BiTrees.elem[i].T);
                for(int k=i;k<BiTrees.length-1;k++)
                {
                	BiTrees.elem[k]=BiTrees.elem[k+1];
                }
                BiTrees.elem[BiTrees.length-1].T=NULL;
                BiTrees.length--;
                i--;
            }
        }
    }
    if(num==BiTrees.length) return ERROR;
    else return OK;
}

status BiTreeDepth(BiTree T)
//参数为 BiTree T
//求二叉树T的深度
{
	 if(set==0)
   {
   	set=1;
   	if(T==NULL) return -1;
   	else if(!(T->data.key)) {return 0;}
   }
    if(T!=NULL)
    {
    return(max(BiTreeDepth(T->lchild),BiTreeDepth(T->rchild))+1);
    }
    else return 0;
}

void visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}

int main(void)
{
	BiTree T;
	T=NULL;
	BITREES BiTrees;
	BiTrees.length=0;
	int i=0;
	int e,LR,e1,e2,num,lo,rem,jia,dep,loa;
	TElemType value;
	char name[30];
	char Filename[30];
	int op=1;
	DEF definition[100];
	while(op)
	{
		system("cls");	printf("\n\n");
	printf("Menu for Linear Table On Sequence Structure \n");
	printf("--------------------------------------------\n");
	printf("    1. CreatBiTree(创建二叉树)7. Assign(结点赋值)\n");
	printf("  2. DestroyBiTree(销毁二叉树) 8. GetSibiling(获得兄弟结点)\n");
	printf("    3. ClearBiTree(清空二叉树)  9. InsertNode(插入结点) \n");
	printf("    4. BiTreeEmpty(二叉树判空)  10. DeleteNode(删除结点)\n");
	printf("    5. BiTreeLength(二叉树深度) 11. PreOrderTraverse(前序遍历)\n");
	printf("    6. LocateNode(查找结点)  12. InOrderTraverse(中序遍历)\n");
	printf("    13. PostOrderTraverse(后序遍历) 14. LevelOrderTraverse(按层遍历)\n");
	printf("附加功能:----------------------------------------\n");
	printf("多二叉树操作: 15. AddBiTree(增添二叉树)	16. RemoveBiTree(消除二叉树)\
	 17. LocateBiTree(定位二叉树) 18. WatchBiTree(总览)\n");
	printf("文件功能:  19. SaveBiTree(写入文件) 20. LoadBiTree(读取文件)\n"); 
	printf("  21. MaxPathSum(最大路径和) 22. LowestCommonAncestor(最近公共祖先)\
		23. InvertTree(翻转二叉树)\n");
	printf("");
	printf("    	      0. Exit\n");
	printf("--------------------------------------------\n");
	printf("    请选择你的操作[0~20]:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("请输入这个要建立的二叉树! \n");
			do {
		scanf("%d%d%s",&definition[i].pos,
		&definition[i].data.key,definition[i].data.others);
		} while (definition[i++].pos);
		if(definition[0].pos!=0)
		{
			if(CreateBiTree(T,definition)==OK) 
			printf("二叉树创建成功！\n");
		    else 
			printf("二叉树创建失败！\n");
		}
		else printf("二叉树创建失败！\n");
		i=0;
		 getchar();getchar();
		 break;
		case 2:
		printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
		 {
		 	if(DestroyBiTree(BiTrees.elem[num-1].T)==OK) 
			printf("二叉树销毁成功! \n");
		 	else
			printf("二叉树销毁失败! \n");
		 }
		 else printf("序号错误! \n");
		 set=0;i=0;
		 getchar();getchar();
		 break;
		 case 3:
	   	printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   	
		 if(ClearBiTree(BiTrees.elem[num-1].T)==OK) 
		 printf("二叉树清空成功! \n");
		 else 
		 printf("二叉树清空失败! \n");
		}
		else printf("序号错误! \n");
		set=0;i=0;
		 getchar();getchar();
		 break; 
		case 4:
	   	printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
		 if(BiTreeEmpty(BiTrees.elem[num-1].T)==TRUE) 
		 printf("二叉树为空! \n");
		 else if(BiTreeEmpty(BiTrees.elem[num-1].T)==FALSE) 
		 printf("二叉树不为空! \n");
		 else 
		 printf("二叉树判空失败! \n");
		}
		 else printf("序号错误! \n");
		 i=0;jishu=0;     
		 getchar();getchar();
		 break;
		 case 5:
	   	printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		dep=BiTreeDepth(BiTrees.elem[num-1].T);
		 if(dep==-1) 
		 printf("求深度失败! \n");
		 else 
		 printf("深度为  %d!\n",dep);
		}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar(); 
		 break;
		 case 6:
	   	printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   	printf("请输入你要查找的结点关键字,函数会返回该节点指针! \n");
	   	scanf("%d",&e);
		BiTNode *p=LocateNode(BiTrees.elem[num-1].T,e);
		if(p) 
		printf("%d,%s",p->data.key,p->data.others);
		else 
		printf("不存在此结点! \n");
		}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;      
		 getchar();getchar();
		 break;
		 case 7:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("请输入你要查找的关键字以及替换的值! \n");
	   		scanf("%d%d%s",&e,&value.key,value.others);
	   		int ass=Assign(BiTrees.elem[num-1].T,e,value);
			if(ass==OK) 
			printf("结点赋值成功! \n");
			else if(ass==ERROR) 
			printf("目标关键字有问题! \n");
			else 
			printf("赋值失败");
			memset(guanjianzi,0,sizeof(int)*100); 
	   	}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;     
		 getchar();getchar();
		 break;
		case 8:
		  printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("请输入要查找兄弟的结点的关键字! \n");
	   		scanf("%d",&e);
		BiTNode *p=GetSibling(BiTrees.elem[num-1].T,e);
		if(p) 
		printf("%d,%s",p->data.key,p->data.others);
		else 
		printf("无兄弟结点");
		memset(guanjianzi,0,sizeof(int)*100);	
	   	}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;     
		 getchar();getchar();
		 break;
		 case 9:
		printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("请输入要对应的关键字,插入方式,插入的结点! \n");
	   		scanf("%d%d%d%s",&e,&LR,&value.key,value.others);
			int in=InsertNode(BiTrees.elem[num-1].T,e,LR,value);
			if(in==OK) 
			printf("结点插入成功! \n");
			else if(in==ERROR) 
			printf("结点插入失败! \n");
			else 
			printf("不存在二叉树! \n");
			memset(guanjianzi,0,sizeof(int)*100); 
	   	}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;
		 memset(guanjianzi,0,sizeof(int)*100);    
		 getchar();getchar();
		 break;
		 case 10:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("请输入你要删除的结点的关键字! \n");
	   		scanf("%d",&e);
			int de=DeleteNode(BiTrees.elem[num-1].T,e);
			if(de==OK) 
			printf("删除成功! \n");
			else if(de==ERROR) 
			printf("删除失败! \n");
			else 
			printf("二叉树不存在! \n"); 
	   		}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;
		 memset(guanjianzi,0,sizeof(int)*100);    
		 getchar();getchar();
		 break;
		 case 11:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("先序遍历二叉树! \n");
			int pre=PreOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(pre==-1) 
			printf("不存在二叉树! \n");
			else if(pre==ERROR) 
			printf("二叉树为空! \n"); 
		 }
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 12:
		  printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("中序遍历二叉树! \n");
			int ino=InOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(ino==-1) 
			printf("不存在二叉树! \n");
			else if(ino==ERROR) 
			printf("二叉树为空! \n"); 
		 }
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 13:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("后序遍历二叉树! \n");
			int post=PostOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(post==-1) 
			printf("不存在二叉树! \n");
			else if(post==ERROR) 
			printf("二叉树为空! \n"); 
		 }
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 14:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("层序遍历二叉树! \n");
			int level=LevelOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(level==-1) 
			printf("不存在二叉树! \n");
			else if(level==ERROR) 
			printf("二叉树为空! \n"); 
		 }
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 15:
		 printf("请输入二叉树名字! \n");
			scanf("%s",name);
		printf("请输入这个要建立的二叉树! \n");
			do {
		scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,
		definition[i].data.others);
		} while (definition[i++].pos);
		if(definition[0].pos!=0)
		{ 
			jia=AddBiTree(BiTrees,name,definition);
			if(jia==OK) 
			printf("增添二叉树成功! \n");
			else 
			printf("二叉树创建失败！\n");
		}
		else printf("二叉树创建失败！\n");
		set=0;i=0;jishu=0; 
		getchar();getchar();
		break;
		case 16:
			printf("请输入二叉树名字! \n");
			scanf("%s",name);
			rem=RemoveBiTree(BiTrees,name);
			if(rem==OK) 
			printf("删除成功! \n");
			else 
			printf("删除失败! \n");
			i=0;jishu=0;
			getchar();getchar();
		break;
		case 17:
		printf("请输入二叉树名字! \n");
		scanf("%s",name);
		lo=LocateBiTree(BiTrees,name);
		if(lo==0) 
		printf("查找失败! \n");
		else 
		printf("查找到的逻辑序号为%d! \n",lo);
		jishu=0;
		getchar();getchar();
		break;
		case 18:
			printf("此时存在的二叉树有: \n");
			WatchBiTree(BiTrees);
			jishu=0;
			getchar();getchar();
			break;
		case 19:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("请输入文件名! \n");
			scanf("%s",Filename); 
	   		loa=SaveBiTree(BiTrees.elem[num-1].T,Filename);
			if(loa==OK) 
			printf("写入文件成功! \n");
			else 
			printf("二叉树不存在! \n"); 
	   	}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;
		 getchar();getchar();
		 break;
		case 20:
		printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("请输入文件名! \n");
			scanf("%s",Filename);
			int read=LoadBiTree(BiTrees.elem[num-1].T,Filename);
			if(read==OK) 
			printf("读取文件成功! \n");
			else 
			printf("读取文件失败! \n"); 
		 }
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 21:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{ 
	   		int path=MaxPathSum(BiTrees.elem[num-1].T); 
	   		if(path!=-1) 
			printf("最大路径和为%d! \n",path);
			else 
			printf("不存在该二叉树! \n"); 
		}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 22:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{ 
	   		 printf("请输入要查找的两个结点的关键字! \n");
	   		 scanf("%d %d",&e1,&e2);
			 BiTNode *low=LowestCommonAncestor(BiTrees.elem[num-1].T,e1,e2);
			 if(low) 
			 printf("公共祖先为 %d %s ! \n",low->data.key,low->data.others);
			 else 
			 printf("查找不到公共祖先! \n"); 
		}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;
		 memset(guanjianzi,0,sizeof(int)*100);    
		 getchar();getchar();
		 break;
		case 23:
		 printf("请输入操作的树的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{ 
			int invert=InvertTree(BiTrees.elem[num-1].T); 
			 if(invert==OK) 
			 printf("交换兄弟结点成功 ! \n");
			 else 
			 printf("不存在该二叉树! \n"); 
		}
		 else printf("序号错误! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;  	
	}
	}
}
