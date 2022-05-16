#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } // 1

	// 가상함수 : 이 함수는 호출시, 컴파일 시간에 결정하지 말고
	//		    실행할때 메모리 조사후 호출해 달라는 의미. 
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; } // 1
};
class Dog : public Animal
{
public:
	// override 
	void cry() { std::cout << "Dog Cry" << std::endl; } // 2

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; } // 1

};
int main()
{
	Animal a;
	Dog d;
	Animal* p = &d; 

//	if (사용자입력값 == 1) p = &a;  // 사용자 입력에 따라 객체 변경

	// 컴파일러는 아래 코드를 컴파일 할때 p가 가리키는 곳이 어떤 객체가 있는지
	// 알수 없습니다.
	// 그래서, 컴파일시에 함수 호출을 결정하면 무조건 포인터 타입으로만 결정합니다.
	p->cry(); // 객체가 Dog 이므로 당연히 Dog cry 를 호출하는 것이
			  // 논리적으로는 맞습니다.
			  // 하지만, C++은 함수 호출시 포인터의 타입만으로 함수를 결정
				
	p->cry2();	// 컴파일시에는 "p가 가리키는 메모리를 조사"하는 기계어 코드 생성
				// 실행할때 메모리 조사후 어느 함수를 호출할지 결정..
				// 논리적이고, 이성적인 결정, 단, 약간의 성능저하. 
}


