#include "bintree.h"
#include <stdlib.h>
/*
求结点的层次 */
int Depth(bnode *p, char x){
     int k=1,flag=1,point_not_in_tree=0;
     bnode *q;
     sqstack L1,L2;    
     init(&L1);
     init(&L2);
     push(&L1,p);
     while(1)
     {
        if(flag){
           while(!empty(&L1))
           {
	           point_not_in_tree = 0;
               q=pop(&L1);
               if(q->data==x)  return k;
               if(q->lch!=NULL)  push(&L2,q->lch);
               if(q->rch!=NULL)  push(&L2,q->rch);
           }
           k++;
           flag=0;
           point_not_in_tree++;
        }else {
           while(!empty(&L2))
           {	
   		       point_not_in_tree = 0;
               q=pop(&L2);
               if(q->data==x)  return k;
               if(q->lch!=NULL)  push(&L1,q->lch);
               if(q->rch!=NULL)  push(&L1,q->rch);
           }
           k++;
           flag=1;
           point_not_in_tree ++;
       }
       if(point_not_in_tree == 2){
       	return 0;
       }
     }
	return 0;
}
int main(){
	printf("请输入您要建立的二叉树的先序序列(用#表示空)\n\n");
	bnode *tree = creat();
	printf("\n二叉树构建成功\n");
	getchar();
	printf("\n求x结点的层次,请输入x结点的值:");
	datatype x;
	scanf("%c",&x);
	printf("\n您输入的结点为:%c\n",x);
	int  k =Depth(tree,x);
	k==0?printf("\n该二叉树中无该结点\n"):printf("\n结点%c的层次为:%2d\n",x,k);
	printf("\n");
	return 1;
}