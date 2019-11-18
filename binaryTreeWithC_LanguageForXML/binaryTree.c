#include "bintree.h"
int main(){
 	printf("请输入您要建立的二叉树的先序序列(用#表示空)\n");
	bnode *tree = creat();
	printf("二叉树构建成功");
	printf("\n先序遍历:"); 
 	fstorder(tree);
 	printf("\n后序遍历:");
 	lastorder(tree); 
 	printf("\n");      
	return 1;
}