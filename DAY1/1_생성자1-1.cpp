//생성자1.cpp - 3page
#include <iostream>

// 생성자 호출의 정확한 원리 

class Base
{
public:
	// 핵심. Base에는 default 생성자가 없습니다.
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	// 1. Base에 기본 생성자가 없는 경우는 아래 2줄이 에러가 발생합니다.
	//    오른쪽 주석의 컴파일러가 생성하는 코드를 잘 생각해 보세요.
//	Derived() {}				// Derived() : Base() 
//	Derived(int a) {}			// Derived(int a) : Base()

	// 2. 해결책은, Base에 기본 생성자가 없는경우, 반드시 개발자가 명시적으로 호출해야 합니다.
	Derived()      : Base(0) {}
	Derived(int n) : Base(n) {}
};

int main()
{
	Derived d1;   // call Derived::Derived()
	Derived d2(5);// call Derived::Derived(int)

}

