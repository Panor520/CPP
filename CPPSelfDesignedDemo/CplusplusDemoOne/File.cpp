#include <iostream>
#include <fstream>
using namespace std;

void mainf()
{
	char data[100];
	ofstream outfile;
	outfile.open("afile.dat");//�����ڸ��ļ������Զ�����

	cout << "Writing to the file" << endl;
	cout << "Enter your name: ";
	cin.getline(data, 100);
	// ���ļ�д���û����������
	outfile << data << endl;
	cout << "Enter your age: ";
	cin >> data;
	//����Իس����������뻺���������ݣ�������һ���������һ�������Ӱ��
	cin.ignore();
	// �ٴ����ļ�д���û����������
	outfile << data << endl;
	// �رմ򿪵��ļ�
	outfile.close();

	ifstream infile;
	infile.open("afile.dat");
	cout << "Reading from the file" << endl;
	infile >> data;
	cout << data << endl;

	// �ٴδ��ļ���ȡ���ݣ�����ʾ��
	infile >> data;
	cout << data << endl;

	infile.close();

}