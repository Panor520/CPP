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

typedef struct 
{
	ElemType data;
	int cur;//游标，为0时表示无指向
}Component,StaticLinkList[MAXSIZE];//StaticLinkList[MAXSIZE]代表一个Component数组中有MAXSIZE个Component元素。

//把未被使用的数组元素称为备用链表
//数组第一个元素即下标为0的元素的cur用来存放备用链表第一个节点的下标
//数组最后一个元素的cur则存放第一个有数值的元素的游标，相当于单链表头结点的作用。

Status InitList(StaticLinkList L)
{
	if(L==NULL)
		return ERROR;
	int i;
	for(i=0;i<MAXSIZE-1;i++)
	{
		L[i].cur=i+1;//游标从1开始，数组下标从0开始。
		L[i].data=ElemNULL;
	}
	L[MAXSIZE-1].data=ElemNULL;
	L[MAXSIZE-1].cur=0;//最后一个数组元素的游标必须为0，代表无指向。
	return OK;
}

int Malloc_SSL(StaticLinkList L)
{
	int i=L[0].cur;//第一个元素的游标值始终是备用链表的第一个元素的下标，故以此来获取备用链表中第一个节点作为待插入的新节点

	if(L[0].cur)
		L[0].cur=L[i].cur;//如果第一个元素的游标不为0，则第一个元素的游标就应该为下一个可用节点的游标

	return i;
}


Status InsertList(StaticLinkList L,int i,ElemType e)
{
	int j,k,l;
	k=MAXSIZE-1;//k赋值为MAXSIZE-1的原因就是 
	if(i<1 || i>MAXSIZE-1)
		return ERROR;
		
	j=Malloc_SSL(L);//在备用链表中获取新元素的下标
	
	if(j)
	{
		L[j].data=e;//给新元素数据域赋值

		for(l=1;l<i;l++)
			k=L[k].cur;//找到第i个元素之前元素的下标
		
		L[j].cur=L[k].cur;//将原来i个元素之前元素的游标值赋给新元素的游标
		L[k].cur=j;//将最后一个元素(类似头结点)的游标赋值为数组首元素的下标
		return OK;
	}

	return ERROR;
}

Status DisplayList(StaticLinkList L)
{
	if(L==NULL)
		return ERROR;
	int i=L[MAXSIZE-1].cur;//头结点的游标就是第一个元素的下标
	while(i)
	{
		printf("L[%d].data=%d L[%d].cur=%d \n",i,L[i].data,i,L[i].cur);
		i=L[i].cur;//始终让i的值为链表下一个节点的游标值（也就是下标值）  循环直到数组尾节点游标为0
	}
	return OK;
}

//要执行free必须保证数组不为空且有k元素
void Free_SSL(StaticLinkList L,int k)
{
	L[k].cur=L[0].cur;//将要删除的元素作为备用链表的第一个元素
	L[k].data=ElemNULL;//将要释放的元素的值置空
	L[0].cur=k;//将要删除的元素作为备用链表的第一个元素
}

Status DeleteList(StaticLinkList L,int i)
{
	int j,k;
	if(i<1 || i>MAXSIZE-1)
		return ERROR;
	k=MAXSIZE-1;

	for(j=1;j<i;j++)
		k=L[k].cur;//从头结点的下标开始 这个地方就是游标循环往下走，找到第i个元素的前一个元素的游标
	
	j=L[k].cur;//找到被删除元素前一个元素的游标
	L[k].cur=L[j].cur;

	Free_SSL(L,j);
	return OK;
}

int main()
{
	StaticLinkList L;
	InitList(L);
	
	ElemType e;
	e=10;
	InsertList(L,1,e);
	e=11;
	InsertList(L,1,e);
	e=12;
	InsertList(L,1,e);
	e=13;
	InsertList(L,1,e);
	e=14;
	InsertList(L,1,e);
	
	DisplayList(L);
	
	DeleteList(L,3);
	printf("\n");
	DisplayList(L);

	DeleteList(L,1);
	printf("\n");
	DisplayList(L);
}
