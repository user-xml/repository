#include "ljjz.h"
/*
函数功能:实现用Dijkstra算法求从某顶点v到其余各顶点的最短路径。
注：v的值为顶点在数组中的下标*/
void dijkstra(AdjMatrix G,int v){
	int i,j,m;
	int dist[M],path[M],s[M];
	for(i = 0;i<G.numV;i++){
		dist[i]=G.Edge[v][i];
		s[i] = 0;
		if(i!=v&&G.Edge[v][i]<Max){
			
			path[i] = v;
		}else{
			
			path[i]=-1;
		}
	}
	s[v]=1;
	dist[v] = 0;
	for(i = 0;i<G.numV;i++){
		int min = Max;
		int u = v;
		for(j = 0;j< 6;j++){
			if(!s[j]&&dist[j]<min){
				u=j;
				min = dist[j];
			}
			s[u] = 1;
			for(m = 0;m<G.numV;m++){
				if(!s[m]&&G.Edge[u][m]<Max&&dist[u]+G.Edge[u][m]<dist[m]){
					dist[m] = dist[u]+G.Edge[u][m];
					path[m] = u;
				}
				
			}
		}
	}
	for(i = 0;i< 6;i++){
		printf("\n起始源点 v%d 到 v%d 的最短路径为 %d \n",v+1,i+1,dist[i]);
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

int main(){
	AdjMatrix G;
	int v;
	printf("请您输入起始源点v(注：v的值为顶点在数组中的下标):");
	scanf("%d",&v);
	creatByFileData(&G,6,6);
	print(G);
	printf("您输入的起始源点为:%d,实际起始源点为：%d\n",v,v+1); 
	dijkstra(G,v);
	return 1; 
}