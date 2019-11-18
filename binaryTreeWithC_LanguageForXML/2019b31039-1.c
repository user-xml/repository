#include "bintree.h"
/*
非递归实现先序遍历 */
void fstorder1(bnode *p){
	sqstack s;
	init(&s);
	push(&s,p);
	while(!empty(&s))
	{
		p=pop(&s);
		printf("%3c",p->data);
		if(p->rch){
			push(&s,p->rch);
		}
		if(p->lch){
			push(&s,p->lch);
		}
	}
}
int main(){
	printf("请输入您要建立的二叉树的先序序列(用#表示空)\n\n");
	bnode *tree = creat();
	printf("\n二叉树构建成功\n");
	printf("\n二叉树非递归先序遍历结果为:"); 
	fstorder1(tree);
	printf("\n\n");
	return 1;
}