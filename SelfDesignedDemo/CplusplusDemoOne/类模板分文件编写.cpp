//类模板分文件编写

//#include "ClassTemplateSplitDemo.h"//包含这个头文件，去编译时会报错，是因为类模板函数创建时机是在调用时，编译时并不会连接上可以采用下面方法别面这个错误
//#include "ClassTemplateSplitDemo.cpp"//第一种解决方法：包含了编译时所有需要的信息，可以编译成功

//第二种解决办法(常用)：将.h和.cpp中的内容写到一起，将后缀名改为.hpp文件（约定俗成）
#include "ClassTemplateSplitDemo.hpp"

void ClassTemplateTest01()
{
	ClassTemplateTestPer<string, int> ct("asfas",18);
	ct.showPerson();
}

void main_ClassTemplateTest01()
{
	ClassTemplateTest01();
}