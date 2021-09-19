#include "orderFile.h"

string getKey(string str)
{
	int pos = str.find(":");
	string key = str.substr(0,pos);
	return key;
}

string getValue(string str)
{
	int pos = str.find(":");
	string value = str.substr(pos + 1, str.size() - pos);
	return value;
}

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string date;	//日期
	string interval;//时间段
	string stuId;	//学生编号
	string stuName;	//学生姓名
	string roomId;	//机房编号
	string status;	//预约状态

	this->m_Size = 0;

	while (ifs>>date&& ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		string key;
		string value;

		map<string, string> mTemp;

		mTemp.insert(make_pair(getKey(date),getValue(date)));
		mTemp.insert(make_pair(getKey(interval), getValue(interval)));
		mTemp.insert(make_pair(getKey(stuId), getValue(stuId)));
		mTemp.insert(make_pair(getKey(stuName), getValue(stuName)));
		mTemp.insert(make_pair(getKey(roomId), getValue(roomId)));
		mTemp.insert(make_pair(getKey(status), getValue(status)));

		this->m_orderData.insert(make_pair(this->m_Size,mTemp));
		this->m_Size++;
	}
	ifs.close();
}

void OrderFile::UpdateOrder()
{
	if (this->m_Size==0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE,ios::trunc);
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "Interval:" << this->m_orderData[i]["Interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}

	ofs.close();
}