#include "Graph.h"

int main(void)
{
	ALGraph G;
	G.vexnum=0;
	G.arcnum=0;
	char name[30];
	int nu=0,u,v,w,k; 
	char Filename[30];
	int op=1,i=0; 
	GRAPHS Graphs;
	Graphs.length=0;
	VertexType V[21],value; 
	KeyType VR[100][2];
	memset(guanjianzi,-1,sizeof(int)*100);
	while(op)
	{
		system("cls");	printf("\n\n");
	printf("Menu for Linear Table On Sequence Structure \n");
	printf("--------------------------------------------\n");
	printf("    1. CreatGraph(����ͼ)7. InsertVex(���붥��)\n");
	printf("  2. DestroyGraph(����ͼ) 8. DeleteVex(ɾ������)\n");
	printf("    3. LocateVex(���Ҷ���)  9. InsertArc(���뻡) \n");
	printf("    4. PutVex(���㸳ֵ)  10. DeleteArc(ɾ����)\n");
	printf("    5. FirstAdjVex(��õ�һ�ڽӵ�) 11. DFSTraverse(���������������)\n");
	printf("    6. NextAdjVex(�����һ�ڽӵ�)  12. BFSTraverse(���������������)\n");
	printf("���ӹ���:----------------------------------------\n");
	printf("��ͼ����: 13. AddGraph(����ͼ)	14. RemoveGraph(����ͼ)\
	 15. LocateGraph(��λͼ) 16. WatchGraph(����)\n");
	printf("�ļ�����:  17. SaveGraph(д���ļ�) 18. LoadGraph(��ȡ�ļ�)\n"); 
	printf("  19. VerticesSetLessThank(����С��k�Ķ��㼯��) 20. ShortestPathLength(��������·������)\
		21. ConnectedComponentsNums(ͼ����ͨ����)\n");
	printf("");
	printf("    	      0. Exit\n");
	printf("--------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~20]:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("���������Ҫ������ͼ! \n");
			i=0;
			do {
    	scanf("%d%s",&V[i].key,V[i].others);
		} while(V[i++].key!=-1);
		i=0;
	do {
    	scanf("%d%d",&VR[i][0],&VR[i][1]);
   	} while(VR[i++][0]!=-1);
   	if (CreateGraph(G,V,VR)==ERROR) printf("�������ݴ��޷�����");
   	else
   	{
   		if (G.arcnum!=i-1) {
     	    printf("�ߵ���Ŀ����\n");}
     	printf("����ͼ�ɹ�! \n");
	}
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 2:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		if(DestroyGraph(Graphs.elem[nu-1].G)==OK) 
		printf("ͼ���ٳɹ�! \n");
	 	else
		printf("ͼ����ʧ��! \n");
	}
	else printf("��Ŵ���! \n");
	i=0;
	getchar();getchar();
	break;
	case 3:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		printf("��������ҵĶ���Ĺؼ���! \n");
		scanf("%d",&u); 
		i=LocateVex(Graphs.elem[nu-1].G,u);
		if(i==-1) printf("����ʧ��! \n"); 
		else
		{
			printf("%d %s",Graphs.elem[nu-1].G.vertices[i].data.key,Graphs.elem[nu-1].G.vertices[i].data.others);
		} 
	}
	else printf("��Ŵ���! \n");
	i=0;
	getchar();getchar();
	break;
	case 4:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		printf("��������ҵĶ���Ĺؼ��ֺ�Ҫ����ֵ! \n");
		scanf("%d%d%s",&u,&value.key,value.others);
		i=PutVex(Graphs.elem[nu-1].G,u,value);
		if (i==OK)
     		printf("��ֵ�����ɹ�,����ֵΪ %d %s \n",value.key,value.others);
		else
			printf("��ֵ����ʧ��"); 
	}
	else printf("��Ŵ���! \n");
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 5:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("������Ҫ���ҵ�ͼ�Ķ���ؼ���! \n");
		scanf("%d",&u);
		i=FirstAdjVex(Graphs.elem[nu-1].G,u);
		if (i!=-1)
			printf("%d %s",Graphs.elem[nu-1].G.vertices[i].data.key,Graphs.elem[nu-1].G.vertices[i].data.others);
		else
			printf("����ʧ��"); 
	}
	else printf("��Ŵ���! \n");
	i=0;
	getchar();getchar();
	break;
	case 6:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("��������������Ĺؼ���! \n");
		scanf("%d%d",&v,&w);
		i=NextAdjVex(Graphs.elem[nu-1].G,v,w);
		if (i!=-1)
			printf("%d %s",Graphs.elem[nu-1].G.vertices[i].data.key,Graphs.elem[nu-1].G.vertices[i].data.others);
		else
			printf("����һ�ڽӶ���! \n");
	}
	else printf("��Ŵ���! \n");
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 7:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("������Ҫ����Ķ���! \n");
		scanf("%d%s",&value.key,value.others);
		i=InsertVex(Graphs.elem[nu-1].G,value);
		if (i==OK)
			printf("��������ɹ�! \n");
		else printf("�������ʧ��! \n"); 
	}
	else printf("��Ŵ���! \n");
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 8:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("�����붥��Ĺؼ���! \n");
		scanf("%d",&v);
		i=DeleteVex(Graphs.elem[nu-1].G,v);
		if(i==OK)
		{
			printf("ɾ������ɹ�! \n");
		}
		else printf("ɾ������ʧ��! \n"); 
	}
	else printf("��Ŵ���! \n");
	i=0;
	getchar();getchar();
	break;
	case 9:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		printf("��������������Ĺؼ���! \n");
		scanf("%d%d",&v,&w);
		i=InsertArc(Graphs.elem[nu-1].G,v,w);
		if(i==OK) printf("���뻡�ɹ�! \n");
		else if(i==ERROR) printf("���뻡ʧ��! \n"); 
	}
	else printf("��Ŵ���! \n");
	i=0;
	getchar();getchar();
	break;
	case 10:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("��������������Ĺؼ���! \n");
		scanf("%d%d",&v,&w);
		i=DeleteArc(Graphs.elem[nu-1].G,v,w);
		if(i==OK) printf("ɾ�����ɹ�! \n");
		else printf("ɾ����ʧ��! \n");
	}
	else printf("��Ŵ���! \n");
	i=0;
	getchar();getchar();
	break;
	case 11:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("���ѵĽ��Ϊ: \n");
		i=DFSTraverse(Graphs.elem[nu-1].G,visit);
		if(i==ERROR) printf("ͼ������! \n"); 
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 12:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("���ѵĽ��Ϊ: \n");
		i=BFSTraverse(Graphs.elem[nu-1].G,visit);
		if(i==ERROR) printf("ͼ������! \n");
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 13:
	printf("������ͼ����! \n");
			scanf("%s",name);
		printf("���������Ҫ������ͼ! \n");
		 i=0;
			do {
    	scanf("%d%s",&V[i].key,V[i].others);
		} while(V[i++].key!=-1);
		i=0;
	do {
    	scanf("%d%d",&VR[i][0],&VR[i][1]);
   	} while(VR[i++][0]!=-1);
   	i=AddGraph(Graphs,name,V,VR);
   	if(i==OK) printf("����ɹ�! \n");
   	else printf("����ʧ��! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 14:
	printf("������ͼ����! \n");
			scanf("%s",name);
	i=RemoveGraph(Graphs,name);
	if(i==OK) printf("ɾ���ɹ�! \n");
	else printf("ɾ��ʧ��! \n");
	i=0;num=0;
	getchar();getchar();
	break;
	case 15:
	printf("������ͼ����! \n");
			scanf("%s",name);
	i=LocateGraph(Graphs,name);
	if(i==0) printf("�����ڸ�ͼ! \n");
	else printf("ͼ���߼����Ϊ %d! \n",i); 
	i=0;num=0;
	getchar();getchar();
	break;
	case 16:
	if(Graphs.length==0) printf("������ͼ! \n");
	else
	{
		WatchGraph(Graphs);	
	}
	i=0;num=0;
	//memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 17:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("�������ļ�����! \n");
		scanf("%s",Filename); 
		i=SaveGraph(Graphs.elem[nu-1].G,Filename);
		if(i==OK) printf("д���ļ��ɹ�! \n");
		else printf("д���ļ�ʧ��! \n"); 
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 18:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("�������ļ�����! \n");
		scanf("%s",Filename); 
		i=LoadGraph(Graphs.elem[nu-1].G,Filename);
		if(i==OK) printf("��ȡ�ļ��ɹ�! \n");
		else printf("��ȡ�ļ�ʧ��! \n"); 
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 19:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("�������Ӧ����Ĺؼ��ֺ��·������! \n");
		scanf("%d%d",&v,&k); 
		i=VerticesSetLessThank(Graphs.elem[nu-1].G,v,k);
		if(i==ERROR) printf("����ʧ��! \n");
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 20:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("������������Ӧ�Ķ���Ĺؼ���! \n");
		scanf("%d%d",&v,&w);
		i=ShortestPathLength(Graphs.elem[nu-1].G,v,w);
		if(i==ERROR) printf("����ʧ��,������������! \n");
		else printf("���·��Ϊ %d! \n",i);   
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 21:
	printf("�����������ͼ�����!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		i=ConnectedComponentsNums(Graphs.elem[nu-1].G);
		if(i==ERROR) printf("����ʧ��,������������! \n");
		else printf("ͼ����ͨ����Ϊ %d! \n",i); 
	}
	else printf("��Ŵ���! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break; 
	}
}
}
