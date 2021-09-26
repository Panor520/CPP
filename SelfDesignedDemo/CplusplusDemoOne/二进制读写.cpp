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
/// 写
/// </summary>
void Binary_Write()
{
	ofstream of;
	//打开
	of.open("person.txt",ios::out|ios::binary);//中间是单斜杠，双斜杠不报错也不会有问题就是得不到正确的结果
	//写
	Binary_person p = {18,"tom"};
	of.write((const  char* )&p,sizeof(p));//首个参数时Const char * 类型的，必须强转下，这个参数得到的就是要写入的数据

	of.close();
}

/// <summary>
/// 读
/// </summary>
void Binary_Read()
{
	ifstream ifs;
	//打开
	ifs.open("person.txt", ios::in | ios::binary);//中间是单斜杠，双斜杠不报错也不会有问题就是得不到正确的结果
	//读
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Binary_person p;
	ifs.read((char*)&p,sizeof(Binary_person));//读出来放到p里
	cout << p.age<<" " << p.name << endl;
}
void main_Binary()
{
	//Binary_Write();
	Binary_Read();
}