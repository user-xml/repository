#include "bintree.h"
int main(){
 	printf("��������Ҫ�����Ķ���������������(��#��ʾ��)\n");
	bnode *tree = creat();
	printf("�����������ɹ�");
	printf("\n�������:"); 
 	fstorder(tree);
 	printf("\n�������:");
 	lastorder(tree); 
 	printf("\n");      
	return 1;
}