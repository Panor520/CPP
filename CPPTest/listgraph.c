#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 10//自定义最大顶点数
typedef char VertexType;//顶点类型由用户定义
typedef int EdgeType;//权值类型


//边和权值结点结构体
typedef struct EdgeNode
{
	int adjvex;//邻接点域
	EdgeType weight;//存权值，非网图可以不要这个
	struct EdgeNode * next;
}edgenode;

//顶点结点结构体
typedef struct VertexNode
{
	VertexType data;
	edgenode * next;//边表头指针
}VertexNode,AdjList[MAXVEX];

//邻接表结构体
typedef struct 
{
	AdjList adjList;
	int numVertexes,numEdges;//定点数和边数
}GraphAdjList;

//建立图的邻接表结构
void CreateALGraph(GraphAdjList * g)
{

	g->numVertexes=3;//3个顶点
	g->numEdges=3;//3条边
	
	//初始化顶点结构体
	char x='A';
	for(int i=0;i<g->numVertexes;i++)
	{
		g->adjList[i].data=x+i;//初始化结点值
		g->adjList[i].next=NULL;//初始化指针域
	}
	
	int i,j;
	edgenode * e;
	//生成边表 利用头插法
	for(int k=0;k<g->numEdges;k++)
	{
		printf("输入边（Vi,Vj）上的顶点序号:\n");
		scanf("%d %d",&i,&j);

		e=(edgenode *)malloc(sizeof(edgenode));
		e->adjvex=j;//B的下标
		e->next=g->adjList[i].next;//头插法
		g->adjList[i].next=e;
		
		e =(edgenode*)malloc(sizeof(edgenode));
		e->adjvex=i;
		e->next=g->adjList[j].next;//头插法
		g->adjList[j].next=e;
	}
}

void Show(GraphAdjList * g)
{
	printf("顶点信息:\n");

	for(int i=0;i<g->numVertexes;i++)
	{
		printf("i=%d %c ",i,g->adjList[i].data);
	}
	printf("\n");

	printf("边信息：\n");
	for(int i=0;i<g->numEdges;i++)
	{
		edgenode * temp=g->adjList[i].next;
	
		while(1)
		{	
			if(temp==NULL)
				break;
			printf("i=%d adjvex=%d weight=%d \n",i,temp->adjvex,temp->weight);
			
			temp=temp->next;
		}
	}
}



int main()
{
	GraphAdjList * g=(GraphAdjList *)malloc(sizeof(GraphAdjList));
	CreateALGraph(g);

	Show(g);


	free(g);
	g=0;
	return 0;
}
