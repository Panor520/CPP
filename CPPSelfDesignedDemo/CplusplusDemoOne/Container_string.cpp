#include <iostream>
#include <string>
using namespace std;

#pragma region string Container
//string��c++�����ַ�������string��������һ����
//char *��һ��ָ��
//string��һ���࣬�ڲ���װ��char*����������ַ�������һ��char*������

//string�Ĺ��캯��
//string();						����һ���յ��ַ���
//string(const char* s);		ʹ���ַ���s��ʼ��
//string(const string &str);	ʹ��һ��string�����ʼ����һ������
//string(int n,char c);			ʹ��n���ַ�c��ʼ��
//��ʼ������
void string_test01()
{
	const char* chArr = "casd";//charָ������ᱻ��ʼ�������ַ����������飬�����ڳ����������ɸ��ģ����Ա�����const
	cout << chArr << endl;

	string s1;
	const char* ch = "abcd";
	string s2(ch);
	cout << s2 << endl;

	string s3(s2);
	cout << s3 << endl;

	string s4(10,'n');
	cout << s4 << endl;
}

//��ֵ����
//string& operator=(const char * s);
//string& operator=(const string &s);
//string& operator=(char c);
//string& assign(const char * s);
//string& assign(const char * s,int n);			��ǰn���ַ�������ǰ�ַ���
//string& assign(const string &s);
//string& assign(int n,char c)
void string_test02()
{
	string s1;
	s1 = "hahaah";
	cout << s1 << endl;

	string s2 = s1;
	cout << s2 << endl;

	string s3;
	s3 = 'c';
	cout << s3 << endl;

	string s4;
	s4.assign("hello");
	cout << s4 << endl;

	string s5;
	s5.assign("hello",3);
	cout << s5<< endl;

	string s6;
	s6.assign(s4);
	cout << s6 << endl;

	string s7;
	s7.assign(5,'c');
	cout << s7 << endl;
}

//�ַ���ƴ�Ӳ���
//string& operator+=(const char * str);
//string& operator+=(const string &str);
//string& operator+=(const char c);
//string& append(const char * s);
//string& append(const char * s,int n);			��ǰn���ַ����ӵ���ǰ�ַ���
//string& append(const string &s);
//string& append(const string &s, int pos,int n); �ַ���s�д�pos��ʼ��n���ַ����ӵ��ַ�����β
void string_test03()
{
	string str = "��";
	str += "������Ϸ��";
	cout << str << endl;

	string str1 = "������";
	str1 += str;
	cout << str1 << endl;

	char ch = ',1';
	str1 += ch;
	cout << str1 << endl;

	string strr = "��";
	strr.append("�ڱ�����");
	cout << strr << endl;

	strr.append("hah",2);
	cout << strr << endl;

	string strr1 = ",�������";
	strr.append(strr1);
	cout << strr << endl;

	string strr2 = "xxx,xixi";
	strr.append(strr2,2, strr2.length());
	cout << strr << endl;
}

//�ַ����Ĳ���
void string_Find()
{
	string str = "abcde";
	int pos = str.find("a");//��0��ʼ����
	int pos1 = str.find("df");//�����ڷ���-1
	cout << pos << endl;
	cout << pos1 << endl;

	//rfind ���������  find �Ǵ����� 
	int poss = str.rfind("a");//��0��ʼ����
	int poss1 = str.rfind("df");//�����ڷ���-1
	cout << poss << endl;
	cout << poss1 << endl;
}

//�ַ������滻
void string_Replace()
{
	string str = "abcdef";
	str.replace(1,3,"11111");//���ĸ��֣�1������ ������3���ַ� �滻���ĸ����������������ַ��� 
	cout << str << endl;
}

//�ַ����Ƚ�
void string_Compare()
{
	string str1 = "abc";
	string str2 = "abd";
	bool flag = str1.compare(str2);//����ַ��Ƚ�ASCII�� ������ֵ��bool��ֻ�� 0��1֮���ˣ���Ϊboolֻ����0��1,��0����1
	cout << flag << endl;
	cout << str1.compare(str2) << endl;//����ַ��Ƚ�ASCII�� ��str1�Ƚ�str2��str1�����1��������0��str2�����-1
}

//�ַ�����ȡ
void string_cunqu()
{
	string str1 = "abc";
	
	//ͨ��[]����ÿ���ַ�
	for (int  i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << endl;
	}

	//ͨ��at���ʵ����ַ�

	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << endl;
	}
	//�޸��ַ�
	str1[1] = 'x';
	cout << str1<< endl;
	str1.at(2) = 'd';
	cout << str1 << endl;
}

//�ַ����Ĳ����ɾ��
void string_insertORdelete()
{
	string str = "abcde";
	str.insert(1,"111");
	cout << str << endl;
	string str1 = "222";
	str.insert(0,str1);
	cout << str << endl;

	str.insert(0,2,'x');//�ڵ�0��λ�ã���������x
	cout << str << endl;
	//ɾ��
	str.erase(0,2);
	cout << str << endl;
}

//�ַ�����ȡ
void string_getstring()
{
	string str = "abcdef";
	string str1= str.substr(1, 2);//�ӵ�1���ַ���ʼ����ȡ�����ַ�,str��������
	cout << str1 << endl;

	string str2 = "abcd@enc.com";
	int pos = str2.find("@");
	string str3 = str2.substr(0, pos);
	cout << str3 << endl;
}
#pragma endregion

void main_ContainString()
{
	//string_test01();
	//string_test02();
	//string_test03();

	//string_Find();
	//string_Replace();

	//string_Compare();
	//string_cunqu();
	//string_insertORdelete();
	string_getstring();
}