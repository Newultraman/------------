#include "def.h"

status InitList(SqList& L)
//参数为:SqList &L 
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if(L.elem==NULL)
    {
    L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
    }
    else
    {
        L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return INFEASIBLE;
    }
}

status DestroyList(SqList& L)
//参数为:SqList &L 
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if(L.elem!=NULL)
    {
        free(L.elem);
        L.elem=NULL;
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}


status ClearList(SqList& L)
//参数为:SqList &L 
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        L.length=0;
        free(L.elem);
        L.elem=(ElemType *) malloc(sizeof(ElemType));
        return OK;
    }
}

status ListEmpty(SqList L)
//参数为:SqList L 
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        if(L.length==0) return TRUE;
        else return FALSE;
    }
}

status ListLength(SqList L)
//参数为:SqList L 
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if(L.elem==NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        return L.length;
    }
}


status GetElem(SqList L,int i,ElemType &e)
//参数为:SqList L,int i,ElemType &e 
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL)
    return INFEASIBLE;
    else if(i<1||i>L.length) return ERROR;
    else{
        e=L.elem[i-1];
        return OK;
    }
}

int LocateElem(SqList L,ElemType e)
//参数为:SqList L,ElemType e
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    if(L.elem==NULL) return -1;
    int flag=0,i;
    for(i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) {flag=1;break;}
    }
    if(flag==1) return i+1;
    else return ERROR;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
//参数为:SqList L,ElemType e,ElemType &pre 
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL) return -1;
    int flag=0,i;
    for(i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) {flag=1;break;}
    }
    if(flag==1&&i!=0)
    {
        pre=L.elem[i-1];
        return OK;
    }
    else return ERROR;
}


status NextElem(SqList L,ElemType e,ElemType &next)
//参数为:SqList L,ElemType e,ElemType &next
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
if(L.elem==NULL) return -1;
    int flag=0,i;
    for(i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) {flag=1;break;}
    }
    if(flag==1&&i!=L.length-1)
    {
        next=L.elem[i+1];
        return OK;
    }
    else return ERROR;
}

status ListInsert(SqList &L,int i,ElemType e)
//参数为:SqList &L,int i,ElemType e
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL) return -1;
    else
    {
        if(L.length==0&&i==1) {L.elem[0]=e;L.length++;return OK;}
        else if(i==L.length+1)
        {
            L.elem=(ElemType *)realloc(L.elem,sizeof(ElemType)*(L.length+1));
            L.elem[i-1]=e;
            L.length++;return OK;
        }
        else if(i>L.length+1||i<1) return ERROR;
        else 
        {
            L.elem=(ElemType *)realloc(L.elem,sizeof(ElemType)*(L.length+1));
            for(int k=L.length-1;k>=i-1;k--)
            {
                L.elem[k+1]=L.elem[k];
            }
        L.elem[i-1]=e;
        L.length++;
        return OK;
        }
    }
}


status ListDelete(SqList &L,int i,ElemType &e)
//参数为:SqList &L,int i,ElemType &e
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL) return -1;
    else if(i>L.length||i<1) return ERROR;
    else
    {
        if(i==L.length)
        {
            e=L.elem[i-1];
            int *p=L.elem+L.length-1;
            p=NULL;
            L.length--;
        }
        else
        {
            e=L.elem[i-1];
            for(int j=i;j<L.length;j++)
            {
                L.elem[j-1]=L.elem[j];
            }
            int *p=L.elem+L.length-1;
            p=NULL;
            L.length--;
        }
        return OK;
    }
}

status ListTraverse(SqList L)
//参数为:SqList L 
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if(L.elem==NULL) return -1;
    else if(L.length==0) return ERROR;
    else
    {
        for(int i=0;i<L.length-1;i++)
        {
            printf("%d ",L.elem[i]);
        }
        printf("%d",L.elem[L.length-1]);
        return OK;
    }
}

status  SaveList(SqList L,char FileName[])
//参数为:SqList L,char FileName[]
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    if(L.elem==NULL) return -1;
    else
    {
        FILE *fp;
        fp=fopen(FileName,"wb+");
        fwrite(L.elem,sizeof(int),L.length,fp);
        fclose(fp);
        return OK;
    }
}
status  LoadList(SqList &L,char FileName[])
//参数为:SqList &L,char FileName[]
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    if(L.elem!=NULL) return -1;
    FILE *fp;
    fp=fopen(FileName,"rb+");
    L.length=0;
    L.elem=(ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    int temp;
    int cnt=1;
    while(fread(&temp,sizeof(ElemType),1,fp))
    {
		ListInsert(L,cnt++,temp);
	}
    fclose(fp);
    return OK;
}

status AddList(LISTS &Lists,char ListName[])
//参数为:LISTS &Lists,char ListName[]
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    InitList(Lists.elem[Lists.length].L);
    int i=0;
    while(ListName[i]!='\0')
    {
    Lists.elem[Lists.length].name[i]=ListName[i];
    i++;
    }
    Lists.elem[Lists.length].name[i]='\0';
    Lists.length++;
}

status RemoveList(LISTS &Lists,char ListName[])
//参数为:LISTS &Lists,char ListName[]
// Lists中删除一个名称为ListName的线性表
{
    int i,num=Lists.length;
    for(i=0;i<Lists.length;i++)
    {
        int j=0;
        if(Lists.elem[i].name[j]==ListName[j])
        { 
            int str=0;
            while(ListName[str]!='\0') str++;
            while(Lists.elem[i].name[j]==ListName[j])
            {
                if(j==str) break;
                j++;
            }
            if(j==str)
            {
				DestroyList(Lists.elem[i].L);
                for(int k=i;k<Lists.length-1;k++)
                {
                	Lists.elem[k]=Lists.elem[k+1];
                    /*for(int i=0;i<Lists.elem[k+1].L.length;i++)
                    {
                        Lists.elem[k].L.elem[i]=Lists.elem[k+1].L.elem[i];
                    }
                    Lists.elem[k].L.length=Lists.elem[k+1].L.length;
                    str=0;
                    while(Lists.elem[k+1].name[str]!='\0') str++;
                    for(int n=0;n<str;n++)
                    Lists.elem[k].name[n]=Lists.elem[k+1].name[n];*/
                }
                //DestroyList(Lists.elem[Lists.length-1].L);
                Lists.elem[Lists.length-1].L.elem=NULL;
                Lists.length--;
                i--;
            }
        }
    }
    if(num==Lists.length) return ERROR;
    else return OK;
}


status LocateList(LISTS Lists,char ListName[])
//参数为:LISTS Lists,char ListName[]
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    int i,num=Lists.length;
    for(i=0;i<Lists.length;i++)
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
            if(j==str) {num--;return i+1;}
        }
    }
    if(num==Lists.length) return 0;
}

int MaxSubArray(SqList L)
//参数为:SqList L 
//最大连续子数组和 ,返回最大连续子数组的和. 
{
	if(L.elem==NULL) return -1;
	else
	{
		int max=0;
		int num=0;
		for(int i=0;i<L.length;i++)
		{
			if(num<=0)
			{
				num=L.elem[i];
			}
			else
			{
				num+=L.elem[i];
			}
			if(num>max)
			{
				max=num;
			}
		}
		return max;
	}
}


int SubArrayNum(SqList L,int k)
//参数为:SqList L,int k
//和为K的子数组数量 ,返回和为K的连续子数组数量 
{
	if(L.elem==NULL) return -1;
	int sum=0,ans=0;
	for(int i=0;i<L.length;i++)
	{
		sum=0;
		for(int j=i;j<L.length;j++)
		{
			sum+=L.elem[j];
			if(sum==k) ans++;
		}
	}
	return  ans;
}

int sortList(SqList &L)
//参数为:SqList &L
//排序,返回的值为OK 
{
	if(L.elem==NULL) return -1;
	else
	{
		int temp;
		for(int i=0;i<L.length-1;i++)
		{
			for(int j=i+1;j<L.length;j++)
			{
				if(L.elem[i]>L.elem[j])
				{
					temp=L.elem[i];
					L.elem[i]=L.elem[j];
					L.elem[j]=temp;
				}
			}
		}
		return OK;
	}
}

void WatchList(LISTS Lists)
//输出现有线性表的序列 
{
	if(Lists.length==0) printf("不存在顺序表! \n");
	for(int i=0;i<Lists.length;i++)
	{
		printf("%s\n",Lists.elem[i].name);
	}
 } 
