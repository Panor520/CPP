#include "Boss.h"

Boss::Boss(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

string Boss::getDeptName()
{
	return "Boss";
}

void Boss::showInfo()
{
	cout << "��ţ�" << m_Id
		<< "\t������" << m_Name
		<< "\t��λ��" << getDeptName()
		<< "\t��λְ��:����˾��������" << endl;
}