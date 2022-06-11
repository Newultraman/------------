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
	printf("    1. CreatGraph(创建图)7. InsertVex(插入顶点)\n");
	printf("  2. DestroyGraph(销毁图) 8. DeleteVex(删除顶点)\n");
	printf("    3. LocateVex(查找顶点)  9. InsertArc(插入弧) \n");
	printf("    4. PutVex(顶点赋值)  10. DeleteArc(删除弧)\n");
	printf("    5. FirstAdjVex(获得第一邻接点) 11. DFSTraverse(深度优先搜索遍历)\n");
	printf("    6. NextAdjVex(获得下一邻接点)  12. BFSTraverse(广度优先搜索遍历)\n");
	printf("附加功能:----------------------------------------\n");
	printf("多图操作: 13. AddGraph(增添图)	14. RemoveGraph(消除图)\
	 15. LocateGraph(定位图) 16. WatchGraph(总览)\n");
	printf("文件功能:  17. SaveGraph(写入文件) 18. LoadGraph(读取文件)\n"); 
	printf("  19. VerticesSetLessThank(距离小于k的顶点集合) 20. ShortestPathLength(顶点间最短路径长度)\
		21. ConnectedComponentsNums(图的连通分量)\n");
	printf("");
	printf("    	      0. Exit\n");
	printf("--------------------------------------------\n");
	printf("    请选择你的操作[0~20]:");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			printf("请输入这个要建立的图! \n");
			i=0;
			do {
    	scanf("%d%s",&V[i].key,V[i].others);
		} while(V[i++].key!=-1);
		i=0;
	do {
    	scanf("%d%d",&VR[i][0],&VR[i][1]);
   	} while(VR[i++][0]!=-1);
   	if (CreateGraph(G,V,VR)==ERROR) printf("输入数据错，无法创建");
   	else
   	{
   		if (G.arcnum!=i-1) {
     	    printf("边的数目错误！\n");}
     	printf("创建图成功! \n");
	}
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 2:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		if(DestroyGraph(Graphs.elem[nu-1].G)==OK) 
		printf("图销毁成功! \n");
	 	else
		printf("图销毁失败! \n");
	}
	else printf("序号错误! \n");
	i=0;
	getchar();getchar();
	break;
	case 3:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		printf("请输入查找的顶点的关键字! \n");
		scanf("%d",&u); 
		i=LocateVex(Graphs.elem[nu-1].G,u);
		if(i==-1) printf("查找失败! \n"); 
		else
		{
			printf("%d %s",Graphs.elem[nu-1].G.vertices[i].data.key,Graphs.elem[nu-1].G.vertices[i].data.others);
		} 
	}
	else printf("序号错误! \n");
	i=0;
	getchar();getchar();
	break;
	case 4:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		printf("请输入查找的顶点的关键字和要赋的值! \n");
		scanf("%d%d%s",&u,&value.key,value.others);
		i=PutVex(Graphs.elem[nu-1].G,u,value);
		if (i==OK)
     		printf("赋值操作成功,赋的值为 %d %s \n",value.key,value.others);
		else
			printf("赋值操作失败"); 
	}
	else printf("序号错误! \n");
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 5:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入要查找的图的顶点关键字! \n");
		scanf("%d",&u);
		i=FirstAdjVex(Graphs.elem[nu-1].G,u);
		if (i!=-1)
			printf("%d %s",Graphs.elem[nu-1].G.vertices[i].data.key,Graphs.elem[nu-1].G.vertices[i].data.others);
		else
			printf("查找失败"); 
	}
	else printf("序号错误! \n");
	i=0;
	getchar();getchar();
	break;
	case 6:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入两个顶点的关键字! \n");
		scanf("%d%d",&v,&w);
		i=NextAdjVex(Graphs.elem[nu-1].G,v,w);
		if (i!=-1)
			printf("%d %s",Graphs.elem[nu-1].G.vertices[i].data.key,Graphs.elem[nu-1].G.vertices[i].data.others);
		else
			printf("无下一邻接顶点! \n");
	}
	else printf("序号错误! \n");
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 7:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入要插入的顶点! \n");
		scanf("%d%s",&value.key,value.others);
		i=InsertVex(Graphs.elem[nu-1].G,value);
		if (i==OK)
			printf("插入操作成功! \n");
		else printf("插入操作失败! \n"); 
	}
	else printf("序号错误! \n");
	i=0;
	memset(guanjianzi,-1,sizeof(int)*100);
	getchar();getchar();
	break;
	case 8:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入顶点的关键字! \n");
		scanf("%d",&v);
		i=DeleteVex(Graphs.elem[nu-1].G,v);
		if(i==OK)
		{
			printf("删除顶点成功! \n");
		}
		else printf("删除顶点失败! \n"); 
	}
	else printf("序号错误! \n");
	i=0;
	getchar();getchar();
	break;
	case 9:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{ 
		printf("请输入两个顶点的关键字! \n");
		scanf("%d%d",&v,&w);
		i=InsertArc(Graphs.elem[nu-1].G,v,w);
		if(i==OK) printf("插入弧成功! \n");
		else if(i==ERROR) printf("插入弧失败! \n"); 
	}
	else printf("序号错误! \n");
	i=0;
	getchar();getchar();
	break;
	case 10:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入两个顶点的关键字! \n");
		scanf("%d%d",&v,&w);
		i=DeleteArc(Graphs.elem[nu-1].G,v,w);
		if(i==OK) printf("删除弧成功! \n");
		else printf("删除弧失败! \n");
	}
	else printf("序号错误! \n");
	i=0;
	getchar();getchar();
	break;
	case 11:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("深搜的结果为: \n");
		i=DFSTraverse(Graphs.elem[nu-1].G,visit);
		if(i==ERROR) printf("图不存在! \n"); 
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 12:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("广搜的结果为: \n");
		i=BFSTraverse(Graphs.elem[nu-1].G,visit);
		if(i==ERROR) printf("图不存在! \n");
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 13:
	printf("请输入图名字! \n");
			scanf("%s",name);
		printf("请输入这个要建立的图! \n");
		 i=0;
			do {
    	scanf("%d%s",&V[i].key,V[i].others);
		} while(V[i++].key!=-1);
		i=0;
	do {
    	scanf("%d%d",&VR[i][0],&VR[i][1]);
   	} while(VR[i++][0]!=-1);
   	i=AddGraph(Graphs,name,V,VR);
   	if(i==OK) printf("增添成功! \n");
   	else printf("增添失败! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 14:
	printf("请输入图名字! \n");
			scanf("%s",name);
	i=RemoveGraph(Graphs,name);
	if(i==OK) printf("删除成功! \n");
	else printf("删除失败! \n");
	i=0;num=0;
	getchar();getchar();
	break;
	case 15:
	printf("请输入图名字! \n");
			scanf("%s",name);
	i=LocateGraph(Graphs,name);
	if(i==0) printf("不存在该图! \n");
	else printf("图的逻辑序号为 %d! \n",i); 
	i=0;num=0;
	getchar();getchar();
	break;
	case 16:
	if(Graphs.length==0) printf("不存在图! \n");
	else
	{
		WatchGraph(Graphs);	
	}
	i=0;num=0;
	//memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 17:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入文件名字! \n");
		scanf("%s",Filename); 
		i=SaveGraph(Graphs.elem[nu-1].G,Filename);
		if(i==OK) printf("写入文件成功! \n");
		else printf("写入文件失败! \n"); 
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 18:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入文件名字! \n");
		scanf("%s",Filename); 
		i=LoadGraph(Graphs.elem[nu-1].G,Filename);
		if(i==OK) printf("读取文件成功! \n");
		else printf("读取文件失败! \n"); 
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 19:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入对应顶点的关键字和最长路径长度! \n");
		scanf("%d%d",&v,&k); 
		i=VerticesSetLessThank(Graphs.elem[nu-1].G,v,k);
		if(i==ERROR) printf("操作失败! \n");
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 20:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		printf("请输入两个对应的顶点的关键字! \n");
		scanf("%d%d",&v,&w);
		i=ShortestPathLength(Graphs.elem[nu-1].G,v,w);
		if(i==ERROR) printf("操作失败,输入数据有误! \n");
		else printf("最短路径为 %d! \n",i);   
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break;
	case 21:
	printf("请输入操作的图的序号!\n");
	scanf("%d",&nu);
	if(nu<=Graphs.length&&nu>0)
	{
		i=ConnectedComponentsNums(Graphs.elem[nu-1].G);
		if(i==ERROR) printf("操作失败,输入数据有误! \n");
		else printf("图的连通分量为 %d! \n",i); 
	}
	else printf("序号错误! \n");
	i=0;num=0;
	memset(biaozhi,0,sizeof(int)*100); 
	getchar();getchar();
	break; 
	}
}
}
