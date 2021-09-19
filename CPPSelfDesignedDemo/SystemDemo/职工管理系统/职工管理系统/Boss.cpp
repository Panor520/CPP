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
	cout << "编号：" << m_Id
		<< "\t姓名：" << m_Name
		<< "\t岗位：" << getDeptName()
		<< "\t岗位职责:管理公司所有事情" << endl;
}