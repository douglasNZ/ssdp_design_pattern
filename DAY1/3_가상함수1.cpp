#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal Cry" << std::endl; } // 1

	// �����Լ� : �� �Լ��� ȣ���, ������ �ð��� �������� ����
	//		    �����Ҷ� �޸� ������ ȣ���� �޶�� �ǹ�. 
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; } // 1
};
class Dog : public Animal
{
public:
	// override 
	void cry() { std::cout << "Dog Cry" << std::endl; } // 2

	virtual void cry2() { std::cout << "Dog Cry2" << std::endl; } // 1

};
int main()
{
	Animal a;
	Dog d;
	Animal* p = &d; 

//	if (������Է°� == 1) p = &a;  // ����� �Է¿� ���� ��ü ����

	// �����Ϸ��� �Ʒ� �ڵ带 ������ �Ҷ� p�� ����Ű�� ���� � ��ü�� �ִ���
	// �˼� �����ϴ�.
	// �׷���, �����Ͻÿ� �Լ� ȣ���� �����ϸ� ������ ������ Ÿ�����θ� �����մϴ�.
	p->cry(); // ��ü�� Dog �̹Ƿ� �翬�� Dog cry �� ȣ���ϴ� ����
			  // �������δ� �½��ϴ�.
			  // ������, C++�� �Լ� ȣ��� �������� Ÿ�Ը����� �Լ��� ����
				
	p->cry2();	// �����Ͻÿ��� "p�� ����Ű�� �޸𸮸� ����"�ϴ� ���� �ڵ� ����
				// �����Ҷ� �޸� ������ ��� �Լ��� ȣ������ ����..
				// �����̰�, �̼����� ����, ��, �ణ�� ��������. 
}


