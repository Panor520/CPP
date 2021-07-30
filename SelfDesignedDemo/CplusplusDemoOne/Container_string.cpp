#include <iostream>
#include <string>
using namespace std;

#pragma region string Container
//string是c++风格的字符串，而string本质上是一个类
//char *是一个指针
//string是一个类，内部封装了char*，管理这个字符串，是一个char*的容器

//string的构造函数
//string();						创建一个空的字符串
//string(const char* s);		使用字符串s初始化
//string(const string &str);	使用一个string对象初始化另一个对象
//string(int n,char c);			使用n个字符c初始化
//初始化操作
void string_test01()
{
	const char* chArr = "casd";//char指针数组会被初始化成了字符串常量数组，常量在常量区，不可更改，所以必须用const
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

//赋值操作
//string& operator=(const char * s);
//string& operator=(const string &s);
//string& operator=(char c);
//string& assign(const char * s);
//string& assign(const char * s,int n);			把前n个字符赋给当前字符串
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

//字符串拼接操作
//string& operator+=(const char * str);
//string& operator+=(const string &str);
//string& operator+=(const char c);
//string& append(const char * s);
//string& append(const char * s,int n);			把前n个字符连接到当前字符串
//string& append(const string &s);
//string& append(const string &s, int pos,int n); 字符串s中从pos开始的n个字符连接到字符串结尾
void string_test03()
{
	string str = "我";
	str += "爱玩游戏！";
	cout << str << endl;

	string str1 = "哈哈，";
	str1 += str;
	cout << str1 << endl;

	char ch = ',1';
	str1 += ch;
	cout << str1 << endl;

	string strr = "我";
	strr.append("在北京！");
	cout << strr << endl;

	strr.append("hah",2);
	cout << strr << endl;

	string strr1 = ",别过来啊";
	strr.append(strr1);
	cout << strr << endl;

	string strr2 = "xxx,xixi";
	strr.append(strr2,2, strr2.length());
	cout << strr << endl;
}

//字符串的查找
void string_Find()
{
	string str = "abcde";
	int pos = str.find("a");//从0开始索引
	int pos1 = str.find("df");//不存在返回-1
	cout << pos << endl;
	cout << pos1 << endl;

	//rfind 从右往左查  find 是从左到右 
	int poss = str.rfind("a");//从0开始索引
	int poss1 = str.rfind("df");//不存在返回-1
	cout << poss << endl;
	cout << poss1 << endl;
}

//字符串的替换
void string_Replace()
{
	string str = "abcdef";
	str.replace(1,3,"11111");//从哪个字（1）符起 几个（3）字符 替换成哪个（第三个参数）字符串 
	cout << str << endl;
}

//字符串比较
void string_Compare()
{
	string str1 = "abc";
	string str2 = "abd";
	bool flag = str1.compare(str2);//逐个字符比较ASCII码 ，但赋值给bool就只有 0和1之分了，因为bool只能是0或1,非0都是1
	cout << flag << endl;
	cout << str1.compare(str2) << endl;//逐个字符比较ASCII码 ，str1比较str2，str1大输出1，相等输出0，str2大输出-1
}

//字符串存取
void string_cunqu()
{
	string str1 = "abc";
	
	//通过[]访问每个字符
	for (int  i = 0; i < str1.size(); i++)
	{
		cout << str1[i] << endl;
	}

	//通过at访问单个字符

	for (int i = 0; i < str1.size(); i++)
	{
		cout << str1.at(i) << endl;
	}
	//修改字符
	str1[1] = 'x';
	cout << str1<< endl;
	str1.at(2) = 'd';
	cout << str1 << endl;
}

//字符串的插入和删除
void string_insertORdelete()
{
	string str = "abcde";
	str.insert(1,"111");
	cout << str << endl;
	string str1 = "222";
	str.insert(0,str1);
	cout << str << endl;

	str.insert(0,2,'x');//在第0个位置，插入两个x
	cout << str << endl;
	//删除
	str.erase(0,2);
	cout << str << endl;
}

//字符串获取
void string_getstring()
{
	string str = "abcdef";
	string str1= str.substr(1, 2);//从第1个字符开始，截取两个字符,str保持自身
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