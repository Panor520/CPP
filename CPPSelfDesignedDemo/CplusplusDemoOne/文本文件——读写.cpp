#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// д
/// �ڶ���ִ�лḲ�ǵ�ԭ�����ļ���������д���ļ�
/// </summary>
void fstream_Write()
{
	//create object
	ofstream of;

	//ָ���򿪷�ʽ
	of.open("test.txt",ios::out);
	//д����
	of << "111"<<endl;
	//�ر��ļ�
	of.close();
}

void ifstream_Read()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʧ��" << endl;
		return;
	}
	////��һ�ֶ�ȡ��ʽ
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}
	////�ڶ��ֶ�ȡ��ʽ
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	////�����ֶ�ȡ��ʽ
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}
	//�����ֶ�ȡ��ʽ
	char c;
	while ((c=ifs.get())!=EOF) //eof END OF FILE
	{
		cout << c;
	}
	ifs.close();
}
void main_�ı��ļ�()
{
	//fstream_Write();
	ifstream_Read();

}