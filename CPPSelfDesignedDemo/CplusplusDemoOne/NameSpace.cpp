#include <iostream>
//引用命名空间的方法一
using namespace std;
//引用命名空间中具体的方法：
using std::cout;
using std::cin;

//声明命名空间示例
namespace first {
	void func()
	{
		cout<<"first!" << endl;
	}
}
namespace two {
	void func()
	{
		cout << "Two!" << endl;
	}
}

//void main()
//{//调用指定命名空间成员方法一
//	first::func();
//	two::func();
//}

//调用指定命名空间成员方法二
using namespace first;
//void main()
//{
//	func();
//}

void mainns()
{
	std::cout << "test namespace!" << std::endl;
}