#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef char datatype;
typedef struct node 	/*二叉树结构定义*/
{
    datatype data;
    struct node *lch,*rch;
}bnode;
 /*根据扩充二叉树的先序序列建立二叉树p*/
 bnode*  creat(){
	 bnode *tree;
	 datatype c;
	 scanf("%c",&c);
	 if(c =='#'){
 		tree = NULL;
 	}else{
	 	tree = (bnode*)malloc(sizeof(bnode));
	 	tree->data = c;
	 	tree->lch = creat();
	 	tree->rch = creat();
	 }
	 return tree;
}

void fstorder(bnode *p)  	/*先序递归遍历二叉树*/
{
    if(p)
    {
        printf("%c",p->data);
        fstorder(p->lch);
        fstorder(p->rch);
    }
}
void midorder(bnode *p)  	/*中序递归遍历二叉树*/
{
    if(p)
    {
    	fstorder(p->lch);
        printf("%c",p->data);
        fstorder(p->rch);
    }
}
void lastorder(bnode *p) 	/*后序递归遍历二叉树*/
{
    if(p)
    {
        lastorder(p->lch);
        lastorder(p->rch);
        printf("%c",p->data);
    }
}

/*顺序栈定义*/
typedef struct
{
    bnode *data[N];
    int top;
}sqstack;

void init(sqstack *s)   /*初始化空栈*/
{
    s->top=-1;
}
int empty(sqstack *s)   /*判断栈是否为空*/
{
    if(s->top>-1) return 0;
    else return 1;
}
int full(sqstack *s)   /*判断栈是否为满*/
{
    if(s->top==N-1) return 1;
    else return 0;
}
void push(sqstack *s ,bnode *x)   /*进栈*/
{
    if(!full(s))
        s->data[++s->top]=x;
}
bnode *pop(sqstack *s)			/*出栈*/
{
    if(!empty(s))
        return s->data[s->top--];
}

