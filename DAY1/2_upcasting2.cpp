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