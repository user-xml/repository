/********************************************/
/*             邻接矩阵存储结构	   	 	    */
/********************************************/
#include <stdio.h>
#define Max 32767   			/*此处用32767代表无穷大*/
#define M 100          			/*最大顶点数*/
typedef char VertexType;  		/*顶点值类型*/
typedef struct{
	VertexType vertices[M];  /*顶点信息域*/
	int Edge[M][M]; 	     /*邻接矩阵*/
	int numV,numE;  	/*图中顶点总数与边数*/
} AdjMatrix;   			/*邻接矩阵表示的图类型*/

/* 函数功能：建立图的邻接矩阵 */ 
void creat(AdjMatrix *G, int n, int e)
{
	int i, j, vi, vj, w;      /*w为边的权值*/
	G->numV=n;
	G->numE=e;   	  
	printf("输入顶点的信息：\n");
	for( i=0; i<G->numV; i++ )
	{
    	printf("%d:",i+1);   
    	scanf("%c",&G->vertices[i] );
		getchar();      
	}
	for( i=0; i<G->numV; i++ )
	for( j=0; j<G->numV; j++ )
	{
		G->Edge[i][j]=Max;
		if(i==j)G->Edge[i][j]=0;
	}
	for( i=0; i<G->numE; i++ )
	{
  		printf("输入边的信息及权值(vi,vj,w)：");  
  		scanf("%d,%d,%d",&vi,&vj,&w);
  		G->Edge[vi-1][vj-1]=w; 
  		G->Edge[vj-1][vi-1]=w;      /*对于无向图*/        
	}
}
/* 函数功能：从文本中读取数据建立图的邻接矩阵 */ 
void creatByFileData(AdjMatrix *G, int n, int e)
{
	FILE *fw= fopen("D:\\data.txt","r");
	int i, j, vi, vj, w;      /*w为边的权值*/
	G->numV=n;
	G->numE=e;   	  
	for( i=0; i<G->numV; i++ )
	{  
		fscanf(fw,"%c",&G->vertices[i]);
	}
		printf("\n文件读取顶点信息成功\n");
	for( i=0; i<G->numV; i++ )
	for( j=0; j<G->numV; j++ )
	{
		G->Edge[i][j]=Max;
		if(i==j)G->Edge[i][j]=0;
	}
	for( i=0; i<G->numE; i++ )
	{
  	
	  	fscanf(fw,"%d,%d,%d",&vi,&vj,&w);  
  		G->Edge[vi-1][vj-1]=w; 
  		G->Edge[vj-1][vi-1]=w;      /*对于无向图*/        
	}
		printf("\n文件读取边的信息及权值成功\n");
}

/* 函数功能：输出图的邻接矩阵 */ 
void  print(AdjMatrix G)
{
	int i,j;
	printf ("\n输出顶点的信息：\n");
    for( i=0; i<G.numV; i++ )
		printf("%c ",G.vertices[i] );
    printf("\n输出图的邻接矩阵：\n" );
    for( i=0; i<G.numV; i++ )
	{
		for( j=0; j<G.numV ;j++ ) 
			printf("%6d",G.Edge[i][j] );
       	printf("\n");
	}
}
