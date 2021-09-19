#include "speechManager.h"
#include <ctime>

void main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int x;
	while (true)
	{
		sm.show_Menus();

		cout << "请输入你的选择：" << endl;
		cin >> x;
		switch (x)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看往届记录
			sm.showRecord();
			break;
		case 3://清空比赛记录
			sm.clearRecord();
			break;
		case 0://退出比赛程序
			sm.exit_System();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
}