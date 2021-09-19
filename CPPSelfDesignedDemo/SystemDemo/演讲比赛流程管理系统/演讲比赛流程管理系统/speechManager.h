#pragma once//��ֹͷ�ļ��ظ�����
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

	//�˵�չʾ
	void show_Menus();

	//�˳�ϵͳ
	void exit_System();

	//����ѡ��
	void CreateSpeaker();

	//��ʼ���� --�������̿���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//�������
	void speechContest();

	//��ʾ�������
	void showScore();

	//
	void saveRecord();

	//
	void loadRecord();

	//
	void showRecord();

	void clearRecord();

	~SpeechManager();

	//��ʼ������
	void initSpeech();

	vector<int> v1;//�μӱ���ѡ�ֱ������

	vector<int> v2;//��һ�ֽ���ѡ�ֱ������

	vector<int> vVictory;//ʤ��ǰ����ѡ�ֱ������

	map<int, Speaker> m_Speaker;//��ű�� �Լ���Ӧ����ѡ������

	int m_Index;//��������

	bool fileEmpty;//�ļ�Ϊ�ձ�־

	//�����¼
	map<int, vector<string>> m_Record;
	//map<int, string> m_Record; //������� û�����Ϊʲô
};