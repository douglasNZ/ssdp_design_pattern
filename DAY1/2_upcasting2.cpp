// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	std::vector<Dog*>    v1; // Dog 만 보관하는 vector
	std::vector<Animal*> v2; // 동종(Animal로 부터 파생된 모든 클래스)
							// 를 보관하는 컨테이너. 
							// 
	// upcasting 활용 1. 동종을 저장하는 컨테이너 만들기. 
}

// A와 B를 묶어서 관리하고 싶다.
// => A와 B의 공통의 기반 클래스를 만들어야 한다.
// => 상속은 "기존 타입의 확장" 뿐 아니라
//    타입을 "묶기 위해서"도 사용한다.