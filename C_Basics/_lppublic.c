#include "_lppublic.h"

int ctoi(const char c)
{
	int res;
	switch (c)
	{
		case '0':
		    res=0;break;
		case '1':
			res=1;break;
		case '2':
			res=2;break;
		case '3':
			res=3;break;
		case '4':
			res=4;break;
		case '5':
			res=5;break;
		case '6':
			res=6;break;
		case '7':
			res=7;break;
		case '8':
			res=8;break;
		case '9':
			res=9;break;
		default:
			res=-1;break;
	}
	return res;
}

//calculate the y-power of x
int POW(const unsigned int x,unsigned const int y)
{
	int res=x;
	if(y==0)
		return 1;
	for(int i=1;i<y;i++)
	{
		res*=x;
	}
	
	return res;
}

int stringConvertNumSUM(char * str,int len)
{	
	int res=0;
	for(int i=0;i<len;i++)
	{
		res+=ctoi(*(str+i));
	}
	return res;
}

int ATOI(const char * nptr)
{
	int res=0;
	int len=0;
	while(1)
	{
		if((*(nptr+len))!='\0')
		{
			len++;
		}
		else
			break;
	}
	
	for(int i=0;i<len;i++)
	{
		int a=ctoi(*(nptr+i));
		int b=POW(10,len-i-1);
		res+=a*b;
	}
	
	return res;
}


double c_atof(const char * nptr)//convert string to double 
{
	double resInteger=0;
	double resDecimal=0;
	int len=0;
	int dot=0;
	for(int i=0;i!=-1;i++)
	{
		if(*(nptr+i)!='\0')
		{
			len++;
			if(*(nptr+i)=='.'&&dot==0)
			{
				dot=i;
			}
		}
		else
		{
			break;
		}
	}

	int index=0;
	char str[dot+1];
	memset(str,0,sizeof(str));
	for(int i=0;i<dot;i++)
	{
		*(str+i)=*(nptr+i);
	}
	resInteger=ATOI(str);

	int cimi=1;
	for(int i=dot+1;i<len;i++)
	{

		resDecimal+=(double)ctoi(*(nptr+i))/(double)(POW(10,cimi));
		cimi++;
	}
	return resInteger+resDecimal;
}

char *strstr1(const char* str, const char* substr)
{
	int strlen=0;
	int sublen=0;
	
	for(int i=0;*(str+i)!='\0';i++)
	{
		if(*(str+i)!=*(substr+i))
		{
			continue;
		}
		else
		{
			break;
		}
	}

}


size_t  strlen1( const char*  str)//Calculate the effective length of the string,excluding 0.
{
	size_t res=0;
	for(int i=0;*(str+i)!='\0';i++)
	{
		if(*(str+i)!='\0')
		{
			res++;
		}
		else
			break;
	}
	return res;
}

char *strcpy1(char* dest, const char* src)//copy src value to dest address and append 0
{
	int i=0;
	while(1)
	{
		if(*(src+i)!='\0')
		{
			*(dest+i)=*(src+i);
		}
		else
		{
			*(dest+i)='\0';
			break;
		}

		i++;
	}

	return dest;
}

char * strncpy1(char* dest,const char* src, const size_t n)
{
	//如果src字符串长度小于n，则拷贝完字符串后，在dest后追加0，直到n个。
	//
	//如果src的长度大于等于n，就截取src的前n个字符，不会在dest后追加0。
	//
	int i=0;
	while(1)
	{
		if(i<n)
		{
			*(dest+i)=*(src+i);
		}
		else
		{
			*(dest+i)='\0';
		}
		i++;
	}

	return dest;
}
