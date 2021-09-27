#include "speechManager.h"

SpeechManager::SpeechManager()
{
	//��ʼ������������
	this->initSpeech();

	this->CreateSpeaker();

	this->loadRecord();
}

void SpeechManager::show_Menus()
{
	cout << "*********************************************" << endl;
	cout << "**************��ӭ�μ��ݽ�������***************" << endl;
	cout << "**************1.��ʼ�ݽ�����*******************" << endl;
	cout << "**************2.�鿴�����¼*******************" << endl;
	cout << "**************3.��ձ�����¼*******************" << endl;
	cout << "**************0.�˳���������*******************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

void SpeechManager::exit_System()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::CreateSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0.00;
		}

		this->v1.push_back(i + 10001);

		//����ʼ����ѡ����Ϣ��ŵ�������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

	/*for (map<int,Speaker>::iterator i = this->m_Speaker.begin(); i != this->m_Speaker.end(); i++)
	{
		cout << "ѡ�ֱ�ţ�" << (*i).first << " name:" << (*i).second.m_Name << " score:" << (*i).second.m_Score[0] << endl;
	}*/
}

void SpeechManager::speechDraw()
{
	cout << "��" << this->m_Index << "��ѡ�������ڳ�ǩ��" << endl;
	cout << "--------------------------" << endl;
	cout << "��ǩ��˳�����£�" << endl;

	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
		{
			cout << *i << endl;
		}
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator i = v2.begin(); i != v2.end(); i++)
		{
			cout << *i << endl;
		}
	}
	cout << "--------------------------" << endl;
	system("pause");
}

void SpeechManager::startSpeech()
{
	//round 1
	//��ǩ
	this->speechDraw();

	//����
	this->speechContest();
	//��ʾ�������
	this->showScore();


	//round 2
	this->m_Index++;
	//��ǩ
	this->speechDraw();
	//����
	this->speechContest();
	//��ʾ�������
	this->showScore();
	//�������
	this->saveRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");

	//��������������
	this->initSpeech();

	this->CreateSpeaker();

	this->loadRecord();
}

void SpeechManager::speechContest()
{
	cout << "��" << this->m_Index << "�ֱ�����ʼ��" << endl;

	multimap<double, int, greater<double>> groupSource;//��ʱ���������� ���� ѡ�ֱ��
	int num = 0;	//��¼��Ա���� 6��һ��
	vector<int> vTemp;
	if (this->m_Index == 1)
	{
		vTemp = v1;
	}
	else
	{
		vTemp = v2;
	}

	//�������
	for (vector<int>::iterator i = vTemp.begin(); i != vTemp.end(); i++)
	{
		num++;

		deque<double> d;
		for (int i = 0; i < 10; i++)
		{

			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());//���� �Ӵ�С
		d.pop_back();//ȥ����ͷ�
		d.pop_front();//ȥ����߷�

		double sum = accumulate(d.begin(), d.end(), 0.0f);//��ȡ�ܷ�
		double avg = sum / (double)d.size();

		//����ÿ���˶�ƽ���ֵ�map����
		this->m_Speaker[*i].m_Score[this->m_Index - 1] = avg;//m_IndexĬ����1���ʴ˴���һ�θ�ֵӦ-1

		//6����һ�� ��ŵ���ʱ����
		groupSource.insert(make_pair(avg, *i));

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������Ϊ��" << endl;
			for (multimap<double, int, greater<double>>::iterator i = groupSource.begin(); i != groupSource.end(); i++)
			{
				cout << "��ţ�" << i->second << "������" << this->m_Speaker[i->second].m_Name
					<< " �ɼ�: " << this->m_Speaker[i->second].m_Score[this->m_Index - 1] << endl;
			}

			int count = 0;

			for (multimap<double, int, greater<double>>::iterator i = groupSource.begin(); i != groupSource.end() && count < 3; i++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*i).second);
				}
				else
				{
					vVictory.push_back((*i).second);
				}
			}

			groupSource.clear();
			cout << endl;
		}
	}

	cout << "��" << this->m_Index << "�ֱ�����ϣ�" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�" << endl;
	vector<int> vTemp;
	if (this->m_Index == 1)
	{
		vTemp = v2;
	}
	else
	{
		vTemp = vVictory;
	}

	for (vector<int>::iterator i = vTemp.begin(); i != vTemp.end(); i++)
	{
		cout << "ѡ�ֱ�ţ�" << (*i) << " ������" << m_Speaker[*i].m_Name << " �÷֣�" << m_Speaker[*i].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menus();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	//������д�뵽�ļ���
	for (vector<int>::iterator i = vVictory.begin(); i != vVictory.end(); i++)
	{
		ofs << *i << "," << m_Speaker[*i].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�ѱ��棡" << endl;
	this->fileEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	//�ļ�����û������ֵ��ļ�
	if (!ifs.is_open())
	{
		this->fileEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ�����������ļ���������Ϊ��
	char ch;
	ifs >> ch;//���Ƿ�����ַ�
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	this->fileEmpty = false;

	//�������ȡ��һ���ַ��ٷŻ�ȥ
	ifs.putback(ch);

	string data;
	int index = 0;
	while (ifs >> data)
	{
		vector<string> v;
		//string s;
		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;//�Ҳ�������
			}
			string tmp = data.substr(start, pos - start);
			start = pos + 1;
			v.push_back(tmp);
			//s = tmp;
		}

		this->m_Record.insert(make_pair(index, v));
		//this->m_Record.insert(make_pair(index,s));
		index++;
	}

	ifs.close();
}

void SpeechManager::showRecord()
{
	if (this->fileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " " <<
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " " <<
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << " " << endl;
		}
	}
	system("pause");
	system("cls");

}

void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select==1)
	{
		ofstream ofs("speech.csv",ios::trunc);//ios����trunc �������ɾ���ļ������´���
		ofs.close();


		//��������������
		this->initSpeech();

		this->CreateSpeaker();

		this->loadRecord();

		cout << "��ճɹ�" << endl;
	}

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::initSpeech()
{
	//�����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	this->m_Index = 1;

	this->m_Speaker.clear();
	this->m_Record.clear();
}