#include <iostream>
#include <fstream>
using namespace std;

void mainf()
{
	char data[100];
	ofstream outfile;
	outfile.open("afile.dat");//不存在该文件，会自动创建

	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline(data, 100);
	// 向文件写入用户输入的数据
	outfile << data << endl;
	cout << "Enter your age: ";
	cin >> data;
	//清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响
	cin.ignore();
	// 再次向文件写入用户输入的数据
	outfile << data << endl;
	// 关闭打开的文件
	outfile.close();

	ifstream infile;
	infile.open("afile.dat");
	cout << "Reading from the file" << endl;
	infile >> data;
	cout << data << endl;

	// 再次从文件读取数据，并显示它
	infile >> data;
	cout << data << endl;

	infile.close();

}