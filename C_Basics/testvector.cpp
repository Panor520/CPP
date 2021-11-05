#include <vector>
#include <stdio.h>
#include <iostream>

void construct()
{
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third
	
	int myint[]={16,2,3};
	printf("sizeof(myint)=%ld sizeof(int)=%ld\n",sizeof(myint),sizeof(int));
	std::vector<int> fifth(myint,myint+sizeof(myint)/sizeof(int));//这个地方会有疑问，是因为迭代器的end()指向的是最后一个元素的下一个位置，也就是最后一个元素位置加1，所以这里就是要myint+3（而不是加2）	
}

void operatorequal()
{
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);

	bar = foo;
	foo = std::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

int main()
{
	//construct();
	//operatorequal();

	return 0;
}

