/********************************************/
/*             �ڽӾ���洢�ṹ	   	 	    */
/********************************************/
#include <stdio.h>
#define Max 32767   			/*�˴���32767���������*/
#define M 100          			/*��󶥵���*/
typedef char VertexType;  		/*����ֵ����*/
typedef struct{
	VertexType vertices[M];  /*������Ϣ��*/
	int Edge[M][M]; 	     /*�ڽӾ���*/
	int numV,numE;  	/*ͼ�ж������������*/
} AdjMatrix;   			/*�ڽӾ����ʾ��ͼ����*/

/* �������ܣ�����ͼ���ڽӾ��� */ 
void creat(AdjMatrix *G, int n, int e)
{
	int i, j, vi, vj, w;      /*wΪ�ߵ�Ȩֵ*/
	G->numV=n;
	G->numE=e;   	  
	printf("���붥�����Ϣ��\n");
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
  		printf("����ߵ���Ϣ��Ȩֵ(vi,vj,w)��");  
  		scanf("%d,%d,%d",&vi,&vj,&w);
  		G->Edge[vi-1][vj-1]=w; 
  		G->Edge[vj-1][vi-1]=w;      /*��������ͼ*/        
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

/* �������ܣ����ͼ���ڽӾ��� */ 
void  print(AdjMatrix G)
{
	int i,j;
	printf ("\n����������Ϣ��\n");
    for( i=0; i<G.numV; i++ )
		printf("%c ",G.vertices[i] );
    printf("\n���ͼ���ڽӾ���\n" );
    for( i=0; i<G.numV; i++ )
	{
		for( j=0; j<G.numV ;j++ ) 
			printf("%6d",G.Edge[i][j] );
       	printf("\n");
	}
}
