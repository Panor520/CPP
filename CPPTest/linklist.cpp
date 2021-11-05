#include <stdio.h>
#include <cstdlib>

#define MAXSIZE 20 //存储空间初始分配量
typedef int ElemType;//ElemType类型根据实际情况定，这里假设为int
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}node,*LinkList;//每个节点都是一个node结构体，也是一个Node结构体指针LinkList.


Status GetElem(LinkList L,int i,ElemType *e)
{
	if(i<=0)
		return ERROR;
	int j=1;//计数器
	LinkList p=L->next;//定义指针指向第一个节点，头结点后的第一节点

	while(p && j<i)//p不为空，且p的位置还不到i时循环继续
	{
		p=p->next;//当j=i-1时，P所在的节点刚好是i的位置，j=0代表头结点，j=1代表第一个节点
		j++;	
	}

	*e=p->data;

	return OK;
}

Status InsertElem(LinkList L,int i,ElemType *e)
{
	if(i<=0)
		return ERROR;
	int j=1;
	LinkList p=L;//p代表第一个节点 
	//等价于node * p=L->next;

	while(p!=0 &&j<i)//p不为空
	{
		p=p->next;
		j++;
	}
	
	node * temp=(node*)malloc(sizeof(node));
	temp->data=*e;
	temp->next=p->next;
	p->next=temp;

	return OK;
}

Status DeleteElem(LinkList L,int i,ElemType *e)
{
	if(i<=0)
		return ERROR;
	int j=1;
	LinkList p=L;
	while(p!=0&&j<i)
	{
		p=p->next;
		j++;
	}

	LinkList q=p->next;
	*e=p->next->data;
	p->next=p->next->next;
	free(q);// free()释放的是指针指向的空间内存，不是指针；这里直接free(p->next)会报错，因为p->next的值只是个地址，而free必须是指针变量名（变量名涵盖空间内存）
	q=NULL;//避免野指针
	return OK;
}

Status ClearList(LinkList L)
{
	LinkList p,q;
	p=L->next;
	while(p!=NULL)//空链表直接退出或尾节点退出
	{
		q=p->next;//获取下一个节点
		free(p);//将上一个节点释放 //这个地方释放也就意味着L中的数据必须是malloc动态分配出来的，否则一直报invalid size的错误	
		p=q;
	}
	L->next=NULL;

	return OK;
}

int main()
{
	LinkList L;
	node* n0=(node *)malloc(sizeof(node));
	node* n1=(node *)malloc(sizeof(node));
	node* n2=(node *)malloc(sizeof(node));
	node* n3=(node *)malloc(sizeof(node));
	
	L->next=n1;
	n1->next=n2;
	n2->next=n3;
	n3->next=0;

	n1->data=1;
	n2->data=2;
	n3->data=3;

	ElemType e;
	e=10;
	InsertElem(L,1,&e);
	

	GetElem(L,1,&e);
	printf("e=%d\n",e);

	DeleteElem(L,1,&e);
	GetElem(L,1,&e);
	printf("e=%d\n",e);

	ClearList(L);
}
