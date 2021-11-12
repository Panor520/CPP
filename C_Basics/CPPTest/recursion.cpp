#include <stdio.h>


int fbi(int i)
{
	if(i<2)
		return i==0?0:1;
	
	return fbi(i-1)+fbi(i-2);
}

int main()
{
	int i=10;
	for(int j=0;j<=10;j++)
		printf("%d ",fbi(j));
	printf("\n");
	printf(" %d ",fbi(i));
	return 0;
}
