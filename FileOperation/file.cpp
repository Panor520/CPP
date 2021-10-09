#include "file.h"  

// 根据绝对路径的文件名或目录名逐级的创建目录。
// pathorfilename：绝对路径的文件名或目录名。
// bisfilename：说明pathorfilename的类型，true-pathorfilename是文件名，否则是目录名，缺省值为true。
// 返回值：true-创建成功，false-创建失败，如果返回失败，原因有大概有三种情况：1）权限不足； 2）pathorfilename参数不是合法的文件名或目录名；3）磁盘空间不足。
bool MKDIR(const char *filename,bool bisfilename)
{
  // 检查目录是否存在，如果不存在，逐级创建子目录
  char strPathName[301];

  int ilen=strlen(filename);//strlen所作的仅仅是一个计数器的工作，它从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，直到碰到第一个字符串结束符'\0'为止，然后返回计数器值。

  for (int ii=1; ii<ilen;ii++)//这部分只创建文件夹
  {
    if (filename[ii] != '/') continue;

    memset(strPathName,0,sizeof(strPathName));//memset是逐字节拷贝
    strncpy(strPathName,filename,ii);

    if (access(strPathName,F_OK) == 0) continue;//access有权限返回0；在这里指的是是否有这个文件夹，有的话就不用走下面的创建，直接开始进行下一个文件夹名字

    if (mkdir(strPathName,0755) != 0) return false;//mkdir目录创建成功返回0
  }

  if (bisfilename==false)//如果是文件名就创建
  {
    if (access(filename,F_OK) != 0)
    {
      if (mkdir(filename,0755) != 0) return false;
    }
  }

  return true;
}


int main()
{
    // MKDIR("tmp/aaa/bbb/ccc/ddd", false); // 创建"/tmp/aaa/bbb/ccc/ddd"目录。

    // MKDIR("tmp/111/data.xml", false); // 创建"/tmp/111/222/333/444"目录。

    char * str;
    printf("charpointer=%p\n",sizeof(str));
}