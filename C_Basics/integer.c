#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testatoi();

int main()
{
	//二进制
	int two1=0b11;
	printf("%d\n",two1);
	
	int eight1=015;//1*8的一次方+5*8的零次方=8+5=13
	printf("%d\n",eight1);

	int sixteen1=0xba;//10*16的零次方+11*16的零次方=10+176=186
	printf("%d\n",sixteen1);

	testatoi();
	return 0;
}

void testatoi()
{
	char str[10];
	memset(str,0,sizeof(str));
	scanf("%s",str);
	int strInteger=atoi(str);
	printf("%d\n",strInteger+100);
}
