#include <iostream>
#include <string>
using namespace std;

//有纯虚析构函数的类也是抽象类，无法实例化对象
//只有在基类中定义了虚析构函数，子类中的析构函数才会被调用
class chunxugou_Animal
{
public:
	chunxugou_Animal()
	{
		cout << "基类构造函数" << endl;
	}
	//利用虚析构函数解决父类指针释放对象时不干净的问题
	/*virtual~chunxugou_Animal()
	{
		cout << "基类析构函数" << endl;
	} */
	virtual~chunxugou_Animal() = 0;//纯虚析构必须有实现，因为基类中也需要释放堆上开辟的空间
	virtual void speak() = 0;
};
chunxugou_Animal::~chunxugou_Animal()
{
	cout << "基类纯虚析构函数" << endl;
}
class chunxugou_Cat:public chunxugou_Animal
{
public:
	chunxugou_Cat(string name)
	{
		cout << "cat 构造" << endl;
		m_Name = new string(name);
	}
	~chunxugou_Cat()
	{
		cout << "cat 析构" << endl;
		if (m_Name!=NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
	}
	virtual void speak()
	{
		cout << *m_Name <<" speak" << endl;
	}
	string * m_Name;
};

void chunxugou_test01()
{
	chunxugou_Animal * a = new chunxugou_Cat("Tom");
	a->speak();
	delete a;//父类指针在析构时不会调用子类的析构函数，若子类中有堆区的属性，会出现内存泄漏
}

void main_chunxuhanshu()
{
	chunxugou_test01();
}