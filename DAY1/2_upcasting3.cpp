#include <iostream>


// upcasting3.cpp
class Animal 
{
public: 
	virtual ~Animal() {}	// 모든 기반 클래스의 소멸자는 반드시 
							// 가상함수가 되어야 합니다.
	int age;
};
class Cat : public Animal 
{
};
class Dog : public Animal
{
public:
	int color;
};

// upcasting 장점 2. 동종을 처리하는 함수를 만들수 있다
//  => 동종 : 동일 기반 클래스로 부터 파생된 클래스(타입)

//void NewYear(Dog* pDog) // 인자로 Dog 만 받을수 있는 함수
void NewYear(Animal* p)   // 모든 동물을 인자로 받는 함수.
{
	++(p->age); // 새해가 되면 나이가 증가.
	
	// 원래는 위 코드만 있었는데..
	// 나중에 새로운 요구 조건이 추가되었다.
	// 혹시, p가 Dog라면 color도 변경하고 싶다.

//	p->color = 10; // error. p의 타입이 Animal* 이므로 Animal 멤버가접근가능

	// Dog 고유 멤버에 접근하려면 캐스팅 필요
	// down cast : 기반 클래스 포인터를 파생 클래스 포인터로 다시 캐스팅 하는것
	// static_cast  : 실제 객체가 Dog가 아니라도 항상 성공. 위험하다.
	// dynamic_cast : 실제 객체가 Dog 인 경우만 성공, 아니면 0 반환 
	//				단, 반드시 가상함수가 한개 이상 있는 경우만 사용가능합니다.
//	Dog* pDog = static_cast<Dog*>(p);

	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;

	if (pDog != nullptr)
	{
		pDog->color = 10;
	}

}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);

}













