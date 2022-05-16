// 1_������2-1.cpp
#include <string>
#include <iostream>

class People
{
	std::string name;
	int age;
public:
	// ��� ��ü�� �׻� ��ȿ�� ���·� ��������� �մϴ�
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
//	People p1;	// �̷��� ��ü�� ����� �ִٴ� ���� ������� ? (�ʱ�ȭ ���� ���� ��ü)
	People p2("kim", 20);

//	Student s(99); // error
	Student s("kim", 20, 99); // ok
}


