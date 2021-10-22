#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(int argc,char *argv[])
{
	if (argc!=3)
	{
	    printf("Using:./book source dest\n");
	    printf("Example:./book /tmp/aaa.txt /tmp/bbb.txt\n");
	    printf("本程序的功能是文件复制，source是源文件名，dest是目标文件名。\n");
	    return -1;
	}

	FILE * source,* target;
	
	source=fopen(argv[1],"r");
	if(source==0)
	{
		printf("fopen(%s) failed",argv[1]);
		return -1;
	}

	target=fopen(argv[2],"w");
	if(target==0)
	{
		printf("fopen(%s) failed",argv[2]);
		return -1;
	}

	int readN=0;
	int * str=malloc(100); //只需要一个指针存放100字节的内存的首地址即可，什么类型的指针无所谓
	while(1)
	{
		//读取100个字节
		readN=fread(str,1,100,source);
		if(readN==0)
			break;
		//将100个字节写入文件
		fwrite(str,1,readN,target);
	}
	free(str);
	fclose(source);
	fclose(target);

	

return 0;
}

