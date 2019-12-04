#include "ljjz.h"
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

int main(){
	AdjMatrix G;
	creatByFileData(&G,6,6);
	print(G);
	return 1; 
}