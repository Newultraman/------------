#include "def1.h"

status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
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
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，\
返回OK，否则返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L中的所有元素，\
返回OK，否则返回INFEASIBLE。
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
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；\
如果线性表L不存在，返回INFEASIBLE。
{
    if(L==NULL) return -1;
    else
    {
        if(!L->next) return OK;
        else return FALSE;
    }
}

int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；\
如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，查找元素e在线性表L中的位置序号；\
如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；\
如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；\
如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；\
当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；\
当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；\
如果线性表L不存在，返回INFEASIBLE。
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
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，\ 
返回OK,否则返回INFEASIBLE。
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
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，\
返回OK，否则返回INFEASIBLE。
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
//对链表进行翻转 
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
//删除链表的倒数第n个节点,并存储在e中. 
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
//对链表进行排序 
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
// 只需要在Lists中增加一个名称为ListName的空链表.
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
//删除一个名称为ListName的链表 
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
            }//判断名字是否一样 
            if(j==str)
            {
            	LinkList t,p,tail;
            	if(Lists.elem[i].L==NULL) 
            	{
            		InitList(Lists.elem[i].L);
				}
                for(int k=i;k<Lists.num-1;k++)
                {
                    //进行将第k+1个链表复制到第k个链表
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
                    //以下是名字的复制 
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
//在Lists中查找一个名称为ListName的链表，成功返回逻辑序号，否则返回0
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
//输出现有链表的序列 
{
	if(Lists.num==0) printf("没有链表了! \n");
	for(int i=0;i<Lists.num;i++)
	{
		printf("%s\n",Lists.elem[i].name);
	}
}
