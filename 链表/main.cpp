
#include "list1.h"
int main()
{
	LISTS Lists;
	Lists.num=0;
	LinkList L;
	L=NULL;
	ElemType e;
	int i,j;
	int n;
	int now=0;
	char name[30],Filename[30];
	int op=1;
	while(op)
	{
		system("cls"); printf("\n\n");
		printf("Menu for Linear Table On Sequence Structure \n");
		printf("------------------------------------------\n");
		printf("    1. InitList(创建链表)       7. LocateElem(定位元素)\n");
		printf("    2. DestroyList(销毁链表)	8. PriorElem(元素前驱)\n");
		printf("    3. ClearList(清空链表)      9. NextElem(元素后继) \n");
		printf("    4. ListEmpty(判空链表)      10. ListInsert(插入元素)\n");
		printf("    5. ListLength(链表长度)     11. ListDelete(删除元素)\n");
		printf("    6. GetElem(获取元素)        12. ListTraverse(遍历链表)\n");
		printf("附加功能:----------------------------------------\n");
		printf("    13.reverseList(翻转链表)    14.RemoveNthFromEnd(删除倒数)\
		       15.sortList(链表排序)\n");
		printf("文件功能:16.SaveList(写入文件)       17.LoadList(读取文件)\n");
		printf("多线性表操作: 18.AddList(增添链表)	19.RemoveList(消除链表)\
		        20.LocateList(定位链表)   21.WatchList(总览链表)\n");
		printf("");
		printf("    	      0. Exit\n");
		printf("----------------------------------------\n");
		printf("    请选择你的操作[0~20]:");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
		 if(InitList(L)==OK) printf("链表创建成功！\n");
		     else printf("链表创建失败！\n");
		 getchar();getchar();
		 break;
		 case 2:
	   		printf("请输入操作的表的序号!\n");
	   		scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(DestroyList(Lists.elem[n-1].L)==OK) 
		 printf("链表销毁成功! \n");
		 else 
		 printf("链表销毁失败! \n");
		}
		else printf("序号错误 !\n");
		 getchar();getchar();
		 break;
		 case 3:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(ClearList(Lists.elem[n-1].L)==OK) 
		 printf("链表清空成功! \n");
		 else 
		 printf("链表清空失败! \n");
		 }
		else printf("序号错误 !\n");
		 getchar();getchar();
		 break;
		 case 4:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(ListEmpty(Lists.elem[n-1].L)==TRUE) 
		 printf("链表为空! \n");
		 else if(ListEmpty(Lists.elem[n-1].L)==FALSE) 
		 printf("链表不为空! \n");
		 else printf("链表判空失败! \n");
		 }
		else printf("序号错误 !\n");     
		 getchar();getchar();
		 break;
		 case 5:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(ListLength(Lists.elem[n-1].L)==-1) 
		 printf("求长度失败! \n");
		 else 
		 printf("长度为  %d!\n",ListLength(Lists.elem[n-1].L));
		 }
		else printf("序号错误 !\n");    
		 getchar();getchar();
		 break;
		 case 6:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
	   	printf("----请输入你要获取的元素序号i,函数会保存在e中! \n");
	   	scanf("%d",&i);
		if(GetElem(Lists.elem[n-1].L,i,e)==OK) 
		printf("获取的元素为 %d! \n",e);
		else 
		printf("获取元素失败! \n");
		}
		else printf("序号错误 !\n");     
		 getchar();getchar();
		 break;
		 case 7: 
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 printf("----请输入要查找的元素e! \n");
		 scanf("%d",&e);
		 if(LocateElem(Lists.elem[n-1].L,e)==-1) 
		 printf("查找元素失败! \n");
		 else if(LocateElem(Lists.elem[n-1].L,e)==0) 
		 printf("没有满足条件的元素! \n");
		 else 
		 printf("查找到满足要求的元素序号为 %d! \n",LocateElem(Lists.elem[n-1].L,e));
		 }
		else printf("序号错误 !\n");     
		 getchar();getchar();
		 break;
		 case 8:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 ElemType pre;
		 printf("----请输入要查找的元素e! \n");
		 scanf("%d",&e);
		 if(PriorElem(Lists.elem[n-1].L,e,pre)==OK) 
		 printf("获得指定元素的前驱成功 %d! \n",pre);
		 else 
		 printf("操作失败! \n");
		 }
		else printf("序号错误 !\n");     
		 getchar();getchar();
		 break;
		 case 9:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 ElemType next;
		 printf("----请输入要查找的元素e! \n");
		 scanf("%d",&e);
		 if(NextElem(Lists.elem[n-1].L,e,next)==OK) 
		 printf("获得指定元素的后继成功 %d! \n",next);
		 else  
		 printf("操作失败! \n");
		 }
		else printf("序号错误 !\n");   
		 getchar();getchar();
		 break;
		 case 10:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 printf("----请输入要插入的元素e! \n");
		 scanf("%d",&e);
		 printf("----请输入要插入的元素位置i! \n");
		 scanf("%d",&i);
		 if(ListInsert(Lists.elem[n-1].L,i,e)==OK) 
		 printf("插入成功! \n");
		 else 
		 printf("插入失败! \n");
		 }
		else printf("序号错误 !\n");     
		 getchar();getchar();
		 break;
		 case 11:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 printf("----请输入要删除的元素位置i! \n");
		 scanf("%d",&i);
		 if(ListDelete(Lists.elem[n-1].L,i,e)==OK) 
		 printf("删除数据成功,删除数据为%d! \n",e);
		 else 
		 printf("数据删除失败! \n");
		 }
		else printf("序号错误 !\n");     
		 getchar();getchar();
		 break;
		 case 12:
	     printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
	   	int flag;
		   flag=ListTraverse(Lists.elem[n-1].L);
		   printf("\n");
		 if(flag==0) 
		 printf("链表是空表！\n");
		 else if(flag==-1) 
		 printf("链表不存在! \n");
		 }
		else printf("序号错误 !\n"); 
		getchar();getchar();
		 break;
		 case 18:
			printf("请输入列表名字! \n");
			scanf("%s",name);
			int add;
			add=AddList(Lists,name);
			if(add==OK) {
			printf("增添列表成功! \n");
			now++;
			}
			else printf("增添链表失败! \n");
		getchar();getchar();
		break;
		case 19:
			printf("请输入列表名字! \n");
			scanf("%s",name);
			if(RemoveList(Lists,name)==OK) {
			printf("删除成功! \n");
			now--;
			}
			else printf("删除失败! \n"); 
			getchar();getchar();
		break;
		case 20:
			char name[30];
			printf("请输入列表名字! \n");
			scanf("%s",name);
			if(LocateList(Lists,name)==0) 
			printf("查找失败! \n");
			else 
			printf("查找到的逻辑序号为:%d! \n",LocateList(Lists,name));
			getchar();getchar();
		break;
		case 21:
			printf("此时存在的顺序表有: \n");
			WatchList(Lists);
			getchar();getchar();
			break;
		case 16:
			printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
			 printf("请输入文件名! \n");
			 scanf("%s",Filename);
			 j=SaveList(Lists.elem[n-1].L,Filename);
			 if(j==OK) {
			 printf("写入文件成功! \n");}
			 else printf("写入文件失败! \n");
			 }
		else printf("序号错误 !\n");
			 getchar();getchar();
		break;
		case 17:
			printf("请输入操作的表的序号!\n");
	   		scanf("%d",&n);
	   		if(n<=now&&n>0)
	   	{
			 printf("请输入文件名! \n");
			 scanf("%s",Filename);
			 j=LoadList(Lists.elem[n-1].L,Filename);
			 	if(j==OK) {
				 printf("读取文件成功! \n");
				 ListTraverse(Lists.elem[n-1].L);
				 printf("\n");
					}
				 else
				 {
				 	printf("读取文件失败! \n");
				  }
				  }
		else printf("序号错误 !\n");
			 getchar();getchar();
		break;
		case 13:
		printf("请输入操作的表的序号!\n");
		scanf("%d",&n);
		if(n<=now&&n>0)
	   	{
		if(reverseList(Lists.elem[n-1].L)==OK)
		{
			printf("翻转成功! \n");
			ListTraverse(Lists.elem[n-1].L);
		}
		else printf("翻转出现问题! \n");
		}
		else printf("序号错误 !\n");
		 getchar();getchar();
		break;
		case 14:
		 printf("请输入操作的表的序号!\n");
		scanf("%d",&n);
		if(n<=now&&n>0)
	   	{
		printf("请输入你要删除链表的倒数第几个节点! \n");
		int daoshu;
		scanf("%d",&daoshu);
		if(RemoveNthFrom(Lists.elem[n-1].L,daoshu,e)==OK)
		{
		printf("删除成功,倒数第%d个数据为%d! \n",daoshu,e);
		}
		else 
		printf("删除操作出现问题! \n");
		}
		else printf("序号错误 !\n");
		 getchar();getchar();
		break;
		case 15:
			printf("请输入操作的表的序号!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
			if(sortList(Lists.elem[n-1].L)==OK) 
			printf("排序成功! \n");
			else 
			printf("排序失败! \n");
			ListTraverse(Lists.elem[n-1].L);
			}
		else printf("序号错误 !\n"); 
			 getchar();getchar();
		break;
		case 0:
         break;
		}//end of switch
	}//end of while
	printf("\n欢迎下次使用本系统!");
}//end of main 
