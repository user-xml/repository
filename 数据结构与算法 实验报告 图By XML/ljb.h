/*********************************************/
/*              �ڽӱ�洢�ṹ          	 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>
#define M 100		    	/*ͼ����󶥵���*/
typedef char VertexType;    /*������Ϣ��������*/
typedef struct ArcNode{     /*�߱���*/
	int adjvex;
	int info;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct Vnode{       /*ͷ�������*/
	VertexType data;        /*������Ϣ*/
	ArcNode *firstarc;      /*�ڽ�����ͷָ��*/
}Vnode;

typedef struct{           /*�ڽӱ�����*/
	Vnode Vertex[M];      /*���ͷ����˳���*/
	int numV,numE;        /*ͼ�Ķ����������*/
}AdjList;

/* �������ܣ�����ͼ���ڽӱ� */ 
void creat(AdjList *G,int n,int e)
{
	FILE *fw= fopen("D:\\data.txt","r");
	int i,vi,vj,w;
	ArcNode *q1,*q2;
	G->numV =n;
	G->numE =e;
	printf("���붥�����Ϣ��\n");
	for( i=0; i<G->numV; i++ )
	{
	/*
	printf("%d:",i+1);   
    	scanf("%c",&G->Vertex[i].data );
		getchar();*/
		fscanf(fw,"%c",&G->Vertex[i].data);
		G->Vertex[i].firstarc=NULL;      
	}
 	for(i=0; i<G->numE; i++ )
	{
		
		//printf("����ߵ���Ϣ��Ȩֵ(vi,vj,w)��"); 
      	//scanf("%d,%d,%d",&vi,&vj,&w);          ����ͼ*/*/
      	fscanf(fw,"%d,%d,%d",&vi,&vj,&w); 
      	q1=(ArcNode*)malloc(sizeof(ArcNode));
 		q1->adjvex=vj-1; q1->info=w; q1->nextarc=NULL;
 		q1->nextarc= G->Vertex[vi-1].firstarc; 
 		G->Vertex[vi-1].firstarc=q1; 
 		q2=(ArcNode*)malloc(sizeof(ArcNode));
 		q2->adjvex=vi-1; q2->info=w; q2->nextarc=NULL;
 		q2->nextarc= G->Vertex[vj-1].firstarc; 
 		G->Vertex[vj-1].firstarc=q2; 
	}
}

/* �������ܣ����ͼ���ڽӱ� */
void print(AdjList G)
{
	ArcNode *p;
	int i;
	for(i=0;i<G.numV;i++)
    {
		printf("%c",G.Vertex[i].data);
        p=G.Vertex[i].firstarc;
        while(p)
        {
			printf("->%2d%3d",p->adjvex,p->info);
            p=p->nextarc;
        }
     	printf("\n");
	}
}
