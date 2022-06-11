#include "def.h"

int biaozhi[100];
int zuiduan[50][50];
int num=0;
int guanjianzi[100]; 

void shanqu(KeyType VR[][2],int ii)
{
    while(VR[ii][0]!=-1)
    {
        VR[ii][0]=VR[ii+1][0];
        VR[ii][1]=VR[ii+1][1];
        ii++;
    }
}

status CreateGraph(ALGraph &G,VertexType V[],KeyType VR[][2])
//����Ϊ ALGraph &G,VertexType V[],KeyType VR[][2]
/*����V��VR����ͼT������OK�����V��VR����ȷ������ERROR
�������ͬ�Ĺؼ��֣�����ERROR��*/
{
    G.vexnum=0;
    G.arcnum=0;
    int i=0;
    if(V[0].key==-1) return ERROR;
    while(V[i].key!=-1)
    {
        guanjianzi[i]=V[i].key;
        for(int j=0;j<i;j++)
        {
            if(guanjianzi[j]==guanjianzi[i]) return ERROR;
        }
        i++;
    }//i����λ���ڵĸ���
    if(i>MAX_VERTEX_NUM) return ERROR;
    int k;
    for(k=0;k<i;k++)//����ͷ�ڵ��д��
    {
        G.vertices[k].data=V[k];
        G.vertices[k].firstarc=NULL;
        G.vexnum++;
    }
    G.vertices[k].data.key=-1;
    //�ж�ÿ�����Ƿ���ȷ
    int ii=0;
    while(VR[ii][0]!=-1)
    {
        int jj;
        for(jj=0;jj<i;jj++)
        {
            if(VR[ii][0]==V[jj].key) break;
        }
        if(jj!=i)
        {
           for(jj=0;jj<i;jj++)
           {
               if(VR[ii][1]==V[jj].key) break;
           }
           if(jj==i) return ERROR; 
        }
        else return ERROR;
        jj=0;
        for(int kk=0;kk<ii;kk++)
        {
            if(VR[kk][0]==VR[ii][1]&&VR[kk][1]==VR[ii][0])//�෴
            {
                shanqu(VR,ii);
                ii--;
                G.arcnum++;
                break;
            } 
            else if(VR[kk][0]==VR[ii][0]&&VR[kk][1]==VR[ii][1])//��ͬ
            {
                shanqu(VR,ii);
                ii--;
                G.arcnum++;
                break;
            }
        }
        ii++;
    }
    int j=0;
    for(int k=0;k<i;k++)
    {
        while(VR[j][0]!=-1)//��VR���б���
        {
            if(VR[j][0]==G.vertices[k].data.key)//ǰ��
            {
                for(int kk=0;kk<i;kk++)
                {
                    if(VR[j][1]==G.vertices[kk].data.key&&kk!=k)
                    {
                        ArcNode *temp;
                    temp=(ArcNode *)malloc(sizeof(ArcNode));
                    temp->adjvex=kk;
                    temp->nextarc=G.vertices[k].firstarc;
                    G.vertices[k].firstarc=temp;
                    G.arcnum++;
                    break;
                    }
                    else if(VR[j][1]==G.vertices[kk].data.key&&kk==k)
                    {
                        G.arcnum++;break;
                    }
                }
            }
            else if(VR[j][1]==G.vertices[k].data.key)//���
            {
                for(int kk=0;kk<i;kk++)
                {
                    if(VR[j][0]==G.vertices[kk].data.key&&kk!=k)
                    {
                        ArcNode *a;
                    a=(ArcNode *)malloc(sizeof(ArcNode));
                    a->adjvex=kk;
                    a->nextarc=G.vertices[k].firstarc;
                    G.vertices[k].firstarc=a;
                    break;
                    }
                    else if(VR[j][0]==G.vertices[kk].data.key&&kk==k)
                    {
                        G.arcnum++;break;
                    }
                }
            }
            j++;
        }
        j=0;
    }
    return OK;
}

status DestroyGraph(ALGraph &G)
//����Ϊ ALGraph &G
/*��������ͼG,ɾ��G��ȫ������ͱ�*/
{
    ArcNode *p1,*p2;
    int i=0;
    //printf("haha");
    while(G.vertices[i].data.key!=-1)
    {
        p1=G.vertices[i].firstarc;
        if(p1)//ֻ��һ����
        {
            p2=p1->nextarc;
            while(p2)
            {
                free(p1);
                p1=p2;
                p2=p2->nextarc;
            }
            free(p1);
            G.vertices[i].firstarc=NULL;
        }
        i++;
    }
    G.arcnum=0;G.vexnum=0;
    return OK;
}

int LocateVex(ALGraph G,KeyType u)
//����Ϊ ALGraph G,KeyType u
//����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
{
    int i;
    if(G.vexnum==0) return -1; 
    while(G.vertices[i].data.key!=-1)
    {
        if(u==G.vertices[i].data.key)
        {
            return i;
        }
        i++;
    }
    return -1;
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//����Ϊ ALGraph &G,KeyType u,VertexType value
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK��
//�������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
{
    if(u==-1) return ERROR;
    int i=0;
    while(G.vertices[i].data.key!=-1)
    {
        guanjianzi[i]=G.vertices[i].data.key;
        i++;
    } 
    int j=0,flag=0;
    for(j=0;j<i;j++)
    {
        if(guanjianzi[j]==value.key) 
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        if(u!=guanjianzi[j]) return ERROR;
    }
    i=0;
    while(G.vertices[i].data.key!=-1)
    {
        if(G.vertices[i].data.key==u)
        {
            G.vertices[i].data=value;
            return OK;
        }
        i++;
    }
    return ERROR;
}

status FirstAdjVex(ALGraph G,KeyType u)
//����Ϊ ALGraph G,KeyType u
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
{
    int i=0,j;
    while(G.vertices[i].data.key!=-1)
    {
        if(u==G.vertices[i].data.key)
        {
            if(G.vertices[i].firstarc)
            {
                return G.vertices[i].firstarc->adjvex;
            }
            else return -1;
        }
        i++;
    }
    return -1;
}

status NextAdjVex(ALGraph G,KeyType v,KeyType w)
//����Ϊ ALGraph G,KeyType v,KeyType w
//����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���v���ڽӶ��������w����һ�ڽӶ����λ�򣬲���ʧ�ܷ���-1��
{
    int i=0;
    while(G.vertices[i].data.key!=-1)
    {
        guanjianzi[i]=G.vertices[i].data.key;
        i++;
    }
    int j,k;
    for(j=0;j<i;j++)
    {
        if(v==G.vertices[j].data.key) break;
    }
    for(k=0;k<i;k++)
    {
        if(w==G.vertices[k].data.key) break;
    }
    if(j==i||k==i) return -1;
    ArcNode *p;
    p=G.vertices[j].firstarc;
    while(p)
    {
        if(k==p->adjvex) 
        {
            if(p->nextarc) return p->nextarc->adjvex;
            else return -1;
        }
        p=p->nextarc;
    }
    return -1;
}

status InsertVex(ALGraph &G,VertexType v)
//����Ϊ ALGraph &G,VertexType v
//��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
{
    int i=0;
    if(G.vexnum>=MAX_VERTEX_NUM) return ERROR;
    while(G.vertices[i].data.key!=-1)
    {
        if(v.key==G.vertices[i].data.key) return ERROR;
        i++;
    }
    G.vertices[i].data=v;
    G.vertices[i].firstarc=NULL;
    if(i!=MAX_VERTEX_NUM-1)
    {G.vertices[i+1].data.key=-1;
    G.vertices[i+1].firstarc=NULL;}
    G.vexnum++;
    return OK;
}

status DeleteVex(ALGraph &G,KeyType v)
//����Ϊ ALGraph &G,KeyType v
//��ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK,���򷵻�ERROR
{
    int i;
    if(G.vexnum==0||G.vexnum==1) return ERROR;
    for(i=0;i<G.vexnum;i++)
    {
        if(v==G.vertices[i].data.key) break;
    }
    if(i==G.vexnum) return ERROR;
    ArcNode *p1,*p2;
    p1=G.vertices[i].firstarc;
    if(p1)
    {
        p2=p1->nextarc;
        while(p2)
        {
            free(p1);
            p1=p2;
            p2=p2->nextarc;
            G.arcnum--;
        }
        free(p1);
        G.arcnum--;
        for(int j=0;j<G.vexnum;j++)//ɾ��
        {
            if(j!=i)
            {
                ArcNode *p,*pp;
                p=G.vertices[j].firstarc;
                if(p)
                {
                   if(p->adjvex==i) {G.vertices[j].firstarc=p->nextarc;free(p);}
                   else
                   {
                       pp=p->nextarc;
                       while(pp)
                       {
                           if(pp->adjvex==i) {p->nextarc=pp->nextarc;free(pp);break;}
                           p=pp;
                           pp=pp->nextarc;
                       }
                   }
                }
            }
        }
        for(int j=0;j<G.vexnum;j++)//�ı�
        {
            if(j!=i)
            {
                ArcNode *p;
                p=G.vertices[j].firstarc;
                while(p)
                {
                    if(p->adjvex>i) p->adjvex--;
                    p=p->nextarc;
                }
            }
        }
    }
    //ɾ��
    for(int j=i;j<G.vexnum;j++)
    {
        G.vertices[j]=G.vertices[j+1];
    }
    G.vexnum--;
    return OK;
}

status InsertArc(ALGraph &G,KeyType v,KeyType w)
//����Ϊ ALGraph &G,KeyType v,KeyType w
//��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
    {
        if(v==G.vertices[i].data.key) break;
    }
    for(j=0;j<G.vexnum;j++)
    {
        if(w==G.vertices[j].data.key) break;
    }
    if(i==G.vexnum||j==G.vexnum) return ERROR;
    //i��v��Ӧ�ı�ţ�j��w��Ӧ�ı��
    ArcNode *p;
    p=G.vertices[i].firstarc;
    while(p)
    {
        if(p->adjvex==j) return ERROR;
        p=p->nextarc;
    }
    p=G.vertices[i].firstarc;
    if(p==NULL)
    {
        G.vertices[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
        G.vertices[i].firstarc->adjvex=j;
        G.vertices[i].firstarc->nextarc=NULL;
    }
    else
    {
        ArcNode *t;
        t=(ArcNode *)malloc(sizeof(ArcNode));
        t->adjvex=j;
        t->nextarc=p;
        G.vertices[i].firstarc=t;
    }
    G.arcnum++;
    ArcNode *pp;
    pp=G.vertices[j].firstarc;
    if(pp==NULL)
    {
        G.vertices[j].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
        G.vertices[j].firstarc->adjvex=i;
        G.vertices[j].firstarc->nextarc=NULL;
    }
    else
    {
        ArcNode *tt;
        tt=(ArcNode *)malloc(sizeof(ArcNode));
        tt->adjvex=i;
        tt->nextarc=pp;
        G.vertices[j].firstarc=tt;
    }
    return OK;
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//����Ϊ ALGraph &G,KeyType v,KeyType w
//��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
{
    if(w==v) return ERROR;
     int i,j;
    for(i=0;i<G.vexnum;i++)
    {
        if(v==G.vertices[i].data.key) break;
    }
    for(j=0;j<G.vexnum;j++)
    {
        if(w==G.vertices[j].data.key) break;
    }
    if(i==G.vexnum||j==G.vexnum) return ERROR;
    //i��v��Ӧ�ı�ţ�j��w��Ӧ�ı��
    ArcNode *p;
    int flag=0;
    p=G.vertices[i].firstarc;
    while(p)
    {
        if(p->adjvex==j) flag=1;
        p=p->nextarc;
    }
    if(flag!=1) return ERROR;
    p=G.vertices[i].firstarc;
    if(p->adjvex==j) {G.vertices[i].firstarc=p->nextarc;free(p);}//��һ������
    else
    {
        while(p->nextarc)
        {
            if(p->nextarc->adjvex==j)
            {
                ArcNode *pp=p->nextarc;
                p->nextarc=p->nextarc->nextarc;
                free(pp);
                pp=NULL;
                break;
            }
            p=p->nextarc;
        } 
    }
    p=G.vertices[j].firstarc;
    if(p->adjvex==i) {G.vertices[j].firstarc=p->nextarc;free(p);}//��һ������
    else
    {
        while(p->nextarc)
        {
            if(p->nextarc->adjvex==i)
            {
                ArcNode *pp=p->nextarc;
                p->nextarc=p->nextarc->nextarc;
                free(pp);
                pp=NULL;
                break;
            }
            p=p->nextarc;
        } 
    }
    G.arcnum--;
    return OK;
}

void visit(VertexType v)
{
    printf(" %d %s",v.key,v.others);
}

void dfs(int i,void (*visit)(VertexType),ALGraph &G)
//����Ϊ int i,void (*visit)(VertexType),ALGraph &G
//��ͼ��һ����ͨ��������dfs
{
    visit(G.vertices[i].data);
    num++;
    biaozhi[i]=1;
    ArcNode *p;
    p=G.vertices[i].firstarc;
    while(p)
    {
        if(biaozhi[p->adjvex]==0) dfs(p->adjvex,visit,G);
        p=p->nextarc;
    }
}

void dfs1(int i,ALGraph &G)
//����Ϊ int i,ALGraph &G
//��ͼ��һ����ͨ��������dfs,����������� 
{
    //visit(G.vertices[i].data);
    num++;
    biaozhi[i]=1;
    ArcNode *p;
    p=G.vertices[i].firstarc;
    while(p)
    {
        if(biaozhi[p->adjvex]==0) dfs1(p->adjvex,G);
        p=p->nextarc;
    }
}

status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//����Ϊ ALGraph &G,void (*visit)(VertexType)
//��ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    if(G.vexnum==0) return ERROR;
    dfs(0,visit,G);
    while(num!=G.vexnum)
    {
        int j=0;
        while(biaozhi[j]!=0)
        {
            j++;
        }
        dfs(j,visit,G);
    }
    return OK;
}

void bfs(ALGraph &G,void (*visit)(VertexType),int i)
//����Ϊ ALGraph &G,void (*visit)(VertexType),int i
//��ͼ��һ����ͨ��������bfs 
{
    if(biaozhi[i]==0)
    {
    visit(G.vertices[i].data);
    num++;
    biaozhi[i]=1;
    }
    ArcNode *p;
    int flag=0;
    p=G.vertices[i].firstarc;
    while(p)
    {
        if(biaozhi[p->adjvex]==0) {visit(G.vertices[p->adjvex].data);num++;biaozhi[p->adjvex]=1;flag=1;}
        p=p->nextarc;
    }
    if(flag==0) return ;
    if(G.vertices[i].firstarc)
    bfs(G,visit,G.vertices[i].firstarc->adjvex);
    return ;
}

status BFSTraverse(ALGraph &G,void (*visit)(VertexType))
//����Ϊ ALGraph &G,void (*visit)(VertexType)
//��ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ��
{
    if(G.vexnum==0) return ERROR;
    bfs(G,visit,0);
    while(num!=G.vexnum)
    {
        int j=0;
        while(biaozhi[j]!=0)
        {
            j++;
        }
        bfs(G,visit,j);
    }
    return OK;
}

status AddGraph(GRAPHS &Graphs,char GraphName[],VertexType V[],KeyType VR[][2])
//����Ϊ GRAPHS &Graphs,char GraphName[],VertexType V[],KeyType VR[][2]
//����һ��ͼ 
{
	int creat;
	creat=CreateGraph(Graphs.elem[Graphs.length].G,V,VR);
	int i=0;
    while(GraphName[i]!='\0')
    {
    Graphs.elem[Graphs.length].name[i]=GraphName[i];
    i++;
    }
    Graphs.elem[Graphs.length].name[i]='\0';
    Graphs.length++;
    if(creat==ERROR) return ERROR;
    else return OK;
}

status RemoveGraph(GRAPHS &Graphs,char GraphName[])
//����Ϊ GRAPHS &Graphs,char GraphName[]
//ɾ��һ��ͼ 
{
	int i,num=Graphs.length;
    for(i=0;i<Graphs.length;i++)
    {
        int j=0;
        if(Graphs.elem[i].name[j]==GraphName[j])
        { 
            int str=0;
            while(GraphName[str]!='\0') str++;
        while(Graphs.elem[i].name[j]==GraphName[j])
            {
                if(j==str) break;
                j++;
            }
            if(j==str)
            {
            	DestroyGraph(Graphs.elem[i].G);
                for(int k=i;k<Graphs.length-1;k++)
                {
                	Graphs.elem[k]=Graphs.elem[k+1];
                }
                DestroyGraph(Graphs.elem[Graphs.length-1].G);
                Graphs.length--;
                i--;
            }
        }
    }
    if(num==Graphs.length) return ERROR;
    else return OK;
}

status LocateGraph(GRAPHS &Graphs,char GraphName[])
//����ΪGRAPHS &Graphs,char GraphName[]
// ����һ��ͼ 
{
    int i,num=Graphs.length;
    for(i=0;i<Graphs.length;i++)
    {
        int j=0;
        if(Graphs.elem[i].name[j]==GraphName[j])
        { 
            int str=0;
            while(Graphs.elem[i].name[str]!='\0') str++;
            while(Graphs.elem[i].name[j]==GraphName[j])
            {
                if(j==str) break;
                j++;
            }
            if(j==str) {num--;return i+1;}
        }
    }
    if(num==Graphs.length) return 0;
}

void WatchGraph(GRAPHS Graphs)
//����Ϊ GRAPHS Graphs
//���������ͼ�� 
{
	for(int i=0;i<Graphs.length;i++)
	{
		printf("%s\n",Graphs.elem[i].name);
	}	
}

status SaveGraph(ALGraph G, char FileName[])
//����Ϊ ALGraph G, char FileName[]
//��ͼ������д�뵽�ļ�FileName��
{
    int num=0;
    FILE *fp;
    fp=fopen(FileName,"wb");
    if(G.vexnum==0) return ERROR;
    fwrite(&(G.vexnum),sizeof(int),1,fp);
    for(int i=0;i<G.vexnum;i++)
    {
        fwrite(&(G.vertices[i].data),sizeof(VertexType),1,fp);
        ArcNode *p;
        num=0;
        p=G.vertices[i].firstarc;
        while(p)
        {
            num++;
            p=p->nextarc;
        }
        fwrite(&num,sizeof(int),1,fp);//����仡������
        p=G.vertices[i].firstarc;
        while(p)
        {
            fwrite(&(p->adjvex),sizeof(int),1,fp);
            p=p->nextarc;
        }
    }
    fclose(fp);
    return OK;
}

status LoadGraph(ALGraph &G, char FileName[])
//����Ϊ ALGraph &G, char FileName[]
//�����ļ�FileName��ͼ���ݣ�����ͼ���ڽӱ�
{
    FILE *fp;
    int j;
    fp=fopen(FileName,"rb");
	G.arcnum=0;
    int num=0;
    fread(&(G.vexnum),sizeof(int),1,fp);
    for(int i=0;i<G.vexnum;i++)
    {
        fread(&(G.vertices[i].data),sizeof(VertexType),1,fp);
        G.vertices[i].firstarc=NULL;
        fread(&num,sizeof(int),1,fp);
        G.arcnum+=num;
        ArcNode *p,*pp;
        if(num==1)
        {
            G.vertices[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
            fread(&(G.vertices[i].firstarc->adjvex),sizeof(int),1,fp);
            G.vertices[i].firstarc->nextarc=NULL;
        }
        else if(num>1)
        {	
        	int a[num]; 
        	for(int j=0;j<num;j++)
        	{
        		fread(a+j,sizeof(int),1,fp);
			}
			G.vertices[i].firstarc=(ArcNode *)malloc(sizeof(ArcNode));
			G.vertices[i].firstarc->adjvex=a[num-1];
			G.vertices[i].firstarc->nextarc=NULL;
			for(int j=num-2;j>=0;j--)
			{
				p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=a[j];
				p->nextarc=G.vertices[i].firstarc;
				G.vertices[i].firstarc=p;
			}
        }
    }
    G.arcnum=G.arcnum/2;
    fclose(fp);
    return OK;
} 



int xunzhao(ALGraph &G,int i,int k)
//����Ϊ ALGraph &G,int i,int k
//���������ǲ��ϵĽ��еݹ������Ѱ����Ŀ�궥�����Ϊk���ڵĶ��� 
{
	if(k==1) return OK;
	ArcNode *p;
		p=G.vertices[i].firstarc;
		while(p)
		{
			if(biaozhi[p->adjvex]==0)
			{
				printf("%d %s\n",G.vertices[p->adjvex].data.key,G.vertices[p->adjvex].data.others);
				biaozhi[p->adjvex]=1;
				xunzhao(G,p->adjvex,k-1);
			}
			p=p->nextarc;
		}
	return OK;
}

status VerticesSetLessThank(ALGraph &G,int v,int k)
//����ΪGraph &G,int v,int k
//�����붥��v����С��k�Ķ���ļ��� 
{
	int i;
	if(G.vexnum==0) return ERROR;
	if(k<=1) return ERROR;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.vertices[i].data.key==v) break;
	}
	if(i==G.vexnum) return ERROR;
		ArcNode *p;
		biaozhi[i]=1;
		p=G.vertices[i].firstarc;
		while(p)
		{
			if(biaozhi[p->adjvex]==0)
			{
				printf("%d %s\n",G.vertices[p->adjvex].data.key,G.vertices[p->adjvex].data.others);
				biaozhi[p->adjvex]=1;
				xunzhao(G,p->adjvex,k-1);
			}
			p=p->nextarc;
		}
	return OK;
}

status ShortestPathLength(ALGraph &G,int v,int w)
//����Ϊ Graph &G,int v,int w
//��ʼ������ͼG����,��������Ƿ��ض���v�붥��w�����·���ĳ��� 
{
	int i,j;
	if(v==w) return ERROR;
	if(G.vexnum<2) return ERROR;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.vertices[i].data.key==v) break;
	}
	for(j=0;j<G.vexnum;j++)
  	{
		if(G.vertices[j].data.key==w) break;
	}
	if(i==G.vexnum||j==G.vexnum) return ERROR;
	for(int n=0;n<50;n++)
	{
		for(int m=0;m<50;m++)
		{
			zuiduan[n][m]=10000;
		}
	}
	for(int n=0;n<G.vexnum;n++)//�Ծ�����и�ֵ 
	{
		ArcNode *p;
		p=G.vertices[n].firstarc;
		while(p)
		{
			zuiduan[n][p->adjvex]=1;
			p=p->nextarc;
		}
	}
	for(int k=0;k<G.vexnum;k++)
	{
		if(zuiduan[i][j]>zuiduan[i][k]+zuiduan[k][j])
		zuiduan[i][j]=zuiduan[i][k]+zuiduan[k][j];
	}
	return zuiduan[i][j];
}

status ConnectedComponentsNums(ALGraph &G)
//����Ϊ Graph &G
//��ʼ����ΪͼG����,�������Ϊ����ͼG��������ͨ�����ĸ��� 
{
	if(G.vexnum==0) return ERROR;
	int ans=1;
	dfs1(0,G);
    while(num!=G.vexnum)
    {
        int j=0;
        while(biaozhi[j]!=0)
        {
            j++;
        }
        dfs1(j,G);
        ans++;
    }
    return ans;
}


