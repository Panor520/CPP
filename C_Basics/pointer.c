#include <stdio.h>

int main()
{
	int x;
	int * p=&x;
	printf(" &x=%p\n",&x);
	printf(" p=%p\n",p);
	printf(" &p=%p\n",&p);
	x=10;
	int * p1=&x;
	printf("-------\n");
	printf(" p1=%p\n",p1);


	return 0;
}

