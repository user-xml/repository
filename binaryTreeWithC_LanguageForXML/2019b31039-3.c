#include "bintree.h"
void change(bnode *p){
	if(p){
		bnode *t;
		t = p->lch;
		p->lch = p->rch;
		p->rch =t;
		change(p->lch);
		change(p->rch);
	}
}
int main(){
	printf("请输入您要建立的二叉树的先序序列(用#表示空)\n\n");
	bnode *tree = creat();
	printf("\n二叉树构建成功\n");
	change(tree);
	printf("\n二叉树左右子女互换成功\n");
	printf("\n");
	return 1;
}