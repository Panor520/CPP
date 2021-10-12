#include <stdio.h>
#include <string.h>

int main()
{

	char str[10]="12345";
	
	printf("str len=%ld\n",sizeof(str));

	printf("str=%p\n",str);
	printf("&str=%p\n",&str);

	char str1[11]="123\0 567";
	printf("str1=%s\n",str1);
	printf("str1 len=%ld\n",strlen(str1));

	char str2[13]="1234567";
	str2[5]=0;
	printf("str2=%s\n",str2);
	printf("str2 len=%ld\n",strlen(str2));
	
	char str3[3]="12\0";
	printf("str3=%s\n",str3);
	printf("str3[1]=%c\n",*(str3+1));
	printf("str3 len=%ld\n",strlen(str3));
	printf("str3 sizeof=%ld\n",sizeof(str3));

	char str4='h';
	char * cp=&str4;
	printf("str4 pointer=%p\n",cp);
	printf("str4 pointer+1=%p\n",cp+1);
	printf("str4 pointer sizeof=%ld\n",sizeof(cp));
	return 0;
}
