#include "BiTree.h"


status CreateBiTree(BiTree &T,DEF definition[])
//����Ϊ BiTree &T,DEF definition[]
//������T������,����definition����һ��������. 
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
//����Ϊ BiTree &T
//�����������óɿգ���ɾ�����н�㣬�ͷŽ��ռ�
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
//����Ϊ BITREES &BiTrees,char BiTreename[],DEF definition[]
//����һ�������� 
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
//����ΪBITREES &BiTrees,char BiTreeName[]
// BiTrees��ɾ��һ������ΪBiTreeName�Ķ����� 
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
//����Ϊ BiTree T
//�������T�����
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
	printf("    1. CreatBiTree(����������)7. Assign(��㸳ֵ)\n");
	printf("  2. DestroyBiTree(���ٶ�����) 8. GetSibiling(����ֵܽ��)\n");
	printf("    3. ClearBiTree(��ն�����)  9. InsertNode(������) \n");
	printf("    4. BiTreeEmpty(�������п�)  10. DeleteNode(ɾ�����)\n");
	printf("    5. BiTreeLength(���������) 11. PreOrderTraverse(ǰ�����)\n");
	printf("    6. LocateNode(���ҽ��)  12. InOrderTraverse(�������)\n");
	printf("    13. PostOrderTraverse(�������) 14. LevelOrderTraverse(�������)\n");
	printf("���ӹ���:----------------------------------------\n");
	printf("�����������: 15. AddBiTree(���������)	16. RemoveBiTree(����������)\
	 17. LocateBiTree(��λ������) 18. WatchBiTree(����)\n");
	printf("�ļ�����:  19. SaveBiTree(д���ļ�) 20. LoadBiTree(��ȡ�ļ�)\n"); 
	printf("  21. MaxPathSum(���·����) 22. LowestCommonAncestor(�����������)\
		23. InvertTree(��ת������)\n");
	printf("");
	printf("    	      0. Exit\n");
	printf("--------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~20]:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("���������Ҫ�����Ķ�����! \n");
			do {
		scanf("%d%d%s",&definition[i].pos,
		&definition[i].data.key,definition[i].data.others);
		} while (definition[i++].pos);
		if(definition[0].pos!=0)
		{
			if(CreateBiTree(T,definition)==OK) 
			printf("�����������ɹ���\n");
		    else 
			printf("����������ʧ�ܣ�\n");
		}
		else printf("����������ʧ�ܣ�\n");
		i=0;
		 getchar();getchar();
		 break;
		case 2:
		printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
		 {
		 	if(DestroyBiTree(BiTrees.elem[num-1].T)==OK) 
			printf("���������ٳɹ�! \n");
		 	else
			printf("����������ʧ��! \n");
		 }
		 else printf("��Ŵ���! \n");
		 set=0;i=0;
		 getchar();getchar();
		 break;
		 case 3:
	   	printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   	
		 if(ClearBiTree(BiTrees.elem[num-1].T)==OK) 
		 printf("��������ճɹ�! \n");
		 else 
		 printf("���������ʧ��! \n");
		}
		else printf("��Ŵ���! \n");
		set=0;i=0;
		 getchar();getchar();
		 break; 
		case 4:
	   	printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
		 if(BiTreeEmpty(BiTrees.elem[num-1].T)==TRUE) 
		 printf("������Ϊ��! \n");
		 else if(BiTreeEmpty(BiTrees.elem[num-1].T)==FALSE) 
		 printf("��������Ϊ��! \n");
		 else 
		 printf("�������п�ʧ��! \n");
		}
		 else printf("��Ŵ���! \n");
		 i=0;jishu=0;     
		 getchar();getchar();
		 break;
		 case 5:
	   	printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		dep=BiTreeDepth(BiTrees.elem[num-1].T);
		 if(dep==-1) 
		 printf("�����ʧ��! \n");
		 else 
		 printf("���Ϊ  %d!\n",dep);
		}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar(); 
		 break;
		 case 6:
	   	printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   	printf("��������Ҫ���ҵĽ��ؼ���,�����᷵�ظýڵ�ָ��! \n");
	   	scanf("%d",&e);
		BiTNode *p=LocateNode(BiTrees.elem[num-1].T,e);
		if(p) 
		printf("%d,%s",p->data.key,p->data.others);
		else 
		printf("�����ڴ˽��! \n");
		}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;      
		 getchar();getchar();
		 break;
		 case 7:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("��������Ҫ���ҵĹؼ����Լ��滻��ֵ! \n");
	   		scanf("%d%d%s",&e,&value.key,value.others);
	   		int ass=Assign(BiTrees.elem[num-1].T,e,value);
			if(ass==OK) 
			printf("��㸳ֵ�ɹ�! \n");
			else if(ass==ERROR) 
			printf("Ŀ��ؼ���������! \n");
			else 
			printf("��ֵʧ��");
			memset(guanjianzi,0,sizeof(int)*100); 
	   	}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;     
		 getchar();getchar();
		 break;
		case 8:
		  printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("������Ҫ�����ֵܵĽ��Ĺؼ���! \n");
	   		scanf("%d",&e);
		BiTNode *p=GetSibling(BiTrees.elem[num-1].T,e);
		if(p) 
		printf("%d,%s",p->data.key,p->data.others);
		else 
		printf("���ֵܽ��");
		memset(guanjianzi,0,sizeof(int)*100);	
	   	}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;     
		 getchar();getchar();
		 break;
		 case 9:
		printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("������Ҫ��Ӧ�Ĺؼ���,���뷽ʽ,����Ľ��! \n");
	   		scanf("%d%d%d%s",&e,&LR,&value.key,value.others);
			int in=InsertNode(BiTrees.elem[num-1].T,e,LR,value);
			if(in==OK) 
			printf("������ɹ�! \n");
			else if(in==ERROR) 
			printf("������ʧ��! \n");
			else 
			printf("�����ڶ�����! \n");
			memset(guanjianzi,0,sizeof(int)*100); 
	   	}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;
		 memset(guanjianzi,0,sizeof(int)*100);    
		 getchar();getchar();
		 break;
		 case 10:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("��������Ҫɾ���Ľ��Ĺؼ���! \n");
	   		scanf("%d",&e);
			int de=DeleteNode(BiTrees.elem[num-1].T,e);
			if(de==OK) 
			printf("ɾ���ɹ�! \n");
			else if(de==ERROR) 
			printf("ɾ��ʧ��! \n");
			else 
			printf("������������! \n"); 
	   		}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;
		 memset(guanjianzi,0,sizeof(int)*100);    
		 getchar();getchar();
		 break;
		 case 11:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("�������������! \n");
			int pre=PreOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(pre==-1) 
			printf("�����ڶ�����! \n");
			else if(pre==ERROR) 
			printf("������Ϊ��! \n"); 
		 }
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 12:
		  printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("�������������! \n");
			int ino=InOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(ino==-1) 
			printf("�����ڶ�����! \n");
			else if(ino==ERROR) 
			printf("������Ϊ��! \n"); 
		 }
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 13:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("�������������! \n");
			int post=PostOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(post==-1) 
			printf("�����ڶ�����! \n");
			else if(post==ERROR) 
			printf("������Ϊ��! \n"); 
		 }
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 14:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("�������������! \n");
			int level=LevelOrderTraverse(BiTrees.elem[num-1].T,visit);
			if(level==-1) 
			printf("�����ڶ�����! \n");
			else if(level==ERROR) 
			printf("������Ϊ��! \n"); 
		 }
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 15:
		 printf("���������������! \n");
			scanf("%s",name);
		printf("���������Ҫ�����Ķ�����! \n");
			do {
		scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,
		definition[i].data.others);
		} while (definition[i++].pos);
		if(definition[0].pos!=0)
		{ 
			jia=AddBiTree(BiTrees,name,definition);
			if(jia==OK) 
			printf("����������ɹ�! \n");
			else 
			printf("����������ʧ�ܣ�\n");
		}
		else printf("����������ʧ�ܣ�\n");
		set=0;i=0;jishu=0; 
		getchar();getchar();
		break;
		case 16:
			printf("���������������! \n");
			scanf("%s",name);
			rem=RemoveBiTree(BiTrees,name);
			if(rem==OK) 
			printf("ɾ���ɹ�! \n");
			else 
			printf("ɾ��ʧ��! \n");
			i=0;jishu=0;
			getchar();getchar();
		break;
		case 17:
		printf("���������������! \n");
		scanf("%s",name);
		lo=LocateBiTree(BiTrees,name);
		if(lo==0) 
		printf("����ʧ��! \n");
		else 
		printf("���ҵ����߼����Ϊ%d! \n",lo);
		jishu=0;
		getchar();getchar();
		break;
		case 18:
			printf("��ʱ���ڵĶ�������: \n");
			WatchBiTree(BiTrees);
			jishu=0;
			getchar();getchar();
			break;
		case 19:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("�������ļ���! \n");
			scanf("%s",Filename); 
	   		loa=SaveBiTree(BiTrees.elem[num-1].T,Filename);
			if(loa==OK) 
			printf("д���ļ��ɹ�! \n");
			else 
			printf("������������! \n"); 
	   	}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;
		 getchar();getchar();
		 break;
		case 20:
		printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{
	   		printf("�������ļ���! \n");
			scanf("%s",Filename);
			int read=LoadBiTree(BiTrees.elem[num-1].T,Filename);
			if(read==OK) 
			printf("��ȡ�ļ��ɹ�! \n");
			else 
			printf("��ȡ�ļ�ʧ��! \n"); 
		 }
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 21:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{ 
	   		int path=MaxPathSum(BiTrees.elem[num-1].T); 
	   		if(path!=-1) 
			printf("���·����Ϊ%d! \n",path);
			else 
			printf("�����ڸö�����! \n"); 
		}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;
		 case 22:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{ 
	   		 printf("������Ҫ���ҵ��������Ĺؼ���! \n");
	   		 scanf("%d %d",&e1,&e2);
			 BiTNode *low=LowestCommonAncestor(BiTrees.elem[num-1].T,e1,e2);
			 if(low) 
			 printf("��������Ϊ %d %s ! \n",low->data.key,low->data.others);
			 else 
			 printf("���Ҳ�����������! \n"); 
		}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;
		 memset(guanjianzi,0,sizeof(int)*100);    
		 getchar();getchar();
		 break;
		case 23:
		 printf("������������������!\n");
	   	scanf("%d",&num);
	   	if(num<=BiTrees.length&&num>0)
	   	{ 
			int invert=InvertTree(BiTrees.elem[num-1].T); 
			 if(invert==OK) 
			 printf("�����ֵܽ��ɹ� ! \n");
			 else 
			 printf("�����ڸö�����! \n"); 
		}
		 else printf("��Ŵ���! \n");
		 set=0;i=0;jishu=0;    
		 getchar();getchar();
		 break;  	
	}
	}
}
