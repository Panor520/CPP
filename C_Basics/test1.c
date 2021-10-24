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
void test_strncpy();
void test_strcat();
void test_strncat();
void test_strcmp();
void test_strncmp();
void test_strchr();
void test_strrchr();
void test_strstr();
void test_malloc();
void test_GetXMLBuffer_Str();
void test_file();
void test_binaryfile();
void test_fpposition();
void test_filework();
void test_directory();
void test_time();
void test_Customize_mkdir();


struct st_girl
{
	  char name[51];   // 姓名
	  int  age;        // 年龄
	  int  height;     // 身高，单位：cm
	  double weight;     // 体重，单位：kg
	  char sc[31];     // 身材，火辣；普通；飞机场
};

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
	//test_strcpy();
	//test_strncpy();
	//test_strcat();
	//test_strncat();
	//test_strcmp();
	//test_strncmp();
	//test_strchr();
	//test_strrchr();
	//test_strstr();
	//test_GetXMLBuffer_Str();
	//test_malloc();
	//test_file();
	//test_binaryfile();
	//test_fpposition();
	//test_filework();
	//test_directory();
	//test_time();
	test_Customize_mkdir();
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

void test_strncpy()
{
	printf("-----test_strncpy,pls input  src(len=5) n:\n");
	char dest[301];
	int n;
	char src[5]="1234";

	scanf("%d",&n);
	
	char *add=strncpy1(dest,src,n);
	
	printf("&dest=%p\n",add);
	printf("dest=%s src=%s\n",dest,src);
}

void test_strcat()
{
	printf("-----test_strcpy.pls input src(len=10):\n");
	char dest[301]="exist string:";
	char src[10];
	scanf("%s",src);
	
	printf("dest:%s\n",dest);
	printf("&dest=%p\n",strcat1(dest,src));
	printf("src:%s\n",src);
	printf("dest:%s\n",dest);
}

void test_strncat()
{
	printf("-----test_strncat.pls input src(len=9) n=:\n");
	char dest[301]="exist string:";
	char src[10]="123456789";
	int n;
	scanf("%d",&n);
	printf("dest=%s\n",dest);
	printf("&dest=%p\n",dest);
	printf("&dest=%p\n",strncat1(dest,src,n));
	printf("src=%s\n",src);
	printf("dest=%s\n",dest);
}

void test_strcmp()
{
	printf("-----test_strcmp,pls input str1 str2:\n");
	printf("str1=str2:0 | str1>str2:1 | str1<str2:-1\n");
	char str1[100];
	char str2[100];

	scanf("%s %s",str1,str2);
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	printf("strcmp1(str1,str2)=%d\n",strcmp1(str1,str2));
}

void test_strncmp()
{
	printf("-----test_strcmp,pls input str1 str2 n:\n");
	printf("str1=str2:0 | str1>str2:1 | str1<str2:-1\n");
	char str1[100];
	char str2[100];
	int n;

	scanf("%s %s %d",str1,str2,&n);
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	printf("strcmp1(str1,str2)=%d\n",strncmp1(str1,str2,n));
}

void test_strchr()
{
	printf("-----test_strchr,pls input str chr:\n");
	printf("返回一个指向在字符串s中第一个出现c的位置，如果找不到，返回0。\n");
	char str[301];
	char chr;
	memset(str,0,sizeof(str));

	char * zeroadd=0;
	scanf("%s %c",str,&chr);
	printf("str=%s,chr=%c\n",str,chr);
	printf("&0=%p\n",zeroadd);
	printf("&str=%p\n",str);
	printf("strchr1(str,chr)=%p\n",strchr1(str,chr));
}

void test_strrchr()
{
	printf("-----test_strrchr,pls input str chr:\n");
	printf("返回一个指向在字符串s中第一个出现c的位置，如果找不到，返回0。\n");
	char str[301];
	char chr;
	memset(str,0,sizeof(str));

	scanf("%s %c",str,&chr);
	printf("str=%s,chr=%c\n",str,chr);
	printf("&0=%p\n",(void*)0);
	printf("&str=%p\n",str);
	printf("strchr1(str,chr)=%p\n",strrchr1(str,chr));
}

void test_strstr()
{
	printf("-----test_strstr,pls input str substr:\n");
    printf("检索子串在字符串中首次出现的位置。。\n");
	char str[301];
	char substr[10];
	memset(str,0,sizeof(str));

	scanf("%s %s",str,substr);
	printf("str=%s,substr=%s\n",str,substr);
	printf("&0=%p\n",(void*)0);
	printf("&str=%p\n",str);
	printf("strstr1(str,substr)=%p\n",strstr1(str,substr));
}


void test_GetXMLBuffer_Str()
{
	struct st_girl stgirl;
	memset(&stgirl,0,sizeof(struct st_girl));
	char str[301];
	memset(str,0,sizeof(str));
	
	strcpy1(stgirl.name,"haha");
	stgirl.age=18;
	stgirl.height=165;
	stgirl.weight=100;
	strcpy1(stgirl.sc,"best");
	sprintf(str,\
			         "<name>%s</name><age>%d</age><height>%d</height><weight>%.2lf</weight><sc>%s</sc>",\
					           stgirl.name,stgirl.age,stgirl.height,stgirl.weight,stgirl.sc);
	  
	printf("=%s=\n",str);
	char resname[51];
	memset(resname,0,sizeof(resname));
	int res=GetXMLBuffer_Str(str,"sc",resname);
	printf("res=%d  resname=%s\n",res,resname);

}

struct girl
{
	char name[20];
	int height;
};

void test_malloc()
{
	int * p=malloc(sizeof(int));
	double * p1=malloc(sizeof(double));
	char * p2 =malloc(101);//可以存放100个字符的字符串。
	memset(p2,0,101);

	struct girl * p4=malloc(sizeof(struct girl));

	//像使用指针一样使用动态分配的内存
	*p=1000;
	printf("*p=%d\n",*p);

	*p1=20;
	printf("*p1=%lf\n",*p1);

	//*p2="hahahahah\0";//字符串不能这样赋值
	strcpy1(p2,"hahahahah");
	printf("p2=%s\n",p2);
	
	strcpy1(p4->name,"xishi");
	p4->height=165;
	printf("name=%s height=%d\n",p4->name,p4->height);

	//动态分配的内存一定要记得释放
	free(p);
	p=0;
	free(p1);
	p1=0;
	free(p2);
	p2=0;
	free(p4);
	p4=0;
}

void test_file()
{
	FILE * fp=0;//定义文件指针变量

	//以只读方式发开文件
	if((fp=fopen("testfile.c","a+"))==0)
	{
		printf("打开文件失败！\n");
	}
	else
	{
		printf("打开文件成功！fp=%p\n",fp);
		printf("写入文件中---\n");
		for(int i=0;i<3;i++)
		{
			fprintf(fp,"zheshidi %d hang\n",i);
		}

		FILE * fp1=0;
		fp1=fopen("testfile.c","a+");
		char * buffer=malloc(301);
		
		for(int i=0;i<3;i++)
		{
			memset(buffer,0,301);
			if(fgets(buffer,301,fp1)==0)
				break;
			printf("%s",buffer);
		}
		free(buffer);
		buffer=0;

		fclose(fp);
		fclose(fp1);
	}
}

void test_binaryfile()
{
	printf("-----test_binaryfile\n");
	struct st_girl stgirl;
	FILE *fp=0;
	
	if((fp=fopen("testbinary.dat","a+"))==0)
	{
		printf("fopen failed\n");
	}

	strcpy(stgirl.name,"西施"); 
	stgirl.age=18; 
	stgirl.height=170;
	strcpy(stgirl.sc,"火辣"); 
	fwrite(&stgirl,1,sizeof(stgirl),fp);

	strcpy(stgirl.name,"貂蝉");
	stgirl.age=19;
	stgirl.height=165;
	strcpy(stgirl.sc,"火辣");
	fwrite(&stgirl,1,sizeof(stgirl),fp);
	
	fclose(fp);
	fp=0;
	printf("-----fwrite testbinary.dat end-----\n");
	
	printf("-----fgets testbinary.dat begin-----\n");

	struct st_girl st;
	
	FILE * fpread=0;
	if((fpread=fopen("testbinary.dat","a+"))==0)
	{
		printf("fopen failed!");
	}

	while(1)
	{
		if(fread(&st,1,sizeof(st),fpread)==0)
		{
			printf("fread end");
			break;
		}
		printf("name=%s,age=%d,height=%d,sc=%s\n",\
				          st.name,st.age,st.height,st.sc);
	}

}

void test_fpposition()
{
	FILE * fp=fopen("test_fpposition.c","w+");
	if(fp==0)
	{
		printf("fopen failed!");
	}

	fprintf(fp,"0123456789");
	fprintf(fp,"\n123456789");

	fclose(fp);

	FILE * fp1=fopen("test_fpposition.c","w+");
	if(fp==0)
	{
		printf("fopen2 failed!");
	}
	
	printf("无论什么打开方式，位置指针都指向0位置\n");
	printf("position=%ld\n",ftell(fp1));
	rewind(fp1);
	printf("after rewind, position=%ld\n",ftell(fp1));

	fseek(fp1,5,0);//从文件开头向后移5个字节
	printf("after fseek(fp1,5,0),position=%ld\n",ftell(fp1));

	fclose(fp1);
}

void test_filework()
{
	struct st_girl stgirl[3];
	memset(stgirl,0,sizeof(stgirl));

	strcpy1(stgirl[0].name,"ha");
	stgirl[0].age=18;
	stgirl[0].height=165;
	stgirl[0].weight=100;
	strcpy1(stgirl[0].sc,"best");

	strcpy1(stgirl[1].name,"hah");
	stgirl[1].age=19;
	stgirl[1].height=166;
	stgirl[1].weight=110;
	strcpy1(stgirl[1].sc,"best");
	
	strcpy1(stgirl[2].name,"haha");
	stgirl[2].age=20;
	stgirl[2].height=167;
	stgirl[2].weight=120;
	strcpy1(stgirl[2].sc,"best");

	printf("----fwrite----\n");
	FILE * fpWrite=fopen("test_file_work.dat","w+");
	if(fpWrite==0)
	{
		printf("fwrite fopen failed!\n");
	}
	
	//for(int i=0;i<3;i++)
	//{
	//	fwrite(&stgirl[i],1,sizeof(struct st_girl),fpWrite);
	//}
	fwrite(stgirl,1,sizeof(stgirl),fpWrite);

	fclose(fpWrite);
	
	printf("-----fread----\n");
	FILE * fpRead=fopen("test_file_work.dat","r");
	if(fpRead==0)
	{
		printf("read fopen failed\n");
	}

	//struct st_girl readst;
	//for(int i=0;i<3;i++)
	//{
	//	size_t amount=fread(&readst,1,sizeof(struct st_girl),fpRead);
	//	if(amount==0)
	//		break;
	//	printf("name=%s,age=%d,height=%d,sc=%s",\
				          readst.name,readst.age,readst.height,readst.sc);
	//}
	struct st_girl readArr[3];
	size_t amount1=fread(readArr,1,sizeof(readArr),fpRead);
	for(int i=0;i<3;i++)
	{
		 printf("name=%s,age=%d,height=%d,sc=%s\n",\
				                           readArr[i].name,readArr[i].age,readArr[i].height,readArr[i].sc);
	}
	
	fclose(fpRead);
//------------------------------------------------------------------------------------------------------
	printf("-----开始文本信息录入-----\n");
	struct st_girl stArr[2];
	memset(stArr,0,sizeof(stArr));

	for(int i=0;i<2;i++)
	{
		printf("请输入 姓名 年龄 身高 体重 身材：");
		scanf("%s %d %d %lf %s",stArr[i].name,&stArr[i].age,&stArr[i].height,&stArr[i].weight,stArr[i].sc);
	}
	
	char str[301];
	memset(str,0,sizeof(str));
	FILE * fprintfP=fopen("test_wenben.c","w");
	for(int i=0;i<2;i++)
	{
		fprintf(fprintfP,"<name>%s</name><age>%d</age><height>%d</height><weight>%lf</weight><sc>%s</sc>\n",\
			   	stArr[i].name,stArr[i].age,stArr[i].height,stArr[i].weight,stArr[i].sc);
	}
	fclose(fprintfP);
	printf("-----文本保存成功 -----\n");
	
	printf("-----read data begin-----\n");
	memset(stArr,0,sizeof(stArr));
	printf("<name>%s<age>%d<height>%d<weight>%lf<sc>%s\n",\
			                                stArr[0].name,stArr[0].age,stArr[0].height,stArr[0].weight,stArr[0].sc);

	char strTemp[301];
	memset(strTemp,0,301);
	
	FILE * fgetsP=fopen("test_wenben.c","r");
	for(int i=0;i<2;i++)
	{
		fgets(strTemp,301,fgetsP);
		//printf("%s",strTemp);
		GetXMLBuffer_Str(strTemp,"name",stArr[i].name);
		GetXMLBuffer_Int(strTemp,"age",&stArr[i].age);
	 	GetXMLBuffer_Int(strTemp,"height",&stArr[i].height);
	  	GetXMLBuffer_Double(strTemp,"weight",&stArr[i].weight);
	   	GetXMLBuffer_Str(strTemp,"sc",stArr[i].sc);
		
		printf("<name>%s<age>%d<height>%d<weight>%lf<sc>%s\n",\
				                stArr[i].name,stArr[i].age,stArr[i].height,stArr[i].weight,stArr[i].sc);
	}
	fclose(fgetsP);
}

void test_directory()
{
	char * strpwd=malloc(301);
	memset(strpwd,0,sizeof(strpwd));
	printf("strpwd=%p\n",strpwd);
	printf("res=%p\n",getcwd(strpwd,300));
	printf("当前目录是：%s\n",strpwd);
	free(strpwd);

	//printf("-----chdir-----\n");
	//char * strpwd1=malloc(301);
	//memset(strpwd1,0,sizeof(strpwd1));
	//chdir("aaa");
	//getcwd(strpwd1,300);
	//printf("当前目录是：%s\n",strpwd1);
	//free(strpwd1);
	
	printf("-----mkdir-----\n");
	printf("res=%d\n",mkdir("aaa/ddd",0755));

	printf("-----rmdir-----\n");
	printf("res=%d\n",rmdir("bbb"));

	printf("-----opendir-----\n");
	DIR* opendirD=opendir("bbb");
	struct dirent * dirinfo;
	while(1)
	{
		dirinfo=readdir(opendirD);
		if(dirinfo==0)
			break;
		printf("name:%s type:%d\n",dirinfo->d_name,dirinfo->d_type);
	}
	closedir(opendirD);
}

void test_time()
{
	time_t tnow;
	printf("time(&tnow)=%ld\n",time(&tnow));
	printf("time(0)=%ld\n",time(0));

	struct tm * tmi=localtime(&tnow);

	printf("%d-%d-%d 星期%d %d时 %d分 %d秒 第%d天\n",\
				tmi->tm_year+1900,tmi->tm_mon,tmi->tm_mday,tmi->tm_wday,tmi->tm_hour,tmi->tm_min,tmi->tm_sec,tmi->tm_yday);

	time_t tsec=mktime(tmi);
	printf("tsec=%ld\n",tsec);

	//1s=1000000us.
	struct timeval tv1;
	struct timezone tz1;
	gettimeofday(&tv1,&tz1);//第二个参数一般都为空，我们一般都只是为了获得当前时间，不关心时区的信息。

	printf("tv1.tv_sec=%ld tv1.tv_usec=%ld \n",tv1.tv_sec,tv1.tv_usec);
	printf("tz1.tz_minuteswest=%d tz1.tz_dsttime=%d \n",tz1.tz_minuteswest,tz1.tz_dsttime);
	

	printf("-----test_timetostr()-----\n");
	char  strtime[100];
	memset(strtime,0,100);
	printf("timetostr res=%d\n",timetostr(time(0),strtime));
	printf("timetostr(%ld,)=%s\n",tnow,strtime);

	printf("-----strtotime-----\n");
	strtotime(strtime,&tnow);
	printf("%ld\n",tnow);

	printf("-----errno-----\n");
	//FILE * fp=fopen("aaa","r");
	//if(fp==0)
	//{
	//	printf("%d %s\n",errno,strerror(errno));
	//	perror("perror res:");
	//	printf("fopen failed!\n");
		//return ;
	//}
	//fclose(fp);

	printf("----file-----\n");
	if(access("aaa1",F_OK)==0)
		printf("exist\n");

	printf("-----stat-----\n");
	char statstr[20];
	struct stat statTemp;
	if(stat("aaa1",&statTemp)==0)
	{
		timetostr(statTemp.st_mtime,statstr);
		printf("statTemp.st_mtime=%s st_size=%ld\n",statstr,statTemp.st_size);

	}

	printf("-----utim-----");
	struct utimbuf utimTemp;
	utimTemp.actime=time(0);
	utimTemp.modtime=time(0);
	if(utime("aaa1",&utimTemp)==0)
	{
		printf("modify aaa1 time success!\n");
	}
	
	printf("-----rename-----\n");
	if(rename("aaa1","aaa11")==0)
	{
		printf("rename aaa1 to aaa11 success!\n");
	}

	printf("-----remove-----\n");
	if(remove("aaa11")==0)
	{
		printf("rm aaa11 success!\n");
	}
	else
		printf("rm aaa11 failed\n");
	
	if(remove("bbb")==0)
		printf("rm bbb success!\n");
}

void test_Customize_mkdir()
{
	printf("res=%d\n",Customize_mkdir("temp/aaa/bbb"));
}
