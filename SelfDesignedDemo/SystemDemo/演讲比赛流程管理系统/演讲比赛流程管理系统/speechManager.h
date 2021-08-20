#pragma once//防止头文件重复包含
#include <iostream>
#include <vector>
#include <map>
#include "Speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>
using namespace std;

class SpeechManager
{
public:
	SpeechManager();

	//菜单展示
	void show_Menus();

	//退出系统
	void exit_System();

	//生成选手
	void CreateSpeaker();

	//开始比赛 --比赛流程控制
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛打分
	void speechContest();

	//显示比赛结果
	void showScore();

	//
	void saveRecord();

	//
	void loadRecord();

	//
	void showRecord();

	void clearRecord();

	~SpeechManager();

	//初始化属性
	void initSpeech();

	vector<int> v1;//参加比赛选手编号容器

	vector<int> v2;//第一轮晋级选手编号容器

	vector<int> vVictory;//胜出前三名选手编号容器

	map<int, Speaker> m_Speaker;//存放编号 以及对应具体选手容器

	int m_Index;//比赛轮数

	bool fileEmpty;//文件为空标志

	//往届记录
	map<int, vector<string>> m_Record;
	//map<int, string> m_Record; //这个不行 没想出来为什么
};