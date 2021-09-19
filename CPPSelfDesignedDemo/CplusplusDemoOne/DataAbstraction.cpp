#include <iostream>
using namespace std;

//数据抽象是指，只向外界提供关键信息，并隐藏其后台的实现细节，即只表现必要的信息而不呈现细节。
//如;不需要理解 cout 是如何在用户的屏幕上显示文本。您只需要知道公共接口即可，cout 的底层实现可以自由改变。

//抽象把代码分离为接口和实现。所以在设计组件时，必须保持接口独立于实现，这样，如果改变底层实现，接口也将保持不变。
//在这种情况下，不管任何程序使用接口，接口都不会受到影响，只需要将最新的实现重新编译即可。
//如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。
// 
//数据封装是一种把数据和操作数据的函数捆绑在一起的机制
//数据封装引申出了另一个重要的 OOP 概念，即数据隐藏
//把一个类定义为另一个类的友元类，会暴露实现细节，从而降低了封装性。
class adder
{
private:
	int total;
public: adder(int a = 0)
		{
			total =a;
		}
	  void addNum(int number)
	  {
		  total += number;
	  }
	  int Gettotal()
	  {
		  return total;
	  }
};



int maindb()
{
	adder a;
	a.addNum(1);
	a.addNum(2);
	a.addNum(3);
	cout << "Total="<<a.Gettotal() << endl;
	return 0;
}