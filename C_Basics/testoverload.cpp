#include <stdio.h>

class girl
{
private:
	int m_age;

public:
	void setage(int* age);
	bool operator==(const girl & g);
	int operator+(const girl &g);
};

void girl::setage(int * age)
{
	m_age=*age;
}

bool girl::operator==(const girl & g)
{
	if(m_age==g.m_age)
		return true;
	return false;
}

int girl::operator+(const girl & g)
{
	return g.m_age+m_age;
}

int main()
{
	girl gg,gg1;
	int x=18;
	gg.setage(&x);
	x=18;
	gg1.setage(&x);
	if(gg==gg1)
		printf("equal\n");
	else
		printf("unequal\n");

	printf("%d\n",gg+gg1);
	return 0;
}


