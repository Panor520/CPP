#include <stdio.h>

#define MAXSIZE 5
#define  ElemNULL 0;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;//这里暂定为int
typedef struct
{
	SElemType data[MAXSIZE];
	int top;//栈顶指针
}SqStack;

Status Initialize(SqStack * S)
{
	S->top=-1;
	return OK;
}

Status Push(SqStack * S,SElemType & e)
{
	if(S->top>=MAXSIZE-1)//栈满
		return ERROR;

	S->top++;
	S->data[S->top]=e;
	return OK;
}

Status Pop(SqStack * S,SElemType &e)
{
	if(S->top<-1)
		return ERROR;
	e=S->data[S->top];
	S->data[S->top]=ElemNULL;
	S->top--;
	return OK;
}

void Show(SqStack * S)
{
	int index=0;
	while(1)
	{
		if(index>S->top)
			break;
		printf("S->top=%d S->data=%d \n",index,S->data[index]);
		index++;
	}
}

int main()
{
	SqStack * s;
	Initialize(s);
	
	SElemType e=10;
	Push(s,e);
	e=11;
	Push(s,e);
	e=12;
	Push(s,e);
	e=13;
	Push(s,e);
	Show(s);

	printf("\n");
	printf("before pop top=%d\n",s->data[s->top]);
	
	Pop(s,e);

	Show(s);
	printf("after pop top+1=%d\n",s->data[s->top+1]);
}
