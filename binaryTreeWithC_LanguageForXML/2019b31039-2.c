#include "bintree.h"
#include <stdlib.h>
/*
����Ĳ�� */
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
	printf("��������Ҫ�����Ķ���������������(��#��ʾ��)\n\n");
	bnode *tree = creat();
	printf("\n�����������ɹ�\n");
	getchar();
	printf("\n��x���Ĳ��,������x����ֵ:");
	datatype x;
	scanf("%c",&x);
	printf("\n������Ľ��Ϊ:%c\n",x);
	int  k =Depth(tree,x);
	k==0?printf("\n�ö��������޸ý��\n"):printf("\n���%c�Ĳ��Ϊ:%2d\n",x,k);
	printf("\n");
	return 1;
}