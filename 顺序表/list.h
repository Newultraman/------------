#include "def.h"

status InitList(SqList& L)
//����Ϊ:SqList &L 
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
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
//����Ϊ:SqList &L 
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
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
//����Ϊ:SqList &L 
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
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
//����Ϊ:SqList L 
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList L 
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
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
//����Ϊ:SqList L,int i,ElemType &e 
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList L,ElemType e
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
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
//����Ϊ:SqList L,ElemType e,ElemType &pre 
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList L,ElemType e,ElemType &next
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList &L,int i,ElemType e
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList &L,int i,ElemType &e
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList L 
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
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
//����Ϊ:SqList L,char FileName[]
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
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
//����Ϊ:SqList &L,char FileName[]
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
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
//����Ϊ:LISTS &Lists,char ListName[]
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
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
//����Ϊ:LISTS &Lists,char ListName[]
// Lists��ɾ��һ������ΪListName�����Ա�
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
//����Ϊ:LISTS Lists,char ListName[]
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
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
//����Ϊ:SqList L 
//�������������� ,�����������������ĺ�. 
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
//����Ϊ:SqList L,int k
//��ΪK������������ ,���غ�ΪK���������������� 
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
//����Ϊ:SqList &L
//����,���ص�ֵΪOK 
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
//����������Ա������ 
{
	if(Lists.length==0) printf("������˳���! \n");
	for(int i=0;i<Lists.length;i++)
	{
		printf("%s\n",Lists.elem[i].name);
	}
 } 
