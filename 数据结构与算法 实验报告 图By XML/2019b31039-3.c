#include "ljjz.h"
/*
��������:ʵ����Dijkstra�㷨���ĳ����v���������������·����
ע��v��ֵΪ�����������е��±�*/
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
		printf("\n��ʼԴ�� v%d �� v%d �����·��Ϊ %d \n",v+1,i+1,dist[i]);
	}
}
/* �������ܣ����ı��ж�ȡ���ݽ���ͼ���ڽӾ��� */ 
void creatByFileData(AdjMatrix *G, int n, int e)
{
	FILE *fw= fopen("D:\\data.txt","r");
	int i, j, vi, vj, w;      /*wΪ�ߵ�Ȩֵ*/
	G->numV=n;
	G->numE=e;   	  
	for( i=0; i<G->numV; i++ )
	{  
		fscanf(fw,"%c",&G->vertices[i]);
	}
		printf("\n�ļ���ȡ������Ϣ�ɹ�\n");
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
  		G->Edge[vj-1][vi-1]=w;      /*��������ͼ*/        
	}
		printf("\n�ļ���ȡ�ߵ���Ϣ��Ȩֵ�ɹ�\n");
}

int main(){
	AdjMatrix G;
	int v;
	printf("����������ʼԴ��v(ע��v��ֵΪ�����������е��±�):");
	scanf("%d",&v);
	creatByFileData(&G,6,6);
	print(G);
	printf("���������ʼԴ��Ϊ:%d,ʵ����ʼԴ��Ϊ��%d\n",v,v+1); 
	dijkstra(G,v);
	return 1; 
}