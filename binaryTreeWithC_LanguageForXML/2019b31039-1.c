#include "bintree.h"
/*
�ǵݹ�ʵ��������� */
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
	printf("��������Ҫ�����Ķ���������������(��#��ʾ��)\n\n");
	bnode *tree = creat();
	printf("\n�����������ɹ�\n");
	printf("\n�������ǵݹ�����������Ϊ:"); 
	fstorder1(tree);
	printf("\n\n");
	return 1;
}