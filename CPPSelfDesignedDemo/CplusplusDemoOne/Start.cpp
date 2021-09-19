#include <iostream>//cin cout
#include <ctime>
#include <cstring>

using namespace std;
//C++��Сд����
//����������� <<   ��ͷ��������������뷽��
//����ȡ����� >>

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

	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	time_t now = time(0);
	// �� now ת��Ϊ�ַ�����ʽ
	char* dt = ctime(&now);
	cout << "�������ں�ʱ�䣺" << dt << endl;
	
	// �� now ת��Ϊ tm �ṹ
	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC ���ں�ʱ�䣺" << dt << endl;

	time_t now1 = time(0);
	cout << "1970 ��Ŀǰ��������" << now1 << endl;
	tm* ltm = localtime(&now1);

	cout << "�꣺"<<ltm->tm_year <<endl;
	cout << "�£�" << ltm->tm_mon << endl;
	cout << "�գ�" << ltm->tm_mday << endl;

	char name[50];
	cout << "���������֣�" << endl;
	cin >> name;
	cout << "��������ǣ�" << name << endl;
	
	//Struct
	Books Book1;
	strcpy(Book1.author," C++");
	strcpy(Book1.subject, " structure");
	strcpy(Book1.title, " C++");
	Book1.book_id = 1;
	cout << "�����Ϣ���£�"<<Book1.book_id<< Book1.author <<Book1.subject <<Book1.title <<endl;
	PrintBook(Book1);
	PrintBookPointer(&Book1);//ע�����ת��
	//



	return 0;
}

void PrintBook(struct Books book)
{//�����ṹ����������ʳ�Ա��.
	cout << "�����Ϣ���£�" << book.book_id << book.author << book.subject << book.title << endl;
}

void PrintBookPointer(struct Books *book)
{//ָ��ṹ����������ʳ�Ա��->
	cout << "�����Ϣ���£�" << book->book_id << book->author << book->subject << book->title << endl;
}