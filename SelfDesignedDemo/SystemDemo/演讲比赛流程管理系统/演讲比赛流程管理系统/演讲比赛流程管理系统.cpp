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

		cout << "���������ѡ��" << endl;
		cin >> x;
		switch (x)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴�����¼
			sm.showRecord();
			break;
		case 3://��ձ�����¼
			sm.clearRecord();
			break;
		case 0://�˳���������
			sm.exit_System();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
}