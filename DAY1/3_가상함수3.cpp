#include <iostream>

// 구글에서 "C++ Core Guideline" 검색해 보세요.
// 1번째 링크

// C35. 기반 클래스의 소멸자는 반드시
// 1. public  가상함수이거나
// 2. protected non-virtua 로 해야 한다.

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

