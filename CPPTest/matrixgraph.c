#include <stdio.h>
#include <stdlib.h>

typedef char VertexType;//顶点类型由自定义
typedef int EdgeType;//边上的权值类型自定义
#define MAXVEX 100 //最大定点数自定义
#define INFINITY 65535 //65535代表∞ //用这个代表不存在的权值

typedef struct
{
	VertexType vexs[MAXVEX];//顶点表
	EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵 可看做表
	int numVertexes,numEdges;//图中顶点数和边数
}MGraph;

//建立无向图的邻接矩阵表示
void CreateMGraph(MGraph * G)
{
	int i,j,k,w;
	printf("输入顶点数和边数:\n");
	//scanf("%d %d",&(G->numVertexes),&(G->numEdges));//输入顶点数和边数
	G->numVertexes=5;
	G->numEdges=5;
	int a='A';
	for(i=0;i<G->numVertexes;i++)//时间复杂度(O(n))
	{	
		//scanf(&G->vexs[i]);
		G->vexs[i]=a+i;
	}
	
	for(i=0;i<G->numVertexes;i++)
		for(j=0;j<G->numVertexes;j++)
			G->arc[i][j]=INFINITY;//邻接矩阵初始化 时间复杂度为O（n²）
	
	/*这个初始化不好用
	for(k=0;k<G->numEdges;k++)//时间复杂度O(n)
	{
		printf("输入边（vi,vj）上的下标i,下标j和权w:\n");
		scanf("%d,%d,%d",&i,&j,&w);
		G->arc[i][j]=w;
		G->arc[j][i]=G->arc[i][j];//因为是无向图，矩阵对称
	}*/
	G->arc[1][0]=2;
	G->arc[2][0]=2;
	G->arc[0][1]=2;
	G->arc[4][1]=2;
	G->arc[0][2]=2;
	G->arc[3][2]=2;
	G->arc[2][3]=2;
	G->arc[4][3]=2;
	G->arc[1][4]=2;
	G->arc[3][4]=2;
}

void Show(MGraph * g)
{
	int i,j;
	for(i=0;i< g->numVertexes;i++)
	{
		for(j=0;j<g->numVertexes;j++)
		{	
			printf("G[%d][%d]=%d ",i,j,g->arc[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	MGraph * g=(MGraph *)malloc(sizeof(MGraph));
	CreateMGraph(g);
	Show(g);

	free(g);
	g=0;
	return 0;
}


