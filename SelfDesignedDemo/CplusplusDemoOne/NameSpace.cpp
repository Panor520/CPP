#include <iostream>
//���������ռ�ķ���һ
using namespace std;
//���������ռ��о���ķ�����
using std::cout;
using std::cin;

//���������ռ�ʾ��
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
//{//����ָ�������ռ��Ա����һ
//	first::func();
//	two::func();
//}

//����ָ�������ռ��Ա������
using namespace first;
//void main()
//{
//	func();
//}

void mainns()
{
	std::cout << "test namespace!" << std::endl;
}