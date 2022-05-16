#include <iostream>

class Base
{
	// protected 소멸자를 사용하는 의도를 잘알아 두세요
	// 의도 : "Base*" 타입으로는 delete 하지 말라는 것. 
protected:
	~Base() {} 
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	Base* p2 = new Derived;	

//	delete p2;	// error.. protected 소멸자 이므로..
	delete static_cast<Derived*>(p2); // ok.. 
}

