#include <string>
#include <iostream>
using namespace std;

#pragma region ��ģ��ͺ���ģ������


//��ģ��ͺ���ģ������
//1.��ģ��û���Զ������Ƶ���ʹ�÷�ʽ,������ʾ����
//2.��ģ����ģ������б��п�����Ĭ�ϲ���
template <typename nameType =string,typename ageType = int>//ָ��Ĭ�����͵�ģ��
class ClAFuncDiffTemplate
{
public:
	ClAFuncDiffTemplate(nameType name,ageType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void ShowPerson()
	{
		cout << this->m_Name << " " << this->m_Age << endl;
	}
	nameType m_Name;
	ageType m_Age;
};

void test01_clandfuncDiff()
{
	//ClAFuncDiffTemplate cd("Person",18);//error �޷��Զ��Ƴ�ģ������
	ClAFuncDiffTemplate<> cd("Person", 18);//ģ����ָ����Ĭ�����ͣ�����ط������Ϳ��Բ�������ʹ��Ĭ�ϵ�
	cd.ShowPerson();
}

#pragma endregion

#pragma region ��ģ���г�Ա��������ʱ��
//��ģ���г�Ա��������ʱ����
//��ģ���г�Ա�����ڵ���ʱ��ȥ������Ҳ����ȷ����ģ�����ͺ��ٴ���

#pragma endregion



void main_Clasandfuncdiff()
{
	test01_clandfuncDiff();
}