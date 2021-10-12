#include "_lppublic.h"

int ctoi(const char c)
{
	int res;
	switch (c)
		case '0':
		    res=0;	 	break;
		case '1':
			res=1;		break;
		case '2':
			res=2;		break;
		case '3':
			res=3;		break;
		default:
			res=-1;		break;

	return res;
}
