#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Binary_person
{
public:
	int age;
	char name[64];
};
/// <summary>
/// д
/// </summary>
void Binary_Write()
{
	ofstream of;
	//��
	of.open("person.txt",ios::out|ios::binary);//�м��ǵ�б�ܣ�˫б�ܲ�����Ҳ������������ǵò�����ȷ�Ľ��
	//д
	Binary_person p = {18,"tom"};
	of.write((const  char* )&p,sizeof(p));//�׸�����ʱConst char * ���͵ģ�����ǿת�£���������õ��ľ���Ҫд�������

	of.close();
}

/// <summary>
/// ��
/// </summary>
void Binary_Read()
{
	ifstream ifs;
	//��
	ifs.open("person.txt", ios::in | ios::binary);//�м��ǵ�б�ܣ�˫б�ܲ�����Ҳ������������ǵò�����ȷ�Ľ��
	//��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Binary_person p;
	ifs.read((char*)&p,sizeof(Binary_person));//�������ŵ�p��
	cout << p.age<<" " << p.name << endl;
}
void main_Binary()
{
	//Binary_Write();
	Binary_Read();
}