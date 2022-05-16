#include <iostream>

class Base
{
public:
	virtual ~Base() {} // 가상 소멸자
						// 모든 기반 클래스의 소멸자는 가상함수 이어야 합니다.
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p1 = new Derived;	
//	delete p1;	

	Base*  p2 = new Derived;	// 1. sizeof(Derived) 크기의 메모리 할당
								// 2. Derived() 생성자 호출. 

	// C++에서 함수 호출은 "기본적으로 컴파일 할때 결정"
	// 원리 - 포인터 타입으로, 
	//		 (포인터가 가리키는 곳이 어떤 객체인지는 컴파일러는 알수 없다.)
	delete p2;	// 1. 소멸자 호출
				// 2. 메모리 해지.
}	



