#include "ljjz.h"
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
	creatByFileData(&G,6,6);
	print(G);
	return 1; 
}