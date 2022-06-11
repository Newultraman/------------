#include "def1.h"

status InitList(LinkList &L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    if(L==NULL) 
    {
        L=(LinkList)malloc(sizeof(LNode));
        L->next=NULL;
        return OK;
    }
    else return -1;
}

status DestroyList(LinkList &L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬\
����OK�����򷵻�INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        LinkList p1,p2;
        p1=L,p2=L->next;
        while(p2)
        {
            free(p1);
            p1=p2;
            p2=p2->next;
        }
        free(p1);
        L=NULL;
        return OK;
    }
}


status ClearList(LinkList &L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�\
����OK�����򷵻�INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        if(!L->next) return OK;
        LinkList p1,p2;
        p1=L->next,p2=p1->next;
        while(p2)
        {
            free(p1);
            p1=p2;
            p2=p2->next;
        }
        free(p1);
        L->next=NULL;
        return OK;
    }
}

status ListEmpty(LinkList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��\
������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        if(!L->next) return OK;
        else return FALSE;
    }
}

int ListLength(LinkList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        int length=0;
        LinkList p;
        p=L->next;
        while(p)
        {
            p=p->next;
            length++;
        }
        return length;
    }
}

status GetElem(LinkList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK��\
���i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        if(i<1||i>ListLength(L))
        {
            return ERROR;
        }
        else
        {
            LinkList p;
            p=L;
            for(int j=1;j<=i;j++)
            {
                p=p->next;
            }
            e=p->data;
            return OK;
        }
    }
}

status LocateElem(LinkList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����ţ�\
���e�����ڣ�����ERROR�������Ա�L������ʱ������INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        int i=1;
        LinkList p;
        p=L->next;
        while(p)
        {
            if(p->data==e)
            {
                return i;
            }
            else
            {
                p=p->next;
                i++;
            }
        }
        return ERROR;
    }
}

status PriorElem(LinkList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK��\
���û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        LinkList p,before;
        if(!L->next||!L->next->next)
        {
            return ERROR;
        }
        else
        {
            p=L->next,before=L;
            if(p->data==e) return ERROR;
            while(p)
            {
                if(p->data==e)
                {
                    pre=before->data;
                    return OK;
                }
                else
                {
                    before=p;
                    p=p->next;
                }
            }
            return ERROR;
        }
    }
}

status NextElem(LinkList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK��\
���û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else 
    {
        if(!L->next||!L->next->next)
        {
            return ERROR;
        }
        else
        {
            LinkList p,after;
            p=L,after=p->next;
            while(after)
            {
                if(p->data==e)
                {
                    next=after->data;
                    return OK;
                }
                else
                {
                    p=after;
                    after=after->next;
                }
            }
            return ERROR;
        }
    }
}

status ListInsert(LinkList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��\
������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else 
    {
        if(i<1||i>ListLength(L)+1) return ERROR;
        LinkList p;
        p=L;
        for(int j=1;j<i;j++)
        {
            p=p->next;
        }
        LinkList add;
        add=(LinkList)malloc(sizeof(LNode));
        add->data=e;
        add->next=p->next;
        p->next=add;
        return OK;
    }
}

status ListDelete(LinkList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK��\
��ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else 
    {
        if(!L->next) return ERROR;
        if(i<1||i>ListLength(L)) return ERROR;
        LinkList p,before;
        before=L,p=L->next;
        for(int j=1;j<=i-1;j++)
        {
            before=before->next;
            p=p->next;
        }
        e=p->data;
        before->next=p->next;
        free(p);
        return OK;
    }
}

status ListTraverse(LinkList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��\
������Ա�L�����ڣ�����INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        if(!L->next) return OK;
        LinkList p;
        p=L->next;
        while(p->next)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d",p->data);
        return OK;
    }
}


status SaveList(LinkList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�\ 
����OK,���򷵻�INFEASIBLE��
{
    if(L==NULL) return -1;
    else
    {
        FILE *fp;
        fp=fopen(FileName,"wb");
        LinkList p;
        p=L->next;
        while(p)
        {
            fwrite(&(p->data),sizeof(int),1,fp);
            p=p->next;
        }
        fclose(fp);
        return OK;
    }
}

status LoadList(LinkList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�\
����OK�����򷵻�INFEASIBLE��
{
    if(L!=NULL) {return -1;}
    else
    {
        FILE *fp;
        fp=fopen(FileName,"rb");
        LinkList p,tail,before;
        L=(LinkList)malloc(sizeof(LNode));
        p=(LinkList)malloc(sizeof(LNode));
        L->next=p;
        int flag=1,num;
        while(flag)
        {
            if(flag=fread(&num,sizeof(int),1,fp))
            {
            p->data=num;
            tail=(LinkList)malloc(sizeof(LNode));
            before=p;
            p->next=tail;
            p=tail;
            }
            else break;
        }
        before->next = NULL;
        fclose(fp);
        return OK;
    }
}

status reverseList(LinkList &L)
//��������з�ת 
{
	if(L==NULL) return -1;
	if(L->next==NULL) return ERROR;
	int len=ListLength(L);
	ElemType a[len+1];
	LinkList p;
	p=L->next;
	int i;
	for(i=1;i<len;i++)
	{
		a[i]=p->data;
		p=p->next;
	}
	a[i]=p->data;
	LinkList t;
	t=L->next;
	int j;
	for(j=len;j>1;j--)
	{
		t->data=a[j];
		t=t->next;
	}
	t->data=a[j];
	return OK;
}

status RemoveNthFrom(LinkList &L,int n,ElemType &e)
//ɾ������ĵ�����n���ڵ�,���洢��e��. 
{
	if(L==NULL) return -1;
	else if(L->next==NULL||n<=0) return ERROR;
	LinkList p;
	p=L;
	int len=ListLength(L);
	if(n>len) return -1;
	for(int i=0;i<len-n;i++)
	{
		p=p->next;
	}
	e=p->next->data;
	p->next=p->next->next;
	return OK;
}

status sortList(LinkList &L)
//������������� 
{
	if(L==NULL) return -1;
	int len=ListLength(L);
	ElemType a[len+1];
	LinkList p;
	p=L->next;
	int i; 
	for(i=1;i<len;i++)
	{
		a[i]=p->data;
		p=p->next;
	}
	a[i]=p->data;
	ElemType temp;
	LinkList t;
	for(int i=1;i<len;i++)
	{
		for(int j=i;j<=len;j++)
		{
			if(a[i]>a[j])
			{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}
		}
	}
	t=L->next;
	for(i=1;i<len;i++)
	{
		t->data=a[i];
		t=t->next;
	}
	t->data=a[i];
	return OK;
}

status AddList(LISTS &Lists,char ListName[])
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ�����.
{
	InitList(Lists.elem[Lists.num].L);
	int i=0;
	while(ListName[i]!='\0')
    {
    Lists.elem[Lists.num].name[i]=ListName[i];
    i++;
	}
	Lists.elem[Lists.num].name[i]='\0';
    Lists.num++;
    return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
//ɾ��һ������ΪListName������ 
{
	int i,nu=Lists.num;
    for(i=0;i<Lists.num;i++)
    {
        int j=0;
        if(Lists.elem[i].name[j]==ListName[j])
        { 
            int str=0;
            while(ListName[str]!='\0') str++;
            while(Lists.elem[i].name[j]
			==ListName[j])
            {
                if(j==str) break;
                j++;
            }//�ж������Ƿ�һ�� 
            if(j==str)
            {
            	LinkList t,p,tail;
            	if(Lists.elem[i].L==NULL) 
            	{
            		InitList(Lists.elem[i].L);
				}
                for(int k=i;k<Lists.num-1;k++)
                {
                    //���н���k+1�������Ƶ���k������
					DestroyList(Lists.elem[k].L);
					InitList(Lists.elem[k].L);
					t=Lists.elem[k].L;
					p=Lists.elem[k+1].L->next;
					while(p)
					{
					tail=(LinkList)malloc(sizeof(LNode));
						t->next=tail;
						tail->data=p->data;
						p=p->next;
						t=tail;
					}
					//free(tail);
					tail=NULL;
					t->next=NULL;
                    //���������ֵĸ��� 
                    str=0;
                    while(Lists.elem[k+1].name[str]!='\0') 
					str++;
                    for(int n=0;n<str;n++)
                    Lists.elem[k].name[n]=
					Lists.elem[k+1].name[n];
                }
                DestroyList(Lists.elem[Lists.num-1].L);
                Lists.num--;
                i--;
            }
        }
    }
    if(nu==Lists.num) return ERROR;
    else return OK;
}

status LocateList(LISTS &Lists,char ListName[])
//��Lists�в���һ������ΪListName�������ɹ������߼���ţ����򷵻�0
{
	int i,nu=Lists.num;
    for(i=0;i<Lists.num;i++)
    {
        int j=0;
        if(Lists.elem[i].name[j]==ListName[j])
        { 
            int str=0;
        while(Lists.elem[i].name[str]!='\0') str++;
        while(Lists.elem[i].name[j]==ListName[j])
            {
                if(j==str) break;
                j++;
            }
            if(j==str) {nu--;return i+1;}
        }
    }
    if(nu==Lists.num) return 0;
}

void WatchList(LISTS Lists)
//���������������� 
{
	if(Lists.num==0) printf("û��������! \n");
	for(int i=0;i<Lists.num;i++)
	{
		printf("%s\n",Lists.elem[i].name);
	}
}
