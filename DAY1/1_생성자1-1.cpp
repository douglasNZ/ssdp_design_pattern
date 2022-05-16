//������1.cpp - 3page
#include <iostream>

// ������ ȣ���� ��Ȯ�� ���� 

class Base
{
public:
	// �ٽ�. Base���� default �����ڰ� �����ϴ�.
	Base(int a) { std::cout << "Base(int)" << std::endl; }
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	// 1. Base�� �⺻ �����ڰ� ���� ���� �Ʒ� 2���� ������ �߻��մϴ�.
	//    ������ �ּ��� �����Ϸ��� �����ϴ� �ڵ带 �� ������ ������.
//	Derived() {}				// Derived() : Base() 
//	Derived(int a) {}			// Derived(int a) : Base()

	// 2. �ذ�å��, Base�� �⺻ �����ڰ� ���°��, �ݵ�� �����ڰ� ��������� ȣ���ؾ� �մϴ�.
	Derived()      : Base(0) {}
	Derived(int n) : Base(n) {}
};

int main()
{
	Derived d1;   // call Derived::Derived()
	Derived d2(5);// call Derived::Derived(int)

}

