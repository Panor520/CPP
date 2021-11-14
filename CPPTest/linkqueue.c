#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define ElemNULL 0
typedef int  ElemType;
typedef int  Status;

typedef struct Node
{
	ElemType data;
	struct Node * next;
}node,*NodePtr;

typedef struct
{
	NodePtr front;
	NodePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue * l)
{
	NodePtr frontNode=(NodePtr)malloc(sizeof(node));
	frontNode->data=ElemNULL;
	frontNode->next=NULL;

	l->front=frontNode;
	l->rear=frontNode;
	return OK;
}

Status PushElem(LinkQueue * l , ElemType *e)//只能在队尾插入，故和单链表相比没有插入位置一说
{
	//node temp;
	//temp.data=e;
	//temp.next=NULL;
	NodePtr temp=(NodePtr)malloc(sizeof(node));
	temp->data=*e;
	temp->next=NULL;
	
	l->rear->next=temp;//队尾接上新增节点
	l->rear=temp;//新增节点为队尾
	return OK;
}

Status DelElem(LinkQueue * l,ElemType * e)//出队是从头节点出
{
	if(l->front->next==NULL)
	{
		printf("Queue is NULL \n");
		return ERROR;
	}
	NodePtr temp=l->front;
	*e=temp->data;
	l->front=temp->next;

	if(l->rear == temp)//删除最后一个节点的特殊情况处理
		l->rear=l->front;

	free(temp);
	return OK;
}

void Show(LinkQueue *l)
{
	NodePtr index=l->front->next;
	while(1)
	{
		if(index==NULL)
			break;
		printf("%d ",index->data);
		index=index->next;
	}

	printf("\n");
}

int main()
{
	LinkQueue * l=malloc(sizeof(LinkQueue));
	
	InitQueue(l);
	
	ElemType e;
	e=11;
	PushElem(l,&e);

	e=12;
	PushElem(l,&e);

	e=13;
	PushElem(l,&e);

	Show(l);
	
	printf("-----------------DelElem--------------\n");
	DelElem(l,&e);
	Show(l);

	DelElem(l,&e);
	Show(l);
		
	DelElem(l,&e);
	Show(l);

	DelElem(l,&e);
	Show(l);

	free(l);
	l=0;
	return 0;
}
