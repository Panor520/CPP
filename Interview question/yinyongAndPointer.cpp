#include <stdio.h>

int yinyongfunc(short & x)
{
    printf("parameter address=%x\n",&x);
}

int main()
{
    short x=10;
    int sizeofx=sizeof(x);
    printf("x size=%d \n",sizeofx);
    yinyongfunc(x);

    short * pointerX=&x;
    int sizeofpointerx=sizeof(pointerX);
    printf("pointerX size=%d\n",sizeofpointerx);

    int sizeyinyongX=sizeof(&x);//实际是地址大小
    printf("yinyong size=%d\n",sizeyinyongX);

    short & yinyongXX=x;
    int sizeofyinyongXX=sizeof(yinyongXX);
    printf("yinyongXX size=%d\n",sizeofyinyongXX);

    yinyongXX=111;
    printf("yinyongXX=%d,x=%d\n",yinyongXX,x);

    yinyongfunc(yinyongXX);
    return 0;
}

