#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A Struct." << std::endl;
	}
	~A()
	{
		std::cout << "~A Struct." << std::endl;
	}

	A(const A& b)
	{
		std::cout << "A copy Struct." << std::endl;
	}

	A& operator=(const A& b)
	{
		std::cout << "A sign Struct." << std::endl;
		return *this;
	}

	A(A&& b)
	{
		std::cout << "A move copy Struct." << std::endl;
	}

	A& operator=(const A&& b)
	{
		std::cout << "A move sign Struct." << std::endl;
		return *this;
	}
};

A Fun(A&& a)
{
	return std::move(a);
}

int main()
{
	A a;
	//Fun(a);
	auto b = Fun(std::move(a));
	getchar();
}
