#include "Manager.h"

Manager::Manager(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


void Manager::showInfo()
{
	cout << "编号：" << this->m_Id
		<< "\t姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责:完成分配的管理工作！" << endl;
}

string Manager::getDeptName()
{
	return "经理";
}
