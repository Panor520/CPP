#include <iostream>
using namespace std;

class Cube
{
public:
	int GetL()
	{
		return m_L;
	}
	int GetW()
	{
		return m_W;
	}
	int GetH()
	{
		return m_H;
	}
	void setCube(int l,int w,int h)
	{
		m_L = l;//默认访问属性时是加this指针的，this->m_L=l;
		m_W = w;
		m_H = h;
	}
	int GetSurfacearea()
	{
		return (m_L * m_H + m_L * m_W + m_H * m_W) * 2;
	}
	int GetVolume()
	{
		return m_H * m_L * m_W;
	}
	bool EqualFlag(Cube b)
	{
		if (GetL() != b.GetL() || GetW() != b.GetW() || GetH() != b.GetH())
		{
			return false;
		}

		return true;
	}

private:
	int m_L;
	int m_W;
	int m_H;
};

bool EqualFlag(Cube a,Cube b)
{
	if (a.GetL()!=b.GetL()|| a.GetW() != b.GetW()|| a.GetH() != b.GetH())
	{
		return false;
	}
	
	return true;
}

void maincube()
{
	Cube s1;
	s1.setCube(10,10,10);
	cout<<"表面积：" << s1.GetSurfacearea() << endl;
	cout << "体积：" << s1.GetVolume() << endl;

	Cube s2;
	s2.setCube(10, 10, 10);

	if (s1.EqualFlag(s2))
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "UnEqual" << endl;
	}
	

	bool result = EqualFlag(s1,s2);
	if (result)
	{
		cout << "Equal" <<endl ;
	}
	else
	{
		cout << "UnEqual" << endl;
	}
}