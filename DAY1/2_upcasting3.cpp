// upcasting3.cpp
class Animal 
{
public: 
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
	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);

}













