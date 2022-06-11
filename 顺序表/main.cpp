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
	printf("    	      1. InitList(����˳���)       7. LocateElem(��λԪ��)\n");
	printf("    	      2. DestroyList(����˳���)	8. PriorElem(��ȡǰ��)\n");
	printf("    	      3. ClearList(���˳���)      9. NextElem(��ȡ���) \n");
	printf("    	      4. ListEmpty(˳����п�)      10. ListInsert(����Ԫ��)\n");
	printf("    	      5. ListLength(˳�����)     11. ListDelete(ɾ��Ԫ��)\n");
	printf("    	      6. GetElem(��ȡԪ��)        12. ListTraverse(����˳���)\n");
	printf("���ӹ���:----------------------------------------\n");
	printf("�����Ա����: 13.AddList(����˳���)	14.RemoveList(����˳���)      15.LocateList(��λ˳���)    16.WatchList(����)\n");
	printf("�ļ�����:     17.SaveList(д���ļ�)       18.LoadList(��ȡ�ļ�)\n");
	printf("              19.MaxSubArray(���������)    20.SubArrayNum(����������)       21.sortList(����˳���)\n");
	printf("");
	printf("    	      0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~20]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 if(InitList(L)==OK) printf("���Ա����ɹ���\n");
		     else printf("���Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 2:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
		 {
		 	if(DestroyList(Lists.elem[num-1].L)==OK) printf("���Ա����ٳɹ�! \n");
		 	else printf("���Ա�����ʧ��! \n");
		 }
		 else printf("��Ŵ���! \n");
		 getchar();getchar();
		 break;
	   case 3:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 if(ClearList(Lists.elem[num-1].L)==OK) printf("���Ա���ճɹ�! \n");
		 else printf("���Ա����ʧ��! \n");
		}
		else printf("��Ŵ���! \n");
		 getchar();getchar();
		 break;
	   case 4:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 if(ListEmpty(Lists.elem[num-1].L)==TRUE) printf("���Ա�Ϊ��! \n");
		 else if(ListEmpty(Lists.elem[num-1].L)==FALSE) printf("���Ա�Ϊ��! \n");
		 else printf("���Ա��п�ʧ��! \n");
		}
		 else printf("��Ŵ���! \n");     
		 getchar();getchar();
		 break;
	   case 5:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 if(ListLength(Lists.elem[num-1].L)==-1) printf("�󳤶�ʧ��! \n");
		 else printf("����Ϊ  %d!\n",ListLength(Lists.elem[num-1].L));
		}
		 else printf("��Ŵ���! \n");    
		 getchar();getchar();
		 break;
	   case 6:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
	   	printf("----��������Ҫ��ȡ��Ԫ�����i,�����ᱣ����e��! \n");
	   	scanf("%d",&i);
		if(GetElem(Lists.elem[num-1].L,i,e)==OK) printf("��ȡ��Ԫ��Ϊ %d! \n",e);
		else if(GetElem(Lists.elem[num-1].L,i,e)==-1)  printf("��ȡԪ��ʧ��! \n");
		else printf("�����ڴ�Ԫ��! \n");
		}
		 else printf("��Ŵ���! \n");     
		 getchar();getchar();
		 break;
	   case 7: 
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 printf("----������Ҫ���ҵ�Ԫ��e! \n");
		 scanf("%d",&e);
		 if(LocateElem(Lists.elem[num-1].L,e)==-1) printf("����Ԫ��ʧ��! \n");
		 else if(LocateElem(Lists.elem[num-1].L,e)==0) printf("û������������Ԫ��! \n");
		 else printf("���ҵ�����Ҫ���Ԫ�����Ϊ %d! \n",LocateElem(Lists.elem[num-1].L,e)); 
		 }
		 else printf("��Ŵ���! \n");    
		 getchar();getchar();
		 break;
	   case 8:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 ElemType pre;
		 printf("----������Ҫ���ҵ�Ԫ��e! \n");
		 scanf("%d",&e);
		 if(PriorElem(Lists.elem[num-1].L,e,pre)==OK) printf("���ָ��Ԫ�ص�ǰ���ɹ� %d! \n",pre);
		 else if(PriorElem(Lists.elem[num-1].L,e,pre)==-1)printf("����ʧ��! \n");
		 else printf("�����ڸ�Ԫ�ػ��Ԫ�ز�����ǰ��! \n");
		 }
		 else printf("��Ŵ���! \n");     
		 getchar();getchar();
		 break;
	   case 9:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 ElemType next;
		 printf("----������Ҫ���ҵ�Ԫ��e! \n");
		 scanf("%d",&e);
		 if(NextElem(Lists.elem[num-1].L,e,next)==OK) printf("���ָ��Ԫ�صĺ�̳ɹ� %d! \n",next);
		 else if (NextElem(Lists.elem[num-1].L,e,next)==-1)printf("����ʧ��! \n");
		 else printf("�����ڸ�Ԫ�ػ��Ԫ��û�к��! \n"); 
		 }
		 else printf("��Ŵ���! \n");   
		 getchar();getchar();
		 break;
	   case 10:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 printf("----������Ҫ�����Ԫ��e! \n");
		 scanf("%d",&e);
		 printf("----������Ҫ�����Ԫ��λ��i! \n");
		 scanf("%d",&i);
		 int insert=ListInsert(Lists.elem[num-1].L,i,e);
		 if(insert==OK) printf("����ɹ�! \n");
		 else if(insert==-1) printf("����ʧ��! \n");
		 else printf("����λ�ô���! \n");
		 }
		 else printf("��Ŵ���! \n");     
		 getchar();getchar();
		 break;
	   case 11:
	   	printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
		 printf("----������Ҫɾ����Ԫ��λ��i! \n");
		 scanf("%d",&i);
		 int delet;
		 delet=ListDelete(Lists.elem[num-1].L,i,e); 
		 if(delet==OK) printf("ɾ�����ݳɹ�,ɾ������Ϊ%d! \n",e);
		 else if(delet==-1)  printf("����ɾ��ʧ��! \n");
		 else printf("��ų��ִ���! \n");
		 }
		 else printf("��Ŵ���! \n");     
		 getchar();getchar();
		 break;
	   case 12:
	     printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
	   	int flag;
		   flag=ListTraverse(Lists.elem[num-1].L);
		   printf("\n");
		 if(flag==0) printf("���Ա��ǿձ�\n");
		 else if(flag==-1) printf("���Ա�����! \n");
		 }
		 else printf("��Ŵ���! \n"); 
		getchar();getchar();
		 break;
		case 13:
			printf("�������б�����! \n");
			scanf("%s",name);
			//printf("�����б�ɹ�! \n"); 
			AddList(Lists,name);
			printf("�����б�ɹ�! \n"); 
		getchar();getchar();
		break;
		case 14:
			printf("�������б�����! \n");
			scanf("%s",name);
			if(RemoveList(Lists,name)==OK) {
			printf("ɾ���ɹ�! \n");
			}
			else printf("ɾ��ʧ��! \n"); 
			getchar();getchar();
		break;
		case 15:
			char name[30];
			printf("�������б�����! \n");
			scanf("%s",name);
			if(LocateList(Lists,name)==0) printf("����ʧ��! \n");
			else printf("���ҵ����߼����Ϊ:%d! \n",LocateList(Lists,name));
			getchar();getchar();
		break;
		case 19:
			printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			if(MaxSubArray(Lists.elem[num-1].L)!=-1) printf("���������ĺ�Ϊ %d! \n",MaxSubArray(Lists.elem[num-1].L));
			else printf("����ʧ��! \n");
			}
		 else printf("��Ŵ���! \n");
			getchar();getchar();
		break;
		case 20:
			printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			int k;
			printf("��������ҵĺ�k! \n");
			scanf("%d",&k);
			 if(SubArrayNum(Lists.elem[num-1].L,k)!=-1) printf("��Ϊk��������ĸ���Ϊ %d! \n",SubArrayNum(Lists.elem[num-1].L,k));
			else printf("����ʧ��! \n");
			}
		 else printf("��Ŵ���! \n");
			getchar();getchar();
		break;
		case 21:
			printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			if(sortList(Lists.elem[num-1].L)==OK) printf("����ɹ�! \n");
			else printf("����ʧ��! \n");
			ListTraverse(Lists.elem[num-1].L);
			}
		 else printf("��Ŵ���! \n"); 
			 getchar();getchar();
		break;
		case 17:
			printf("����������ı�����!\n");
	   	scanf("%d",&num);
	   	if(num<=Lists.length&&num>0)
	   	{
			 printf("�������ļ���! \n");
			 scanf("%s",Filename);
			 j=SaveList(Lists.elem[num-1].L,Filename);
			 if(j==OK) {
			 printf("д���ļ��ɹ�! \n");}
			 else printf("д���ļ�ʧ��! \n");
			 }
		 else printf("��Ŵ���! \n");
			 getchar();getchar();
		break;
		case 18:
			printf("����������ı�����!\n");
	   		scanf("%d",&num);
	   		if(num<=Lists.length&&num>0)
	   	{
			 printf("�������ļ���! \n");
			 scanf("%s",Filename);
			 j=LoadList(Lists.elem[num-1].L,Filename);
			 	if(j==OK) {
				 printf("��ȡ�ļ��ɹ�! \n");
				 ListTraverse(Lists.elem[num-1].L);
				 printf("\n");
					}
				 else
				 {
				 	printf("��ȡ�ļ�ʧ��! \n");
				  }
				  }
		 else printf("��Ŵ���! \n");
			 getchar();getchar();
		break;
		case 16:
			printf("��ʱ���ڵ�˳�����: \n");
			WatchList(Lists);
			getchar();getchar();
			break; 	 
	case 0:
         break;
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()

