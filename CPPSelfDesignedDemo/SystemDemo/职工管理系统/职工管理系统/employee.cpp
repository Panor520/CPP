#include "employee.h"
Employee::Employee(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "��ţ�" << m_Id
		<< "\t������" << m_Name
		<< "\t��λ��" << getDeptName()
		<< "\t��λְ��:��ɾ�����������" << endl;
}

string Employee::getDeptName()
{
	return string("��ͨԱ��");
}