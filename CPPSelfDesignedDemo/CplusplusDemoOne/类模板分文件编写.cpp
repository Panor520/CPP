//��ģ����ļ���д

//#include "ClassTemplateSplitDemo.h"//�������ͷ�ļ���ȥ����ʱ�ᱨ������Ϊ��ģ�庯������ʱ�����ڵ���ʱ������ʱ�����������Ͽ��Բ������淽�������������
//#include "ClassTemplateSplitDemo.cpp"//��һ�ֽ�������������˱���ʱ������Ҫ����Ϣ�����Ա���ɹ�

//�ڶ��ֽ���취(����)����.h��.cpp�е�����д��һ�𣬽���׺����Ϊ.hpp�ļ���Լ���׳ɣ�
#include "ClassTemplateSplitDemo.hpp"

void ClassTemplateTest01()
{
	ClassTemplateTestPer<string, int> ct("asfas",18);
	ct.showPerson();
}

void main_ClassTemplateTest01()
{
	ClassTemplateTest01();
}