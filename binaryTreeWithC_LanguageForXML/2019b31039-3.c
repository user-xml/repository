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
	printf("��������Ҫ�����Ķ���������������(��#��ʾ��)\n\n");
	bnode *tree = creat();
	printf("\n�����������ɹ�\n");
	change(tree);
	printf("\n������������Ů�����ɹ�\n");
	printf("\n");
	return 1;
}