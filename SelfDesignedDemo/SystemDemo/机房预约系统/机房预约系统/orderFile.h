#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globalFile.h"
#include <string>

class OrderFile
{
public:
	OrderFile();

	//更新预约记录
	void UpdateOrder();

	//记录的容器 Key--条数， value，具体信息
	map<int, map<string, string>> m_orderData;

	//预约记录数
	int m_Size;
};