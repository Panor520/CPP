#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 10 //假设链表最大长度为50
typedef char ElemType;//ElemType类型根据实际情况定，这里假设为int
#define  ElemNULL 0;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct Node 
{
    struct Node * rchildPtr;//右子树结点
	ElemType data;
	struct Node * lchildPtr;//左子树结点
}node,* BinaryTree;

//前序遍历 前序遍历先根节点 后左子树 再右子树
void PreOrderTraverse(BinaryTree  t)
{
	if(t==NULL)
		return;

	printf("%c ",t->data);//显示结点数据 可以修改为对结点的其他操作 
	PreOrderTraverse(t->lchildPtr);
	PreOrderTraverse(t->rchildPtr);
}

//中序遍历
void InOrderTraverse(BinaryTree  t)
{
	 if(t==NULL)
		 return ;
	 InOrderTraverse(t->lchildPtr);
	 printf("%c ",t->data);
	 InOrderTraverse(t->rchildPtr);
}	

//后续遍历
void PostOrderTraverse(BinaryTree t)
{
	if(t==NULL)
		return;
	PostOrderTraverse(t->lchildPtr);
	PostOrderTraverse(t->rchildPtr);
	printf("%c ",t->data);
}

//按前序输入二叉树中结点的值
//#表示空树
Status CreateBinaryTree(BinaryTree * t)
{
	ElemType ch;
	scanf("%c",&ch);
	if(ch=='#')
		*t=NULL;
	else
	{
		*t=(BinaryTree)malloc(sizeof(node));
		
		if(!*t)//避免创建的数为空
			return ERROR;

		(*t)->data=ch;
		CreateBinaryTree(&(*t)->lchildPtr);
		CreateBinaryTree(&(*t)->rchildPtr);

	}
}

//中序生成
Status InCreateBinaryTree(BinaryTree * t)
{
	ElemType ch;
	scanf("%c",&ch);
	if(ch=='#')
		*t=NULL;
	else
	{
		*t=(BinaryTree)malloc(sizeof(node));
		
		if(!*t)//避免创建的数为空
			return ERROR;

		CreateBinaryTree(&(*t)->lchildPtr);
		(*t)->data=ch;
		CreateBinaryTree(&(*t)->rchildPtr);

	}
}

//后序生成树
Status PostCreateBinaryTree(BinaryTree * t)
{
	ElemType ch;
	scanf("%c",&ch);
	if(ch=='#')
		*t=NULL;
	else
	{
		*t=(BinaryTree)malloc(sizeof(node));
		
		if(!*t)//避免创建的数为空
			return ERROR;

		CreateBinaryTree(&(*t)->lchildPtr);
		CreateBinaryTree(&(*t)->rchildPtr);
		(*t)->data=ch;

	}
}

int main()
{
	BinaryTree t;
	CreateBinaryTree(&t);//生成这个数时 将串输入后 敲回车即可终止scanf的输入
	printf("前序遍历：\n");
	PreOrderTraverse(t);
	printf("\n");
	
	printf("中序遍历：\n");
	InOrderTraverse(t);
	printf("\n");
	
	printf("后续遍历:\n");
	PostOrderTraverse(t);
	printf("\n");

	return 0;
}

