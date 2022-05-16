#include <iostream>


// upcasting3.cpp
class Animal 
{
public: 
	virtual ~Animal() {}	// ��� ��� Ŭ������ �Ҹ��ڴ� �ݵ�� 
							// �����Լ��� �Ǿ�� �մϴ�.
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

// upcasting ���� 2. ������ ó���ϴ� �Լ��� ����� �ִ�
//  => ���� : ���� ��� Ŭ������ ���� �Ļ��� Ŭ����(Ÿ��)

//void NewYear(Dog* pDog) // ���ڷ� Dog �� ������ �ִ� �Լ�
void NewYear(Animal* p)   // ��� ������ ���ڷ� �޴� �Լ�.
{
	++(p->age); // ���ذ� �Ǹ� ���̰� ����.
	
	// ������ �� �ڵ常 �־��µ�..
	// ���߿� ���ο� �䱸 ������ �߰��Ǿ���.
	// Ȥ��, p�� Dog��� color�� �����ϰ� �ʹ�.

//	p->color = 10; // error. p�� Ÿ���� Animal* �̹Ƿ� Animal ��������ٰ���

	// Dog ���� ����� �����Ϸ��� ĳ���� �ʿ�
	// down cast : ��� Ŭ���� �����͸� �Ļ� Ŭ���� �����ͷ� �ٽ� ĳ���� �ϴ°�
	// static_cast  : ���� ��ü�� Dog�� �ƴ϶� �׻� ����. �����ϴ�.
	// dynamic_cast : ���� ��ü�� Dog �� ��츸 ����, �ƴϸ� 0 ��ȯ 
	//				��, �ݵ�� �����Լ��� �Ѱ� �̻� �ִ� ��츸 ��밡���մϴ�.
//	Dog* pDog = static_cast<Dog*>(p);

	Dog* pDog = dynamic_cast<Dog*>(p);

	std::cout << pDog << std::endl;

	if (pDog != nullptr)
	{
		pDog->color = 10;
	}

}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);

}













