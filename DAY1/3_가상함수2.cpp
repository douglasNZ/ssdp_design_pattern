#include <iostream>

class Base
{
public:
	virtual ~Base() {} // ���� �Ҹ���
						// ��� ��� Ŭ������ �Ҹ��ڴ� �����Լ� �̾�� �մϴ�.
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
//	Derived d;

//	Derived* p1 = new Derived;	
//	delete p1;	

	Base*  p2 = new Derived;	// 1. sizeof(Derived) ũ���� �޸� �Ҵ�
								// 2. Derived() ������ ȣ��. 

	// C++���� �Լ� ȣ���� "�⺻������ ������ �Ҷ� ����"
	// ���� - ������ Ÿ������, 
	//		 (�����Ͱ� ����Ű�� ���� � ��ü������ �����Ϸ��� �˼� ����.)
	delete p2;	// 1. �Ҹ��� ȣ��
				// 2. �޸� ����.
}	



