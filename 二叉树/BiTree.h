#include "def1.h"

int set=0; 
int jishu=0;
char kong[]="null";
int guanjianzi[100];

void zaikong(BiTree flag[])
{
	for(int i=0;i<100;i++)
	{
		flag[i]=NULL;
	}
}

status jiguanjianzi(BiTree T,int num,int guanjianzi[])
{
	if(T!=NULL)
	{
		guanjianzi[num]=T->data.key;
		jiguanjianzi(T->lchild,num*2,guanjianzi);
		jiguanjianzi(T->rchild,num*2+1,guanjianzi);
	}
	jishu=max(jishu,(num-1)/2);
	return 0;
}

status zairu(BiTree T,int num,BiTree flag[])
{
	if(T!=NULL)
    {
        flag[num]=(BiTNode *)malloc(sizeof(BiTNode));
        flag[num]->data=T->data;
        flag[num]->lchild=NULL;
        flag[num]->rchild=NULL;
        zairu(T->lchild,num*2,flag);
        zairu(T->rchild,num*2+1,flag);
    }
    jishu=max(jishu,(num-1)/2);
    return OK;
}

status DestroyBiTree(BiTree &T)
//����Ϊ BiTree &T
//���������T����,���ٶ�����,������Tָ���. 
{
   if(set==0)
   {
   	set=1;
   	if(T==NULL) return ERROR;
   }
   if (T)
   {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T=NULL;
   }
   return OK;
}

status BiTreeEmpty(BiTree T)
//����ΪBiTree T
// ���������T���ڣ��ж϶�����T�Ƿ�Ϊ�գ��վͷ���TRUE��\
���򷵻�FALSE�����������T�����ڣ�����INFEASIBLE��
{
    if(T==NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        if(T->lchild==NULL&&T->rchild==NULL
		&&strlen(T->data.others)==0) 
		return TRUE;
        else return FALSE;
    }
}

BiTNode* LocateNode(BiTree T,KeyType e)
//����Ϊ BiTree T,KeyType e
//���ҽ��
{
    BiTree Pl,Pr;
    Pl=(BiTNode *)malloc(sizeof(BiTNode)*1);
    Pr=(BiTNode *)malloc(sizeof(BiTNode)*1);
    if(T==NULL) return NULL;
    if(T->data.key==e) return T;
    else
    {
        Pl=LocateNode(T->lchild,e);
        Pr=LocateNode(T->rchild,e);
    }
    if(Pl)
    return Pl;
    else
    return Pr;
}

status Assign(BiTree &T,KeyType e,TElemType value)
//����Ϊ BiTree &T,KeyType e,TElemType value
//ʵ�ֽ�㸳ֵ��
{
    if(set==0)
    {
    	if(T==NULL) return -1;
    	else if(!(T->data.key)) {return 0;}
    	jiguanjianzi(T,1,guanjianzi);
    	set=1;
    	int j;
    	for(j=1;j<=jishu;j++)
    	{
    		if(guanjianzi[j]==e) break;
		}
		if(j==jishu+1) return ERROR;
    	for(int i=1;i<=jishu;i++)
    	{
    		if(value.key==guanjianzi[i]
			&&e!=value.key) 
			return ERROR;
		}
	}
	if(T==NULL) return OK;
	if(T->data.key==e)
	{
		T->data.key=value.key;
		strcpy(T->data.others,value.others);
		return OK;
	}
	else
	{
		Assign(T->lchild,e,value);
		Assign(T->rchild,e,value);
	}
	return OK;
}

BiTNode* GetSibling(BiTree T,KeyType e)
//����Ϊ BiTree T,KeyType e
//ʵ�ֻ���ֵܽ��
{
    if(T==NULL) return NULL;
    BiTree ltemp=T->lchild,rtemp=T->rchild;
    if(ltemp==NULL&&rtemp==NULL)
    {
        return NULL;
    }
    else if(ltemp!=NULL&&rtemp==NULL)
    {
        if(ltemp->data.key==e)
        {
            return NULL;
        }
        else
        {
            return GetSibling(ltemp,e);
        }
    }
    else if(ltemp==NULL&&rtemp!=NULL)
    {
        if(rtemp->data.key==e)
        {
            return NULL;
        }
        else
        {
            return GetSibling(rtemp,e);
        }
    }
    else
    {
        if(ltemp->data.key==e)
        {
            return rtemp;
        }
        else if(rtemp->data.key==e)
        {
            return ltemp;
        }
        else
        {
            BiTree left,right;
            left=GetSibling(ltemp,e);
            right=GetSibling(rtemp,e);
            if(right==NULL&&left==NULL)
                return NULL;
            else if(right!=NULL) return right;
            else return left;
        }
    }
}

status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//����Ϊ BiTree &T,KeyType e,int LR,TElemType c
//�����㡣
{
	if(set==0)
    {
    	if(T==NULL) return -1;
    	else if(!(T->data.key)) {return 0;}
    	jiguanjianzi(T,1,guanjianzi);
    	set=1;
    	int j;
    	for(j=1;j<=jishu;j++)
    	{
    		if(guanjianzi[j]==e) break;
		}
		if(j==jishu+1) return ERROR;
		for(j=1;j<=jishu;j++)
		{
			if(c.key==guanjianzi[j]) 
			return ERROR;
		}
	}
	if(T==NULL) return OK;
	BiTree C;
    C=(BiTNode *)malloc(sizeof(BiTNode));
    C->data=c;
    C->lchild=NULL;
    C->rchild=NULL; 
    if(LR==-1)
    {
        if(T!=NULL)
        {
        C->rchild=T;
        T=C;
        return OK;
        }
        else return ERROR;
    }
    else if(LR==0)//����
	{
		if(T->data.key==e)
		{
			C->rchild=T->lchild;
			T->lchild=C;
			return OK;	
		}
		else
		{
			InsertNode(T->lchild,e,LR,c);
			InsertNode(T->rchild,e,LR,c);
			return OK;
		}	
	}
	else
	{
		if(T->data.key==e)
		{
			C->rchild=T->rchild;
			T->rchild=C;
			return OK;	
		}
		else
		{
			InsertNode(T->lchild,e,LR,c);
			InsertNode(T->rchild,e,LR,c);
			return OK;
		}	
	} 
}

status DeleteNode(BiTree &T,KeyType e)
//����Ϊ BiTree &T,KeyType e
//ɾ����㡣
{
	if(set==0)
   {
   	if(!(T->data.key)) {return 0;}
   	jiguanjianzi(T,1,guanjianzi);
    	set=1;
    	int j;
    	for(j=1;j<=jishu;j++)
    	{
    		if(guanjianzi[j]==e) break;
		}
		if(j==jishu+1) return ERROR;
   	if(T==NULL) return -1;
   	if(e==T->data.key) 
    {
        if(T->lchild==NULL&&T->rchild==NULL)
        {
            free(T);
            T=NULL;
            return OK;
        }
        else if(T->lchild!=NULL&&T->rchild==NULL)
        {
            BiTree past;
            past=T;
            T=T->lchild;
            free(past);
            return OK;
        }
        else if(T->lchild==NULL&&T->rchild!=NULL)
        {
            BiTree past;
            past=T;
            T=T->rchild;
            free(past);
            return OK;
        }
        else
        {
            BiTree right=T->lchild;
            while(right->rchild)
            {
                right=right->rchild;
            }
            right->rchild=T->rchild;
            BiTree past;
            past=T;
            T=T->lchild;
            free(past);
            return OK;
        }
    }
   }
    if(T==NULL) return OK;
    BiTree ltemp=T->lchild,rtemp=T->rchild;
    if(ltemp==NULL&&rtemp==NULL)
    {
        if(T->data.key==e)
        {
            free(T);
            T=NULL;
            return OK;
        }
        else return OK;
    }
    else if(ltemp==NULL&&rtemp!=NULL)
    {
        if(rtemp->data.key==e)
        {
            if(rtemp->rchild==NULL
			&&rtemp->lchild==NULL)
            {
                free(rtemp);
                T->rchild=NULL;
                return OK;
            }
            else if(rtemp->rchild!=NULL
			&&rtemp->lchild==NULL)
            {
                T->rchild=rtemp->rchild;
                free(rtemp);
                return OK;
            }
            else if(rtemp->rchild==NULL
			&&rtemp->lchild!=NULL)
            {
                T->rchild=rtemp->lchild;
                free(rtemp);
                return OK;
            }
            else
            {
                T->rchild=rtemp->lchild;
                BiTree right=rtemp->lchild;
                while(right->rchild)
                {
                    right=right->rchild;
                }
                right->rchild=rtemp->rchild;
                free(rtemp);
                return OK;
            }
        }
        else
        {
            DeleteNode(rtemp,e);
            return OK;
        }
    }
    else if(ltemp!=NULL&&rtemp==NULL)
    {
        if(ltemp->data.key==e)
        {
            if(ltemp->rchild==NULL
			&&ltemp->lchild==NULL)
            {
                free(ltemp);
                T->lchild=NULL;
                return OK;
            }
            else if(ltemp->rchild!=NULL
			&&ltemp->lchild==NULL)
            {
                T->lchild=ltemp->rchild;
                free(ltemp);
                return OK;
            }
            else if(ltemp->rchild==NULL
			&&ltemp->lchild!=NULL)
            {
                T->lchild=ltemp->lchild;
                free(ltemp);
                return OK;
            }
            else
            {
                T->lchild=ltemp->lchild;
                BiTree right=ltemp->lchild;
                while(right->rchild)
                {
                    right=right->rchild;
                }
                right->rchild=ltemp->rchild;
                free(ltemp);
                return OK;
            }
        }
        else
        {
            DeleteNode(ltemp,e);
            return OK;
        }
    }
    else
    {
        if(ltemp->data.key!=e&&rtemp->data.key!=e)
        {
            DeleteNode(ltemp,e);
            DeleteNode(rtemp,e);
            return OK;
        }
        else if(ltemp->data.key==e)
        {
            if(ltemp->rchild==NULL
			&&ltemp->lchild==NULL)
            {
                free(ltemp);
                T->lchild=NULL;
                return OK;
            }
            else if(ltemp->rchild!=NULL
			&&ltemp->lchild==NULL)
            {
                T->lchild=ltemp->rchild;
                free(ltemp);
                return OK;
            }
            else if(ltemp->rchild==NULL
			&&ltemp->lchild!=NULL)
            {
                T->lchild=ltemp->lchild;
                free(ltemp);
                return OK;
            }
            else
            {
                T->lchild=ltemp->lchild;
                BiTree right=ltemp->lchild;
                while(right->rchild)
                {
                    right=right->rchild;
                }
                right->rchild=ltemp->rchild;
                free(ltemp);
                return OK;
            }
            
        }
        else
        {
             if(rtemp->rchild==NULL
			 &&rtemp->lchild==NULL)
            {
                free(rtemp);
                T->rchild=NULL;
                return OK;
            }
            else if(rtemp->rchild!=NULL
			&&rtemp->lchild==NULL)
            {
                T->rchild=rtemp->rchild;
                free(rtemp);
                return OK;
            }
            else if(rtemp->rchild==NULL
			&&rtemp->lchild!=NULL)
            {
                T->rchild=rtemp->lchild;
                free(rtemp);
                return OK;
            }
            else
            {
                T->rchild=rtemp->lchild;
                BiTree right=rtemp->lchild;
                while(right->rchild)
                {
                    right=right->rchild;
                }
                right->rchild=rtemp->rchild;
                free(rtemp);
                return OK;
            }
        }
    }
}

status PreOrderTraverse(BiTree T,void (*visit)(BiTree))
//����Ϊ BiTree T,void (*visit)(BiTree)
//�������������T
{
	if(T==NULL) return -1;
	else if(!(T->data.key)) return ERROR; 
    struct BiTNode * St[100],*p;
    int top=0;                        //�ÿ�ջ
    if(T!=NULL)
    {
        St[top++]=T;
        while(top)
        {
            p=St[--top];
            visit(p); 
            if(p->rchild!=NULL)
            {
                St[top++]=p->rchild;//�Ƚ��ҽڵ�
            }
            if(p->lchild!=NULL)
            {
                St[top++]=p->lchild;//�Ƚ���ڵ�
            }
        }
    }
    return OK;
}

status InOrderTraverse(BiTree T,void (*visit)(BiTree))
//����Ϊ BiTree T,void (*visit)(BiTree)
//�������������T
{
	if(set==0)
   {
   	set=1;
   	if(T==NULL) return -1;
   	else if(!(T->data.key)) return ERROR;
   }
    if(T==NULL) return OK;
    InOrderTraverse(T->lchild,visit);
    visit(T);
    InOrderTraverse(T->rchild,visit);
    return OK;
}

status PostOrderTraverse(BiTree T,void (*visit)(BiTree))
//����Ϊ BiTree T,void (*visit)(BiTree)
//�������������T
{
	if(set==0)
   {
   	set=1;
   	if(T==NULL) return -1;
   	else if(!(T->data.key)) return ERROR;
   }
    if(T==NULL) return OK;
    PostOrderTraverse(T->lchild,visit);
    PostOrderTraverse(T->rchild,visit);
    visit(T);
    return OK;
}

status LevelOrderTraverse(BiTree T,void (*visit)(BiTree))
//����Ϊ BiTree T,void (*visit)(BiTree)
//�������������T
{
	if(!(T->data.key)) return ERROR;
	BiTNode *flag[100];
	zaikong(flag);
    if(T!=NULL) 
    {
        zairu(T,1,flag);
    }
    else return -1;
    for(int i=1;i<=jishu;i++)
    {
        if(flag[i])
        visit(flag[i]);
    }
    jishu=0;
    return OK;
}

status LocateBiTree(BITREES &BiTrees,char BiTreeName[])
//����ΪBITREES &BiTrees,char BiTreeName[]
// ��BiTrees�в���һ������ΪBiTreeName�Ķ�������\
�ɹ������߼���ţ����򷵻�0
{
    int i,num=BiTrees.length;
    for(i=0;i<BiTrees.length;i++)
    {
        int j=0;
        if(BiTrees.elem[i].name[j]==BiTreeName[j])
        { 
            int str=0;
            while(BiTrees.elem[i].name[str]!='\0') str++;
            while(BiTrees.elem[i].name[j]==BiTreeName[j])
            {
                if(j==str) break;
                j++;
            }
            if(j==str) {num--;return i+1;}
        }
    }
    if(num==BiTrees.length) return 0;
}

void WatchBiTree(BITREES &BiTrees)
//����ΪBITREES &BiTrees 
//������ж����������� 
{
	if(BiTrees.length==0) printf("�����ڶ�����! \n");
	for(int i=0;i<BiTrees.length;i++)
	{
		printf("%s\n",BiTrees.elem[i].name);
	}
 } 
 
status SaveBiTree(BiTree T, char FileName[])
//����Ϊ BiTree T, char FileName[]
//���������Ľ������д�뵽�ļ�FileName��.
{
	if(T==NULL) return -1;
	BiTNode *pos[100];
	for(int i=0;i<100;i++)
	{
		pos[i]=(BiTNode *)malloc(sizeof(BiTNode));
		pos[i]->lchild=NULL;
        pos[i]->rchild=NULL;
        pos[i]->data.key=0;
        strcpy(pos[i]->data.others,kong);
	}
	zairu(T,1,pos);
    FILE *fp;
    fp=fopen(FileName,"wb");
    for(int i=1;i<=jishu;i++)
    {
    	fwrite(&(pos[i]->data),sizeof(TElemType),1,fp);
    }
    fclose(fp);
    return OK;
}

status LoadBiTree(BiTree &T,  char FileName[])
//����Ϊ BiTree &T, char FileName[]
//�����ļ�FileName�Ľ�����ݣ�����������
{
    if(T!=NULL) return ERROR;
    FILE *fp;
    fp=fopen(FileName,"rb");
    BiTree rea[100];
    int i=1;
    TElemType temp;
    while(fread(&temp,sizeof(TElemType),1,fp))
    {
        rea[i]=(BiTNode *)malloc(sizeof(BiTNode));
        rea[i]->lchild=NULL;
        rea[i]->rchild=NULL;
        rea[i]->data=temp;
        if(i!=1)
        {
                if(i%2) 
                {
                    rea[i/2]->rchild=rea[i];
                    if((rea[i]->data.key)==0)
                    rea[i/2]->rchild=NULL;
                }
                else 
                {
                    rea[i/2]->lchild=rea[i];
                    if((rea[i]->data.key)==0)
                    rea[i/2]->lchild=NULL;
                }
        }
        i++;
    }
    T=rea[1];
    fclose(fp);
    return OK;
}

status MaxPathSum(BiTree T)
//����Ϊ BiTree T
//����ڵ㵽Ҷ�ӽ������·���� 
{
	if(set==0)
	{
		if(T==NULL) return -1;
		set=1;
	}
	if(T==NULL) return 0;
	int left=MaxPathSum(T->lchild);
	int right=MaxPathSum(T->rchild);
	int maxnum=max(right,left);
	return maxnum+T->data.key;
}

BiTNode *LowestCommonAncestor(BiTree T,int e1,int e2)
//����ΪBiTree T,int e1,int e2
//������������� 
{
	if(set==0)
	{
		if(T==NULL) return NULL;
		set=1;
	jiguanjianzi(T,1,guanjianzi);
	int i,j;
	for(i=1;i<=jishu;i++)
	{
		if(e1==guanjianzi[i]) break;
	}
	for(j=1;j<=jishu;j++)
	{
		if(e2==guanjianzi[j]) break;
	}
	if(i==jishu+1&&j==jishu+1) return NULL;
	}
	if(T==NULL||T->data.key==e1||T->data.key==e2)
	{
		return T;
	}
	BiTree left=LowestCommonAncestor(T->lchild,e1,e2);
	BiTree right=LowestCommonAncestor(T->rchild,e1,e2);
	if(left&&right) 
	{
		return T;
	}
	if(left) return left;
	if(right) return right;
	return NULL;
}
 
status  InvertTree(BiTree &T)
//����Ϊ BiTree &T
//�ֵܽ�㻥�� 
{
	if(T==NULL) return -1;
	static BiTNode *poss[100];
	zaikong(poss);
	zairu(T,1,poss);
	for(int i=1;i<=jishu;i++)
	{
		if(poss[i])
		{
			if(poss[i*2]) poss[i]->rchild=poss[i*2];
			if(poss[i*2+1]) poss[i]->lchild=poss[i*2+1];
		}
	}
	T=poss[1];
	return OK;
}
