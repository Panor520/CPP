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
	int srclen=strlen1(src);
	if(srclen<n)
	{
		while(1)
		{
			if(i<srclen)
			{
				*(dest+i)=*(src+i);
			}
			else
			{
				*(dest+i)='\0';
			}
			
			i++;

			if(i==n)
				break;
		}
	}
	else if(srclen>=n)
	{
		while(1)
		{
			*(dest+i)=*(src+i);

			i++;
			if(i==n)
				break;
		}
	}
	return dest;
}

char *strcat1(char* dest,const char* src)
{
	int destlen=strlen1(dest);
	int srclen=strlen1(src);
	int i=0;
	while(1)
	{
		if(i==srclen)
		{
			*(dest+destlen+i)='\0';
			break;
		}
		*(dest+destlen+i)=*(src+i);
		
		i++;
	}
	return dest;
}

char *strncat1(char* dest,const char* src, const size_t n)
{
	//如果n大于等于字符串src的长度，那么将src全部追加到dest的尾部，如果n小于字符串src的长度，只追加src的前n个字符。
	//strncat会将dest字符串最后的0覆盖掉，字符追加完成后，再追加0。
	int srclen=strlen1(src);
	int destlen=strlen1(dest);

	int i=0;
	if(srclen<n)
	{
		while(1)
		{
			if(i==srclen)
			{
				*(dest+destlen+i)='\0';
				break;
			}
			*(dest+destlen+i)=*(src+i);
			
			i++;
		}
	}
	else//srclen>=n
	{
		while(1)
		{
			if(i==n)
			{
				*(dest+destlen+i)='\0';
				break;
			}
			*(dest+destlen+i)=*(src+i);

			i++;
		}
	}
	return dest;
}

int strcmp1(const char *str1, const char *str2 )
{//相等返回0，str1大于str2返回1，str1小于str2返回-1；
	int str1len=strlen1(str1);
	int str2len=strlen1(str2);
	
	int res=-2;
	int i=0;
	while(1)
	{
		if(i==str1len && i<str2len)
		{
			res=-1;
			break;
		}
		if(i==str2len && i<str1len)
		{
			res=1;
			break;
		}
		if(i==str1len && i==str2len)
		{
			break;
		}


		if(*(str1+i)>*(str2+i))
		{
			res= 1;
			break;
		}
		else if(*(str1+i)<*(str2+i))
		{
			res= -1;
			break;
		}
		else if(*(str1+i)==*(str2+i))
		{
			res=0;
		}

		i++;
	}
	return res;
}

int strncmp1(const char *str1,const char *str2 ,const size_t n)
{//str1=str2:0 | str1>str2:1 | str1<str2:-1
	
	int str1len=strlen1(str1);
	int str2len=strlen1(str2);
	
	int res=-2;
	int i=0;
	while(1)
	{
		if(i==str1len && i<str2len)
		{
			res=-1;
			break;
		}
		if(i==str2len && i<str1len)
		{
			res=1;
			break;
		}
		if(i==str1len && i==str2len)
		{
			break;
		}


		if(*(str1+i)>*(str2+i))
		{
			res= 1;
			break;
		}
		else if(*(str1+i)<*(str2+i))
		{
			res= -1;
			break;
		}
		else if(*(str1+i)==*(str2+i))
		{
			res=0;
		}

		i++;

		if(i==n)
			break;
	}
	return res;
	
}

char *strchr1(const char *s,const int c)
{//返回一个指向在字符串s中第一个出现c的位置，如果找不到，返回0。
	char * res=0;
	int slen=strlen1(s);
	int i=0;
	while(1)
	{
		if((int)(*(s+i))==c)
		{
			res=(char *)s+i;
			break;
		}
		i++;
		if(i==slen)
			return (void*)0;
	}
	return res;
}

char *strrchr1(const char *s,const int c)
{//返回一个指向在字符串s中最后一个出现c的位置，如果找不到，返回0。
		
	char * res=0;
	int slen=strlen1(s);
	int i=0;
	while(1)
	{
		if((int)(*(s+i))==c)
		{
			res=(char *)s+i;
		}
		i++;
		if(i==slen)
			break;
	}
	return res;
}

char *strstr1(const char* str, const char* substr)
{//检索子串在字符串中首次出现的位置。
	int strlen=strlen1(str);
	int sublen=strlen1(substr);
	
	char * res=0;
	int i=0;
	while(1)
	{
		int j=0;
		while(1)
		{
			if(*(str+i+j)==*(substr+j))
			{
				if(j==sublen-1)
				{
					res=(char *)(str+i);
				}
				j++;
			}
			else
			{
				j++;
				break;
			}

			if(j==sublen)
				break;
		}

		i++;
		if(i==strlen||res!=0)
			break;
	}
	return res;
}

int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value)
{//in_FieldName，字段的标签名。out_Value，获取字段标签存放的变量的指针。 返回值，0-成功，-1-失败。
	if(out_Value==0)
		return -1;
	
	int bufferlen=strlen1(in_XMLBuffer);
	int fieldnamelen=strlen1(in_FieldName);
	
	char * field_start=strstr1((char *)in_XMLBuffer,(char *)in_FieldName);
	if(field_start==0)
		return -1;
	
	char * field_end=strstr1((char *)(field_start+fieldnamelen),(char *)in_FieldName);
	if(field_end==0)
		return -1;

	int subn=field_end-2-(field_start+fieldnamelen+1);
	strncpy1(out_Value,(field_start+fieldnamelen+1),subn);
	//out_Value
	
	return 0;
}

int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value)
{
	char strvalue[51];
	memset(strvalue,0,sizeof(strvalue));

	if (GetXMLBuffer_Str(in_XMLBuffer,in_FieldName,strvalue)!=0) return -1;

	(*out_Value)=atoi(strvalue);

	return 0;
}

int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value)
{   
	char strvalue[51];
	memset(strvalue,0,sizeof(strvalue));

	if (GetXMLBuffer_Str(in_XMLBuffer,in_FieldName,strvalue)!=0) return -1;
		    
	(*out_Value)=atof(strvalue);
	return 0;
}

int timetostr(const time_t ti,char *strtime)
{//把整数的时间转换为字符串格式的时间

	struct tm * now=localtime(&ti);
	if(now!=0)
	{
		sprintf(strtime,"%d-%02u-%02u %02u:%02u:%02u", now->tm_year+1900,now->tm_mon,now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
		return 0;
	}
	return -1;
}

int strtotime(const char *strtime,time_t *ti)
{//把字符串格式的时间转换为整数的时间:2019-02-08 12:05:08
	struct tm  tms;
	char * temp=malloc(5);
	memset(temp,0,5);
	temp=strncpy(temp,strtime,4);
	tms.tm_year=atoi(temp)-1900;
	
	memset(temp,0,5);
	temp=strncpy(temp,strstr(strtime,"-")+1,2);
	tms.tm_mon=atoi(temp);

	memset(temp,0,5);
	temp=strncpy(temp,strstr(strstr(strtime,"-")+1,"-")+1,2);
	tms.tm_mday=atoi(temp);


	memset(temp,0,5);
	temp=strncpy(temp,strstr(strtime," ")+1,2);
	tms.tm_hour=atoi(temp);

	memset(temp,0,5);
	temp=strncpy(temp,strstr(strtime,":")+1,2);
	tms.tm_min=atoi(temp);

	memset(temp,0,5);
	temp=strncpy(temp,strstr(strstr(strtime,":")+1,":")+1,2);
	tms.tm_sec=atoi(temp);
	free(temp);

	*ti=mktime(&tms);
	if(*ti!=0)
		return 0; 
	return -1;
}

