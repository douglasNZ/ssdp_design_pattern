// 1_생성자2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// 모든 객체는 항상 유효한 상태로 만들어져야 합니다
	People(const std::string& name, int age) : name(name), age(age) {}
};

class Student : public People
{
	int id;
public:
//	Student(int id) : id(id) {} // Student(int id) : People(), id(id) {}

	Student(const std::string& name, int age, int id)
		: People(name, age), id(id) {}
};

int main()
{
//	People p1;	// 이렇게 객체를 만들수 있다는 것이 좋을까요 ? (초기화 되지 않은 객체)
	People p2("kim", 20);

//	Student s(99); // error
	Student s("kim", 20, 99); // ok
}


