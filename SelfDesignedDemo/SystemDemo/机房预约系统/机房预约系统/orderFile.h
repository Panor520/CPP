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

	//����ԤԼ��¼
	void UpdateOrder();

	//��¼������ Key--������ value��������Ϣ
	map<int, map<string, string>> m_orderData;

	//ԤԼ��¼��
	int m_Size;
};