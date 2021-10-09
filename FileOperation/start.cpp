#include "file.h"

int main()
{
    MKDIR("tmp/aaa/bbb/ccc/ddd", false); // 创建"/tmp/aaa/bbb/ccc/ddd"目录。

    MKDIR("tmp/111/222/333/444/data.xml", true); // 创建"/tmp/111/222/333/444"目录。
}