#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
// 根据绝对路径的文件名或目录名逐级的创建目录。
// pathorfilename：绝对路径的文件名或目录名。
// bisfilename：说明pathorfilename的类型，true-pathorfilename是文件名，否则是目录名，缺省值为true。
// 返回值：true-成功，false-失败，如果返回失败，原因有大概有三种情况：1）权限不足；2）pathorfilename参数不是合法的文件名或目录名；3）磁盘空间不足。
bool MKDIR(const char *pathorfilename,bool bisfilename=true);