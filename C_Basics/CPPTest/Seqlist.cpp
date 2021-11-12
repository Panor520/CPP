#include <stdio.h>
#include <cstring>

#define MAXSIZE 20 //存储空间初始分配量
typedef int ElemType;//ElemType类型根据实际情况定，这里假设为int

typedef struct 
{
	ElemType data[MAXSIZE];//数组元素个数
	int length;//线性表当前长度，必小于数组长度
}SqList;


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

//将线性表的第i个元素返回,将结果传给参数e
Status GetElm(SqList * L,int i,ElemType *e)
{
	if(i > L->length || i < 1)
		return ERROR;
	*e=L->data[i-1];//数组下标从0开始
	return OK;
}

Status ListInsert(SqList * L,int i,ElemType &e )
{
	if(0<i && i<=L->length+1 && L->length>0)//插入位置必须在表头或表尾之间的位置
	{
		for(int k=L->length-1;k>=i-1;k--)
		{
			L->data[k+1]=L->data[k];
		}
	}

	L->data[i-1]=e;
	L->length++;
	return OK;
}

//删除位置i的元素，并将至由e返回
Status ListDelete(SqList * L,int i,ElemType *e)
{
	if(L==0 || L->length==0)
		return ERROR;

	*e=L->data[i-1];

	if(i>0 && i<L->length)
	{
		for(int k=i-1;k<L->length-1;k++)
		{
			L->data[k]=L->data[k+1];
		}
	}

	L->length--;

	return OK;
}

void ListShow(SqList * L)
{
	for(int i=0;i<L->length;i++)
	{
		printf(" %d ",L->data[i]);
	}
	printf("\n");
}

void ListClear(SqList * L)
{
	memset(L->data,0,sizeof(ElemType)*MAXSIZE);
	L->length=0;
}

void ListInitial(SqList * L)
{
	ListClear(L);
}


int main()
{
	SqList sl;
	SqList * slp=&sl;
	ListInitial(slp);

	printf("add new element! 5 4 3 2 1 \n");
	ElemType e=1;
	ListInsert(slp,1,e);
	e=2; ListInsert(slp,1,e);
	e=3; ListInsert(slp,1,e);
	e=4; ListInsert(slp,1,e);
	e=5; ListInsert(slp,1,e);
	ListShow(slp);

	printf("delete 3\n");
	ListDelete(slp,3,&e);
	ListShow(slp);
	printf("delete 3  e=%d\n",e);
	
	return 0;
}
