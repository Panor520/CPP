#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
// ���ݾ���·�����ļ�����Ŀ¼���𼶵Ĵ���Ŀ¼��
// pathorfilename������·�����ļ�����Ŀ¼����
// bisfilename��˵��pathorfilename�����ͣ�true-pathorfilename���ļ�����������Ŀ¼����ȱʡֵΪtrue��
// ����ֵ��true-�ɹ���false-ʧ�ܣ��������ʧ�ܣ�ԭ���д�������������1��Ȩ�޲��㣻2��pathorfilename�������ǺϷ����ļ�����Ŀ¼����3�����̿ռ䲻�㡣
bool MKDIR(const char *pathorfilename,bool bisfilename=true);