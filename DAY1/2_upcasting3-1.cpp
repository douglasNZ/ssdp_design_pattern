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

void NewYear(Animal* p) 
{
	++(p->age); 
}
// Dog �϶� ����� �߰��ϰ� �;��ٸ�..
// Dog ���� ������ ���Ӱ� ���弼��
void NewYear(Dog* p)
{
	NewYear( static_cast<Animal*>(p) );

	p->color = 10;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);
}










