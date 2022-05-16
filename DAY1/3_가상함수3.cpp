#include <iostream>

// ���ۿ��� "C++ Core Guideline" �˻��� ������.
// 1��° ��ũ

// C35. ��� Ŭ������ �Ҹ��ڴ� �ݵ��
// 1. public  �����Լ��̰ų�
// 2. protected non-virtua �� �ؾ� �Ѵ�.

class Base
{
	// protected �Ҹ��ڸ� ����ϴ� �ǵ��� �߾˾� �μ���
	// �ǵ� : "Base*" Ÿ�����δ� delete ���� ����� ��. 
protected:
	~Base() {} 
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p2 = new Derived;	

//	delete p2;	// error.. protected �Ҹ��� �̹Ƿ�..
	delete static_cast<Derived*>(p2); // ok.. 
}

