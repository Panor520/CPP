#include <stdio.h>

#define MAXSIZE 5
#define OK 1
#define ERROR 0
typedef int Status;

typedef int ElemType;//假设为int
typedef struct
{
	ElemType data[MAXSIZE];
	int front;//头指针
	int rear;//尾指针
} StQueue;

Status InitQueue(StQueue * q)
{
	q->front=0;
	q->rear=0;
	return OK;
}

//放回当前队列长度
int QueueLength(StQueue * q)
{
	return (q->rear-q->front+MAXSIZE)%MAXSIZE;//如果push和del的指针变动不出错这里不取模也可以，但加上肯定不会错
}

Status PushQueue(StQueue *q,ElemType &e)
{
	if((q->rear+1)%MAXSIZE==q->front)//队满
	{
		printf("queue overflow! \n");
		return ERROR;
	}
	q->data[q->rear]=e;
	q->rear=(q->rear+1)%MAXSIZE;//尾指针+1  因为可能出现加1后溢出的问题故取模
	return OK;
}

Status DelQueue(StQueue * q,ElemType *e)
{
	if(q->rear==q->front)//队列为空
	{
		printf("queue is NULL\n");
		return ERROR;
	}

	*e=q->data[q->front];
	q->front=(q->front+1)%MAXSIZE;

	return OK;
}

void Show(StQueue * q)
{
	if(q->front==q->rear)
		return;
	int index=q->front;
	printf("front=%d rear=%d \n",q->front,q->rear);
	while(1)
	{
		printf("%d ",q->data[index]);
		index++;
		if(index > q->rear)
			break;
	}
	printf("\n");
}


int main()
{
	StQueue * q=new StQueue;
	InitQueue(q);
	printf("QueueLength=%d\n",QueueLength(q));
	
	ElemType e;
	e=10;
	PushQueue(q,e);

	e=11;
	PushQueue(q,e);

	e=12;
	PushQueue(q,e);

	e=13;
	PushQueue(q,e);
	
	e=14;
	PushQueue(q,e);
	
	Show(q);
	printf("QueueLength=%d\n",QueueLength(q));	
	
	
	printf("------------delqueue--------");
	DelQueue(q,&e);
	Show(q);
	printf("QueueLength=%d\n",QueueLength(q));	


	DelQueue(q,&e);
	Show(q);
	printf("QueueLength=%d\n",QueueLength(q));	

	DelQueue(q,&e);
	Show(q);
	printf("QueueLength=%d\n",QueueLength(q));	
	
	DelQueue(q,&e);
	Show(q);
	printf("QueueLength=%d\n",QueueLength(q));	
	
	
	DelQueue(q,&e);
	Show(q);
	printf("QueueLength=%d\n",QueueLength(q));	
	
	
	
	
	delete q;
	q=0;
	return OK;
}
