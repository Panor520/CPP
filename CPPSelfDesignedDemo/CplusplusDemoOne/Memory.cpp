//�����ڲ����������б�������ռ��ջ�ڴ�
//���ǳ���δʹ�õ��ڴ棬�ڳ�������ʱ���ڶ�̬�����ڴ档
//ʹ������������Ϊ�������͵ı���������ʱ������ڵ��ڴ棬��᷵��������Ŀռ��ַ������������� new �������
//�����������Ҫ��̬������ڴ�ռ䣬����ʹ�� delete �������ɾ��֮ǰ�� new �����������ڴ档
//new �� malloc() ������ȣ�����Ҫ���ŵ��ǣ�new ��ֻ�Ƿ������ڴ棬���������˶���
#include <iostream>
using namespace std;

class Box
{
public:
	Box() { cout << "���ǹ��캯����" << endl; }
	~Box() { cout<<"������������" << endl; }
};

void memory()
{
	double* pvalue = NULL;//��ʼ��ΪNULLָ��
	pvalue = new double;//Ϊ���������ڴ棨�����ַ��
	*pvalue = 1.23;
	cout << "pvalue=" << *pvalue << endl;
	delete pvalue;//�ͷ��ڴ�

	char* pvalue1 = NULL;
	pvalue1 = new char[20];
	strcpy(pvalue1, "haha");
	cout << pvalue1 << endl;
	delete[] pvalue1;


	int m = 10;
	// ��̬����,���鳤��Ϊ m;
	int* array = new int[m];//��������ʱ����ָ�����鳤��

	//�ͷ��ڴ�
	delete[] array;

	//����Ķ�̬�ڴ�������������һ����ûʲô��ͬ
	Box* box = new Box[2];//����Box���󣬹������͹��캯���ֱ𱻵�������
	delete[]box;
}

int* newGrammar()
{
	//new �ڶ����������ݣ������ظ����͵�ָ��,��Ҫ�Լ��ͷ�
	int* p = new int(10);
	return p;
}

void newArray()
{
	int* p = new int[10];
	for (int i = 0; i < 10; i++)
	{
		*(p + i) = 100 + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout<<*(p+i) <<endl;
	}
	//�ͷ������[]
	delete[] p;
}

int* testStack()
{
	int p = 10;
	return &p;
}

void testRelease()
{
	int* a = testStack();
	cout << *a << endl;//��һ�α������ᱣ����ַ
	cout << *a << endl;//����ľͻ��Զ��ͷŵ�ջ��������
	cout << *a << endl;
	cout << *a << endl;

	int * p= newGrammar();
	cout << *p <<endl ;
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//�ͷŶ�������ʹ��delete
	delete p;
	//cout << *p << endl;//�����ͷ��꣬����ط��ͻᱨ��
}


void mainme()
{
	//memory();
	//testRelease();
	newArray();
}
