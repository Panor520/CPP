#include <stdio.h>
#include <cstdlib>

#define MAXSIZE 10 //假设链表最大长度为50
typedef int ElemType;//ElemType类型根据实际情况定，这里假设为int
#define  ElemNULL 0;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef struct Node
{
	ElemType data;//链表数据域
	struct Node * next;
}* LinkStackPtr;

typedef struct
{
	LinkStackPtr top;//栈顶，头结点的位置，如果为null即为空栈
	int count;
}LinkStack;

Status Push(LinkStack * l,ElemType & e)
{
	if(l->count>=MAXSIZE)
		return ERROR;
	LinkStackPtr lp=(LinkStackPtr)malloc(sizeof(struct Node));
	lp->data=e;
	lp->next=l->top;//栈顶
	l->top=lp;//新生成的为栈顶头结点,这个头结点是有数据域的数据的
	l->count++;
	return OK;
}

Status Pop(LinkStack * l,ElemType * e)
{
	if(l->count<=0)
		return ERROR;

	*e=l->top->data;

	LinkStackPtr temp;//free时一定要定义这个类型指针
	temp=l->top;
	l->top=l->top->next;
	free(temp);
	temp->next=NULL;
	l->count--;
	

	return OK;
}

void Show(LinkStack l)//这个地方show不能用指针 否则会影响原始数据
{
	LinkStackPtr temp;
	int count=l.count;
	while(1)
	{	
		temp=l.top;
		printf("top->bottom data=%d \n",temp->data);
			
		l.top=l.top->next;
		count--;
		
		if(count<=0)
			break;
	}
}

Status Initialize(LinkStack * l)
{
	l->top=NULL;
	l->count=0;
	return OK;
}

Status main()
{
	LinkStack* ls;
	Initialize(ls);
	ElemType e;

	e=1;
	Push(ls,e);

	e=2;
	Push(ls,e);
	e=3;
	Push(ls,e);
	e=4;
	Push(ls,e);
	
	Show(*ls);
	printf("\n");

	Pop(ls,&e);
	Show(*ls);


}
