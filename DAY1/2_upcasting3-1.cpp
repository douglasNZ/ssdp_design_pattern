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

void NewYear(Animal* p) 
{
	++(p->age); 
}
// Dog 일때 기능을 추가하고 싶었다면..
// Dog 전용 버전을 새롭게 만드세요
void NewYear(Dog* p)
{
	NewYear( static_cast<Animal*>(p) );

	p->color = 10;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}










