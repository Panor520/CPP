#include "speechManager.h"

SpeechManager::SpeechManager()
{
	//初始化容器和属性
	this->initSpeech();

	this->CreateSpeaker();

	this->loadRecord();
}

void SpeechManager::show_Menus()
{
	cout << "*********************************************" << endl;
	cout << "**************欢迎参加演讲比赛！***************" << endl;
	cout << "**************1.开始演讲比赛*******************" << endl;
	cout << "**************2.查看往届记录*******************" << endl;
	cout << "**************3.清空比赛记录*******************" << endl;
	cout << "**************0.退出比赛程序*******************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

void SpeechManager::exit_System()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::CreateSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0.00;
		}

		this->v1.push_back(i + 10001);

		//将初始化的选手信息存放到容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}

	/*for (map<int,Speaker>::iterator i = this->m_Speaker.begin(); i != this->m_Speaker.end(); i++)
	{
		cout << "选手编号：" << (*i).first << " name:" << (*i).second.m_Name << " score:" << (*i).second.m_Score[0] << endl;
	}*/
}

void SpeechManager::speechDraw()
{
	cout << "第" << this->m_Index << "轮选手你正在抽签：" << endl;
	cout << "--------------------------" << endl;
	cout << "抽签后顺序如下：" << endl;

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
	//抽签
	this->speechDraw();

	//比赛
	this->speechContest();
	//显示比赛结果
	this->showScore();


	//round 2
	this->m_Index++;
	//抽签
	this->speechDraw();
	//比赛
	this->speechContest();
	//显示比赛结果
	this->showScore();
	//保存分数
	this->saveRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");

	//重置容器和属性
	this->initSpeech();

	this->CreateSpeaker();

	this->loadRecord();
}

void SpeechManager::speechContest()
{
	cout << "第" << this->m_Index << "轮比赛开始：" << endl;

	multimap<double, int, greater<double>> groupSource;//临时容器，保存 分数 选手编号
	int num = 0;	//记录人员个数 6个一组
	vector<int> vTemp;
	if (this->m_Index == 1)
	{
		vTemp = v1;
	}
	else
	{
		vTemp = v2;
	}

	//遍历打分
	for (vector<int>::iterator i = vTemp.begin(); i != vTemp.end(); i++)
	{
		num++;

		deque<double> d;
		for (int i = 0; i < 10; i++)
		{

			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());//排序 从大到小
		d.pop_back();//去掉最低分
		d.pop_front();//去掉最高分

		double sum = accumulate(d.begin(), d.end(), 0.0f);//获取总分
		double avg = sum / (double)d.size();

		//保存每个人都平均分到map容器
		this->m_Speaker[*i].m_Score[this->m_Index - 1] = avg;//m_Index默认是1，故此处第一次赋值应-1

		//6个人一组 存放到临时容器
		groupSource.insert(make_pair(avg, *i));

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次为：" << endl;
			for (multimap<double, int, greater<double>>::iterator i = groupSource.begin(); i != groupSource.end(); i++)
			{
				cout << "编号：" << i->second << "姓名：" << this->m_Speaker[i->second].m_Name
					<< " 成绩: " << this->m_Speaker[i->second].m_Score[this->m_Index - 1] << endl;
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

	cout << "第" << this->m_Index << "轮比赛完毕！" << endl;
	system("pause");
}

void SpeechManager::showScore()
{
	cout << "第" << this->m_Index << "轮晋级选手信息如下：" << endl;
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
		cout << "选手编号：" << (*i) << " 姓名：" << m_Speaker[*i].m_Name << " 得分：" << m_Speaker[*i].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menus();
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将数据写入到文件中
	for (vector<int>::iterator i = vVictory.begin(); i != vVictory.end(); i++)
	{
		ofs << *i << "," << m_Speaker[*i].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭文件
	ofs.close();

	cout << "记录已保存！" << endl;
	this->fileEmpty = false;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	//文件夹下没这个名字的文件
	if (!ifs.is_open())
	{
		this->fileEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件夹下有这个文件但是内容为空
	char ch;
	ifs >> ch;//看是否读到字符
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		this->fileEmpty = true;
		ifs.close();
		return;
	}

	this->fileEmpty = false;

	//将上面读取的一个字符再放回去
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
				break;//找不到返回
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
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "界" <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " " <<
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " " <<
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << " " << endl;
		}
	}
	system("pause");
	system("cls");

}

void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;
	if (select==1)
	{
		ofstream ofs("speech.csv",ios::trunc);//ios：：trunc 如果存在删除文件并重新创建
		ofs.close();


		//重置容器和属性
		this->initSpeech();

		this->CreateSpeaker();

		this->loadRecord();

		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::initSpeech()
{
	//容器置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	this->m_Index = 1;

	this->m_Speaker.clear();
	this->m_Record.clear();
}