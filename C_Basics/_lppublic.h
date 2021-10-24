#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <utime.h>

int ctoi(char c);

int POW(const unsigned int x,unsigned const int y);

int stringConvertNumSUM(char * str,int len);

int ATOI(const char * nptr);

double c_atof(const char * nptr);//convert string to double 

size_t  strlen1( const char*  str);//Calculate the effective length of the string,excluding 0.

char *strcpy1(char* dest, const char* src);//copy src value to dest address and append 0

char * strncpy1(char* dest,const char* src, const size_t n);

char *strcat1(char* dest,const char* src);

char *strncat1(char* dest,const char* src, const size_t n);

int strcmp1(const char *str1, const char *str2 );

int strncmp1(const char *str1,const char *str2 ,const size_t n);

char *strchr1(const char *s,const int c);

char *strrchr1(const char *s,const int c);

char *strstr1(const char* str,const char* substr);

int GetXMLBuffer_Str(const char *in_XMLBuffer,const char *in_FieldName,char *out_Value);

int GetXMLBuffer_Int(const char *in_XMLBuffer,const char *in_FieldName,int *out_Value);

int GetXMLBuffer_Double(const char *in_XMLBuffer,const char *in_FieldName,double *out_Value);

int timetostr(const time_t ti,char *strtime);//把整数的时间转换为字符串格式的时间

int strtotime(const char *strtime,time_t *ti);//把字符串格式的时间转换为整数的时间

int Customize_mkdir(const char *path );
