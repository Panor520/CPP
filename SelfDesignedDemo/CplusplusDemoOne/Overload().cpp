#include <string>
#include <iostream>
using namespace std;


class KuohaoPerson
{
public :
	void operator()(string text)
	{
		cout << text << endl;
	}
	int operator()(int a,int b)
	{
		return a + b;
	}
};

//��Ա���������أ�������ֻ�ڸ���Ķ�����
class KuohaoPerson1
{
};

void main_oVERLOAD()
{
	KuohaoPerson ko;
	ko("xxx");//�������ƺ����ĵ��õ����ؾ��Ƿº�����

	cout<< KuohaoPerson()(1, 2)<<endl;//KuohaoPerson()���Ǵ�����������
	/*KuohaoPerson1 ko1;
	ko1("xaws ");*/
}