#include <stdio.h>
#include <string.h>
#include <stdarg.h>

class CGirl
{
public:
	char m_name[50];
	int m_age;
	int m_height;
	char m_sc[30];
	char m_yz[30];
	int Show();
};

void testclass(CGirl* GirlArr)
{
	printf("-----对象数组as parameter----\n");
	//CGirl GirlArr[10];//定义对象数组，就是生成10个对象
//	GirlArr->m_age=165;//0
//	(GirlArr+sizeof(CGirl)*1)->m_age=166;//2
//	(GirlArr+sizeof(CGirl)*3)->m_age=167;//4
//	(GirlArr+sizeof(CGirl)*5)->m_age=168;//6
//	printf("0.age=%d 2.age=%d 3.age=%d 4.age=%d 6.age=%d \n",\
//			GirlArr->m_age,(GirlArr+sizeof(CGirl)*1)->m_age,(GirlArr+sizeof(CGirl)*2)->m_age,(GirlArr+sizeof(CGirl)*3)->m_age,(GirlArr+sizeof(CGirl)*5)->m_age);
	

	GirlArr[0].m_age=165;//0
	(GirlArr[2]).m_age=166;//2
	(GirlArr[4]).m_age=167;//4
	(GirlArr[6]).m_age=168;//6
	printf("0.age=%d 2.age=%d 3.age=%d 4.age=%d 6.age=%d \n",\
			GirlArr[0].m_age,(GirlArr[2]).m_age,(GirlArr[3]).m_age,(GirlArr[4]).m_age,(GirlArr[6]).m_age);
	
	
}

void testclasspointer()
{
	CGirl * cg;
	CGirl cg1;
	cg=&cg1;

	cg->m_age=18;
	printf("classpointer:%d\n",cg->m_age);
}

void testclassparameter(CGirl cg)
{
	cg.m_age=19;
	printf("classparameter:%d\n",cg.m_age);
}

void testclassparameter(CGirl * cg)
{
	    cg->m_age=20;
	    printf("classparameter:%d\n",cg->m_age);
}

int myprintf(const char *format, ...)
{
	va_list arg;
	va_start(arg,format);
	vprintf(format,arg);//vfprintf函数把宏分析的结果输出到文件是C语言自带的。
	va_end(arg);
	return 0;
}

int myfprintf(FILE *stream, const char *format, ...)  // 格式化输出到文件
{
	fflush(stream);
	va_list arg;
	va_start(arg,format);
	vfprintf(stream,format,arg);
	va_end(arg);
	return 0;
}

int mysprintf(char *str,const char *format, ...)
{
	va_list arg;
	va_start(arg,format);
	vsprintf(str,format,arg);
	va_end(arg);
	return 0;
}

int mysnprintf(char *str, size_t size, const char *format,...)
{
	va_list arg;
	va_start(arg,format);
	vsnprintf(str,size,format,arg);//vfprintf函数把宏分析的结果输出到文件是C语言自带的。
	va_end(arg);
	return 0;
}

void testyinyong(int &a)
{
	printf("&&a=%p \n",&a);
}

int b=3;

int& testyinyong2()
{
//	int b=1;
	printf("&b=%p\n",&b);
	return b;
}

class girl 
{
public:
	void setage(int&num);
	int &showage();
private:
	int age;
};

void girl::setage(int& num)
{
	age=num;
}

int &girl::showage()
{
	printf("age=%d\n",age);
	return age;
}

int main()
{
	CGirl GirlArr[10];//定义对象数组，就是生成10个对象
	testclass(GirlArr);

	testclasspointer();

	CGirl cg;
	testclassparameter(cg);
	testclassparameter(&cg);

	myprintf("%s %d %d \n","test myprintf()",1,2);

	FILE * filePoint=fopen("test_fprintf.c","w");//利用 vim test_fprintf.c 查看结果
	if(filePoint==0)
		printf("fopen failed!\n");

	myfprintf(filePoint,"%s %d %s","hello",100,"world\n");
	fclose(filePoint);

	char str[300];
	mysprintf(str,"%d %s %d ",1,"test mysprintf()",3);//将format的内容整体转为字符串赋值给str，不会向printf一样输出
	printf("%s\n",str);	

	memset(str,0,sizeof(str));
	mysnprintf(str,4,"%d %d %s",1,100,"test2");//将format的内容转为字符串后将n-1个字符复制到str中，不会向printf一样输出
	printf("%s\n",str);
	
	int a=10;
	testyinyong(a);
	printf("&a=%p\n",&a);
	
	int c=testyinyong2();
	int &d=testyinyong2();
	printf("&c=%p\n",&c);
	printf("&d=%p\n",&d);

	girl g;
	//g.age=18;
	int age=18;
	g.setage(age);
	int &e=g.showage();
	e=19;
	g.showage();
}
