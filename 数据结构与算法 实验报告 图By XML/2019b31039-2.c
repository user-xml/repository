#include "ljb.h"
//函数功能：输出以邻接表为存储结构的无向图的各顶点的度
void degree(AdjList G){
	ArcNode *p;
	int i,n;
	for(i = 0;i<G.numV;i++){
		n = 0;
		p = G.Vertex[i].firstarc;
		while(p){
			n++;
			p = p->nextarc;
		}
		printf("\n顶点%d的度位\t%d\n",i+1,n);
	}
	printf("\n");
}
/* 函数功能：从文本中读取数据建立图的邻接表 */ 
void creatByFileData(AdjList *G,int n,int e)
{
	FILE *fw= fopen("D:\\data.txt","r");
	int i,vi,vj,w;
	ArcNode *q1,*q2;
	G->numV =n;
	G->numE =e;

	for( i=0; i<G->numV; i++ )
	{

		fscanf(fw,"%c",&G->Vertex[i].data);
		G->Vertex[i].firstarc=NULL;      
	}
	printf("\n文件读取顶点信息成功\n");
 	for(i=0; i<G->numE; i++ )
	{
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
		printf("\n文件读取边的信息及权值成功\n");
}

int main(){
	AdjList G;
	creatByFileData(&G,6,6);
	print(G);
	degree(G);
	return 1;
} 