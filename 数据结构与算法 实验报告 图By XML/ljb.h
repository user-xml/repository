/*********************************************/
/*              邻接表存储结构          	 */
/*********************************************/

#include <stdio.h>
#include <stdlib.h>
#define M 100		    	/*图的最大顶点数*/
typedef char VertexType;    /*顶点信息数据类型*/
typedef struct ArcNode{     /*边表结点*/
	int adjvex;
	int info;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct Vnode{       /*头结点类型*/
	VertexType data;        /*顶点信息*/
	ArcNode *firstarc;      /*邻接链表头指针*/
}Vnode;

typedef struct{           /*邻接表类型*/
	Vnode Vertex[M];      /*存放头结点的顺序表*/
	int numV,numE;        /*图的顶点数与边数*/
}AdjList;

/* 函数功能：建立图的邻接表 */ 
void creat(AdjList *G,int n,int e)
{
	FILE *fw= fopen("D:\\data.txt","r");
	int i,vi,vj,w;
	ArcNode *q1,*q2;
	G->numV =n;
	G->numE =e;
	printf("输入顶点的信息：\n");
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
		
		//printf("输入边的信息及权值(vi,vj,w)："); 
      	//scanf("%d,%d,%d",&vi,&vj,&w);          无向图*/*/
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

/* 函数功能：输出图的邻接表 */
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
