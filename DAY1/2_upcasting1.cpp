class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d;   // ok
//	int* p2 = &d;	// error
	Animal* p3 = &d;// ok.. upcasting

	// 이 예제에서 3가지 사실을 꼭 기억하세요

	// 핵심 1. 기반 클래스 포인터로 파생 클래스 객체의 주소를 담을수 있다.

	// 핵심 2. Animal* 로 Dog를 가리킬때, 포인터로는 Animal의 
	//		  멤버만 접근할수 있다. (객체가 Dog라 하더라도..)
	//	      컴파일러는 항상 포인터 타입으로만 멤버 접근을 확인한다.!
	p3->age = 10;   // ok
//	p3->color = 10; // error

	// 핵심 3. Dog 고유의 멤버에 접근하려면 Dog*로 캐스팅 한다.
	// => 단, p3가 가리키는 것이 Dog라고 확신할수 있을때만..
	static_cast<Dog*>(p3)->color = 10; // ok
}











