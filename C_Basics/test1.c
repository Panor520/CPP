#include "_lppublic.h"


void testctoi();
void testPOW();
void testStringCTNumSum();
void test_ATOI();
int test_getsrandnum();
void test_puke();
void test_c_atof();
void test_strlen1();
void test_strcpy();

int main()
{
	//testctoi();
	//testPOW();
	//testStringCTNumSum();
  	//test_ATOI();
	//test_getsrandnum();
	//test_puke();	
	//test_c_atof();
	//test_strlen1();
	test_strcpy();
}


void testctoi()
{
	printf("ctoi('0')=%d\n",ctoi('0'));
	return;
}

void testPOW()
{
	printf("--testPOW,pls input num:\n");
	int x,y;
	scanf("%d %d",&x,&y);

	printf("POW(%d,%d)=%d\n",x,y,POW(x,y));
	return;
}

void testStringCTNumSum()
{
	printf("--testStringCTNumSum,pls input sting:\n");
	char str[301];
	memset(str,0,sizeof(str));//initialize str \0

	scanf("%s",str);
	
  	int len=strlen(str);
	int res=stringConvertNumSUM(str,len);
	printf("str=%s,,sum=%d\n",str,res);
}

void test_ATOI()
{
	printf("-- test_ATOI,pls inpute string:\n");
	char str[301];
	memset(str,0,sizeof(str));
	
	scanf("%s",str);
	int res=ATOI(str);

	printf("res=%d\n",res);
}

int test_getsrandnum()
{
	int arr[52];
	memset(arr,0,sizeof(arr));

	srand(time(0));//use second time 
	int index=0;
	for(int j=0;index<52;j++)
	{
		int num=rand()%52+1;
		//	bool sameFlag=false; //c no bool type
		int sameFlag=0;

		for(int i=0;i<index;i++)
		{
			if(*(arr+i)==num)
			{
				sameFlag=1;
				break;
			}
		}

		if(sameFlag==0)
		{
			*(arr+index)=num;
			index++;
		}
	}

	//printf arr
	for(int i=0;i<52;i++)
	{
		printf("arr[%d]=%d\n",i,*(arr+i));
	}
}

void test_puke()
{

	int arr[52];
	memset(arr,0,sizeof(arr));

	srand(time(0));//use second time 
	int index=0;
	for(int j=0;index<52;j++)
	{
		int num=rand()%52+1;
		//	bool sameFlag=false; //c no bool type
		int sameFlag=0;

		for(int i=0;i<index;i++)
		{
			if(*(arr+i)==num)
			{
				sameFlag=1;
				break;
			}
		}

		if(sameFlag==0)
		{
			*(arr+index)=num;
			index++;
		}
	}

	//fa pai
	int player[4][13];
	memset(player,0,sizeof(player));
	
	for(int i=0;i<13;i++)
	{
		player[0][i]=arr[i]+0;
		player[1][i]=arr[i]+1;
		player[2][i]=arr[i]+2;	
		player[3][i]=arr[i]+3;
	}

	for(int i=0;i<13;i++)
	{
		printf("[0][%d]=%d\n",i,player[0][i]);
	}
	printf("------------\n");

	for(int i=0;i<13;i++)
	{
		printf("[1][%d]=%d\n",i,player[1][i]);
	}
	printf("-----------\n");
	
	for(int i=0;i<13;i++)
	{
		printf("[2][%d]=%d\n",i,player[2][i]);
	}
	printf("----------\n");
	
	for(int i=0;i<13;i++)
	{
		printf("[3][%d]=%d\n",i,player[2][i]);
	}
	printf("\n");
}


void test_c_atof()
{
	printf("-------test_c_atof,pls input str:\n");
	char  str[301];
	scanf("%s",str);
	double res=c_atof(str);

	printf("convert %s to double:%lf\n",str,res);

}

void test_strlen1()
{
	printf("------test_strlen,pls input string:\n");
	char str[301];
	scanf("%s",str);
	printf("strlen1(str)=%ld\n",strlen1(str));
}

void test_strcpy()
{
	printf("-------test strcpy(str1,str2),pls input str2:\n");
	char str1[500];
	char str2[301];
	
	memset(str1,0,sizeof(str1));
	memset(str2,0,sizeof(str2));
	scanf("%s",str2);
	printf("dest=&str1=%p\n",str1);
	printf("strcpy(str1,str2)=%p\n",strcpy1(str1,str2));
	printf("str2=%s\n",str2);
}
