
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
		printf("    1. InitList(��������)       7. LocateElem(��λԪ��)\n");
		printf("    2. DestroyList(��������)	8. PriorElem(Ԫ��ǰ��)\n");
		printf("    3. ClearList(�������)      9. NextElem(Ԫ�غ��) \n");
		printf("    4. ListEmpty(�п�����)      10. ListInsert(����Ԫ��)\n");
		printf("    5. ListLength(������)     11. ListDelete(ɾ��Ԫ��)\n");
		printf("    6. GetElem(��ȡԪ��)        12. ListTraverse(��������)\n");
		printf("���ӹ���:----------------------------------------\n");
		printf("    13.reverseList(��ת����)    14.RemoveNthFromEnd(ɾ������)\
		       15.sortList(��������)\n");
		printf("�ļ�����:16.SaveList(д���ļ�)       17.LoadList(��ȡ�ļ�)\n");
		printf("�����Ա����: 18.AddList(��������)	19.RemoveList(��������)\
		        20.LocateList(��λ����)   21.WatchList(��������)\n");
		printf("");
		printf("    	      0. Exit\n");
		printf("----------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~20]:");
		scanf("%d",&op);
		switch(op)
		{
		case 1:
		 if(InitList(L)==OK) printf("�������ɹ���\n");
		     else printf("������ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
		 case 2:
	   		printf("����������ı�����!\n");
	   		scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(DestroyList(Lists.elem[n-1].L)==OK) 
		 printf("�������ٳɹ�! \n");
		 else 
		 printf("��������ʧ��! \n");
		}
		else printf("��Ŵ��� !\n");
		 getchar();getchar();
		 break;
		 case 3:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(ClearList(Lists.elem[n-1].L)==OK) 
		 printf("������ճɹ�! \n");
		 else 
		 printf("�������ʧ��! \n");
		 }
		else printf("��Ŵ��� !\n");
		 getchar();getchar();
		 break;
		 case 4:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(ListEmpty(Lists.elem[n-1].L)==TRUE) 
		 printf("����Ϊ��! \n");
		 else if(ListEmpty(Lists.elem[n-1].L)==FALSE) 
		 printf("����Ϊ��! \n");
		 else printf("�����п�ʧ��! \n");
		 }
		else printf("��Ŵ��� !\n");     
		 getchar();getchar();
		 break;
		 case 5:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 if(ListLength(Lists.elem[n-1].L)==-1) 
		 printf("�󳤶�ʧ��! \n");
		 else 
		 printf("����Ϊ  %d!\n",ListLength(Lists.elem[n-1].L));
		 }
		else printf("��Ŵ��� !\n");    
		 getchar();getchar();
		 break;
		 case 6:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
	   	printf("----��������Ҫ��ȡ��Ԫ�����i,�����ᱣ����e��! \n");
	   	scanf("%d",&i);
		if(GetElem(Lists.elem[n-1].L,i,e)==OK) 
		printf("��ȡ��Ԫ��Ϊ %d! \n",e);
		else 
		printf("��ȡԪ��ʧ��! \n");
		}
		else printf("��Ŵ��� !\n");     
		 getchar();getchar();
		 break;
		 case 7: 
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 printf("----������Ҫ���ҵ�Ԫ��e! \n");
		 scanf("%d",&e);
		 if(LocateElem(Lists.elem[n-1].L,e)==-1) 
		 printf("����Ԫ��ʧ��! \n");
		 else if(LocateElem(Lists.elem[n-1].L,e)==0) 
		 printf("û������������Ԫ��! \n");
		 else 
		 printf("���ҵ�����Ҫ���Ԫ�����Ϊ %d! \n",LocateElem(Lists.elem[n-1].L,e));
		 }
		else printf("��Ŵ��� !\n");     
		 getchar();getchar();
		 break;
		 case 8:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 ElemType pre;
		 printf("----������Ҫ���ҵ�Ԫ��e! \n");
		 scanf("%d",&e);
		 if(PriorElem(Lists.elem[n-1].L,e,pre)==OK) 
		 printf("���ָ��Ԫ�ص�ǰ���ɹ� %d! \n",pre);
		 else 
		 printf("����ʧ��! \n");
		 }
		else printf("��Ŵ��� !\n");     
		 getchar();getchar();
		 break;
		 case 9:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 ElemType next;
		 printf("----������Ҫ���ҵ�Ԫ��e! \n");
		 scanf("%d",&e);
		 if(NextElem(Lists.elem[n-1].L,e,next)==OK) 
		 printf("���ָ��Ԫ�صĺ�̳ɹ� %d! \n",next);
		 else  
		 printf("����ʧ��! \n");
		 }
		else printf("��Ŵ��� !\n");   
		 getchar();getchar();
		 break;
		 case 10:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 printf("----������Ҫ�����Ԫ��e! \n");
		 scanf("%d",&e);
		 printf("----������Ҫ�����Ԫ��λ��i! \n");
		 scanf("%d",&i);
		 if(ListInsert(Lists.elem[n-1].L,i,e)==OK) 
		 printf("����ɹ�! \n");
		 else 
		 printf("����ʧ��! \n");
		 }
		else printf("��Ŵ��� !\n");     
		 getchar();getchar();
		 break;
		 case 11:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
		 printf("----������Ҫɾ����Ԫ��λ��i! \n");
		 scanf("%d",&i);
		 if(ListDelete(Lists.elem[n-1].L,i,e)==OK) 
		 printf("ɾ�����ݳɹ�,ɾ������Ϊ%d! \n",e);
		 else 
		 printf("����ɾ��ʧ��! \n");
		 }
		else printf("��Ŵ��� !\n");     
		 getchar();getchar();
		 break;
		 case 12:
	     printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
	   	int flag;
		   flag=ListTraverse(Lists.elem[n-1].L);
		   printf("\n");
		 if(flag==0) 
		 printf("�����ǿձ�\n");
		 else if(flag==-1) 
		 printf("��������! \n");
		 }
		else printf("��Ŵ��� !\n"); 
		getchar();getchar();
		 break;
		 case 18:
			printf("�������б�����! \n");
			scanf("%s",name);
			int add;
			add=AddList(Lists,name);
			if(add==OK) {
			printf("�����б�ɹ�! \n");
			now++;
			}
			else printf("��������ʧ��! \n");
		getchar();getchar();
		break;
		case 19:
			printf("�������б�����! \n");
			scanf("%s",name);
			if(RemoveList(Lists,name)==OK) {
			printf("ɾ���ɹ�! \n");
			now--;
			}
			else printf("ɾ��ʧ��! \n"); 
			getchar();getchar();
		break;
		case 20:
			char name[30];
			printf("�������б�����! \n");
			scanf("%s",name);
			if(LocateList(Lists,name)==0) 
			printf("����ʧ��! \n");
			else 
			printf("���ҵ����߼����Ϊ:%d! \n",LocateList(Lists,name));
			getchar();getchar();
		break;
		case 21:
			printf("��ʱ���ڵ�˳�����: \n");
			WatchList(Lists);
			getchar();getchar();
			break;
		case 16:
			printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
			 printf("�������ļ���! \n");
			 scanf("%s",Filename);
			 j=SaveList(Lists.elem[n-1].L,Filename);
			 if(j==OK) {
			 printf("д���ļ��ɹ�! \n");}
			 else printf("д���ļ�ʧ��! \n");
			 }
		else printf("��Ŵ��� !\n");
			 getchar();getchar();
		break;
		case 17:
			printf("����������ı�����!\n");
	   		scanf("%d",&n);
	   		if(n<=now&&n>0)
	   	{
			 printf("�������ļ���! \n");
			 scanf("%s",Filename);
			 j=LoadList(Lists.elem[n-1].L,Filename);
			 	if(j==OK) {
				 printf("��ȡ�ļ��ɹ�! \n");
				 ListTraverse(Lists.elem[n-1].L);
				 printf("\n");
					}
				 else
				 {
				 	printf("��ȡ�ļ�ʧ��! \n");
				  }
				  }
		else printf("��Ŵ��� !\n");
			 getchar();getchar();
		break;
		case 13:
		printf("����������ı�����!\n");
		scanf("%d",&n);
		if(n<=now&&n>0)
	   	{
		if(reverseList(Lists.elem[n-1].L)==OK)
		{
			printf("��ת�ɹ�! \n");
			ListTraverse(Lists.elem[n-1].L);
		}
		else printf("��ת��������! \n");
		}
		else printf("��Ŵ��� !\n");
		 getchar();getchar();
		break;
		case 14:
		 printf("����������ı�����!\n");
		scanf("%d",&n);
		if(n<=now&&n>0)
	   	{
		printf("��������Ҫɾ������ĵ����ڼ����ڵ�! \n");
		int daoshu;
		scanf("%d",&daoshu);
		if(RemoveNthFrom(Lists.elem[n-1].L,daoshu,e)==OK)
		{
		printf("ɾ���ɹ�,������%d������Ϊ%d! \n",daoshu,e);
		}
		else 
		printf("ɾ��������������! \n");
		}
		else printf("��Ŵ��� !\n");
		 getchar();getchar();
		break;
		case 15:
			printf("����������ı�����!\n");
	   	scanf("%d",&n);
	   	if(n<=now&&n>0)
	   	{
			if(sortList(Lists.elem[n-1].L)==OK) 
			printf("����ɹ�! \n");
			else 
			printf("����ʧ��! \n");
			ListTraverse(Lists.elem[n-1].L);
			}
		else printf("��Ŵ��� !\n"); 
			 getchar();getchar();
		break;
		case 0:
         break;
		}//end of switch
	}//end of while
	printf("\n��ӭ�´�ʹ�ñ�ϵͳ!");
}//end of main 
