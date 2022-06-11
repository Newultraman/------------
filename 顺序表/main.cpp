#include "list.h"

int main(void)
{
	SqList L;
	L.elem=NULL;
	LISTS Lists;
	Lists.length=0;
	ElemType e;
	int i,j;
	int num;
	char name[30];
	char Filename[30];
	int op=1;
	while(op)
	{
		system("cls");	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	      1. InitList(创建顺序表)       7. LocateElem(定位元素)\n");
	printf("    	      2. DestroyList(销毁顺序表)	8. PriorElem(获取前驱)\n");
	printf("    	      3. ClearList(清空顺序表)      9. NextElem(获取后继) \n");
	printf("    	      4. ListEmpty(顺序表判空)      10. ListInsert(插入元素)\n");
	printf("    	      5. ListLength(顺序表长度)     11. ListDelete(删除元素)\n");
	printf("    	      6. GetElem(获取元素)        12. ListTraverse(遍历顺序表)\n");
	printf("附加功能:----------------------------------------\n");
	printf("多线性表操作: 13.AddList(增添顺序表)	14.RemoveList(消除顺序表)      15.LocateList(定位顺序表)    16.WatchList(总览)\n");
	printf("文件功能:     17.SaveList(写入文件)       18.LoadList(读取文件)\n");
	printf("              19.MaxSubArray(最大子数组)    20.SubArrayNum(连续子数组)       21.sortList(排序顺序表)\n");
	printf("");
	printf("    	      0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~20]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 if(InitList(L)==OK) printf("线性表创建成功！\n");
		     else printf("线性表创建失败！\n");
		 getchar();getchar();
		 break;
	   case 2:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
		 {
		 	if(DestroyList(Lists.elem[num-1].L)==OK) printf("线性表销毁成功! \n");
		 	else printf("线性表销毁失败! \n");
		 }
		 else printf("序号错误! \n");
		 getchar();getchar();
		 break;
	   case 3:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 if(ClearList(Lists.elem[num-1].L)==OK) printf("线性表清空成功! \n");
		 else printf("线性表清空失败! \n");
		}
		else printf("序号错误! \n");
		 getchar();getchar();
		 break;
	   case 4:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 if(ListEmpty(Lists.elem[num-1].L)==TRUE) printf("线性表为空! \n");
		 else if(ListEmpty(Lists.elem[num-1].L)==FALSE) printf("线性表不为空! \n");
		 else printf("线性表判空失败! \n");
		}
		 else printf("序号错误! \n");     
		 getchar();getchar();
		 break;
	   case 5:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 if(ListLength(Lists.elem[num-1].L)==-1) printf("求长度失败! \n");
		 else printf("长度为  %d!\n",ListLength(Lists.elem[num-1].L));
		}
		 else printf("序号错误! \n");    
		 getchar();getchar();
		 break;
	   case 6:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
	   	printf("----请输入你要获取的元素序号i,函数会保存在e中! \n");
	   	scanf("%d",&i);
		if(GetElem(Lists.elem[num-1].L,i,e)==OK) printf("获取的元素为 %d! \n",e);
		else if(GetElem(Lists.elem[num-1].L,i,e)==-1)  printf("获取元素失败! \n");
		else printf("不存在此元素! \n");
		}
		 else printf("序号错误! \n");     
		 getchar();getchar();
		 break;
	   case 7: 
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 printf("----请输入要查找的元素e! \n");
		 scanf("%d",&e);
		 if(LocateElem(Lists.elem[num-1].L,e)==-1) printf("查找元素失败! \n");
		 else if(LocateElem(Lists.elem[num-1].L,e)==0) printf("没有满足条件的元素! \n");
		 else printf("查找到满足要求的元素序号为 %d! \n",LocateElem(Lists.elem[num-1].L,e)); 
		 }
		 else printf("序号错误! \n");    
		 getchar();getchar();
		 break;
	   case 8:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 ElemType pre;
		 printf("----请输入要查找的元素e! \n");
		 scanf("%d",&e);
		 if(PriorElem(Lists.elem[num-1].L,e,pre)==OK) printf("获得指定元素的前驱成功 %d! \n",pre);
		 else if(PriorElem(Lists.elem[num-1].L,e,pre)==-1)printf("操作失败! \n");
		 else printf("不存在该元素或该元素不存在前驱! \n");
		 }
		 else printf("序号错误! \n");     
		 getchar();getchar();
		 break;
	   case 9:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 ElemType next;
		 printf("----请输入要查找的元素e! \n");
		 scanf("%d",&e);
		 if(NextElem(Lists.elem[num-1].L,e,next)==OK) printf("获得指定元素的后继成功 %d! \n",next);
		 else if (NextElem(Lists.elem[num-1].L,e,next)==-1)printf("操作失败! \n");
		 else printf("不存在该元素或该元素没有后继! \n"); 
		 }
		 else printf("序号错误! \n");   
		 getchar();getchar();
		 break;
	   case 10:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 printf("----请输入要插入的元素e! \n");
		 scanf("%d",&e);
		 printf("----请输入要插入的元素位置i! \n");
		 scanf("%d",&i);
		 int insert=ListInsert(Lists.elem[num-1].L,i,e);
		 if(insert==OK) printf("插入成功! \n");
		 else if(insert==-1) printf("插入失败! \n");
		 else printf("插入位置错误! \n");
		 }
		 else printf("序号错误! \n");     
		 getchar();getchar();
		 break;
	   case 11:
	   	printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 printf("----请输入要删除的元素位置i! \n");
		 scanf("%d",&i);
		 int delet;
		 delet=ListDelete(Lists.elem[num-1].L,i,e); 
		 if(delet==OK) printf("删除数据成功,删除数据为%d! \n",e);
		 else if(delet==-1)  printf("数据删除失败! \n");
		 else printf("序号出现错误! \n");
		 }
		 else printf("序号错误! \n");     
		 getchar();getchar();
		 break;
	   case 12:
	     printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
	   	int flag;
		   flag=ListTraverse(Lists.elem[num-1].L);
		   printf("\n");
		 if(flag==0) printf("线性表是空表！\n");
		 else if(flag==-1) printf("线性表不存在! \n");
		 }
		 else printf("序号错误! \n"); 
		getchar();getchar();
		 break;
		case 13:
			printf("请输入列表名字! \n");
			scanf("%s",name);
			//printf("增添列表成功! \n"); 
			AddList(Lists,name);
			printf("增添列表成功! \n"); 
		getchar();getchar();
		break;
		case 14:
			printf("请输入列表名字! \n");
			scanf("%s",name);
			if(RemoveList(Lists,name)==OK) {
			printf("删除成功! \n");
			}
			else printf("删除失败! \n"); 
			getchar();getchar();
		break;
		case 15:
			char name[30];
			printf("请输入列表名字! \n");
			scanf("%s",name);
			if(LocateList(Lists,name)==0) printf("查找失败! \n");
			else printf("查找到的逻辑序号为:%d! \n",LocateList(Lists,name));
			getchar();getchar();
		break;
		case 19:
			printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			if(MaxSubArray(Lists.elem[num-1].L)!=-1) printf("最大子数组的和为 %d! \n",MaxSubArray(Lists.elem[num-1].L));
			else printf("操作失败! \n");
			}
		 else printf("序号错误! \n");
			getchar();getchar();
		break;
		case 20:
			printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			int k;
			printf("请输入查找的和k! \n");
			scanf("%d",&k);
			 if(SubArrayNum(Lists.elem[num-1].L,k)!=-1) printf("和为k的子数组的个数为 %d! \n",SubArrayNum(Lists.elem[num-1].L,k));
			else printf("操作失败! \n");
			}
		 else printf("序号错误! \n");
			getchar();getchar();
		break;
		case 21:
			printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			if(sortList(Lists.elem[num-1].L)==OK) printf("排序成功! \n");
			else printf("排序失败! \n");
			ListTraverse(Lists.elem[num-1].L);
			}
		 else printf("序号错误! \n"); 
			 getchar();getchar();
		break;
		case 17:
			printf("请输入操作的表的序号!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			 printf("请输入文件名! \n");
			 scanf("%s",Filename);
			 j=SaveList(Lists.elem[num-1].L,Filename);
			 if(j==OK) {
			 printf("写入文件成功! \n");}
			 else printf("写入文件失败! \n");
			 }
		 else printf("序号错误! \n");
			 getchar();getchar();
		break;
		case 18:
			printf("请输入操作的表的序号!\n");
	   		scanf("%d",&num);
	   		if(num<=Lists.length&&num>0)
	   	{
			 printf("请输入文件名! \n");
			 scanf("%s",Filename);
			 j=LoadList(Lists.elem[num-1].L,Filename);
			 	if(j==OK) {
				 printf("读取文件成功! \n");
				 ListTraverse(Lists.elem[num-1].L);
				 printf("\n");
					}
				 else
				 {
				 	printf("读取文件失败! \n");
				  }
				  }
		 else printf("序号错误! \n");
			 getchar();getchar();
		break;
		case 16:
			printf("此时存在的顺序表有: \n");
			WatchList(Lists);
			getchar();getchar();
			break; 	 
	case 0:
         break;
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
}//end of main()

