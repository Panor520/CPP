#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/// <summary>
/// 写
/// 第二次执行会覆盖掉原来的文件，并重新写入文件
/// </summary>
void fstream_Write()
{
	//create object
	ofstream of;

	//指定打开方式
	of.open("test.txt",ios::out);
	//写内容
	of << "111"<<endl;
	//关闭文件
	of.close();
}

void ifstream_Read()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
		return;
	}
	////第一种读取方式
	//char buf[1024] = { 0 };
	//while (ifs>>buf)
	//{
	//	cout << buf << endl;
	//}
	////第二种读取方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}
	////第三种读取方式
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}
	//第四种读取方式
	char c;
	while ((c=ifs.get())!=EOF) //eof END OF FILE
	{
		cout << c;
	}
	ifs.close();
}
void main_文本文件()
{
	//fstream_Write();
	ifstream_Read();

}