#include <iostream>//cin cout
#include <ctime>
#include <cstring>

using namespace std;
//C++大小写敏感
//流插入运算符 <<   箭头方向代表数据流入方向
//流提取运算符 >>

void PrintBook(struct Books book);
void PrintBookPointer(struct Books *book);

struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};




int main1()
{
	int a, b;
	int& i = a;
	int& j = b;
	//Attention!
	int& c = a, & d = b;

	a = 1;
	b = 4;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;

	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	// 把 now 转换为字符串形式
	char* dt = ctime(&now);
	cout << "本地日期和时间：" << dt << endl;
	
	// 把 now 转换为 tm 结构
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC 日期和时间：" << dt << endl;

	time_t now1 = time(0);
	cout << "1970 到目前经过秒数" << now1 << endl;
	tm* ltm = localtime(&now1);

	cout << "年："<<ltm->tm_year <<endl;
	cout << "月：" << ltm->tm_mon << endl;
	cout << "日：" << ltm->tm_mday << endl;

	char name[50];
	cout << "请输入名字：" << endl;
	cin >> name;
	cout << "你的名字是：" << name << endl;
	
	//Struct
	Books Book1;
	strcpy(Book1.author," C++");
	strcpy(Book1.subject, " structure");
	strcpy(Book1.title, " C++");
	Book1.book_id = 1;
	cout << "书的信息如下："<<Book1.book_id<< Book1.author <<Book1.subject <<Book1.title <<endl;
	PrintBook(Book1);
	PrintBookPointer(&Book1);//注意参数转换
	//



	return 0;
}

void PrintBook(struct Books book)
{//正常结构体参数，访问成员用.
	cout << "书的信息如下：" << book.book_id << book.author << book.subject << book.title << endl;
}

void PrintBookPointer(struct Books *book)
{//指针结构体参数，访问成员用->
	cout << "书的信息如下：" << book->book_id << book->author << book->subject << book->title << endl;
}