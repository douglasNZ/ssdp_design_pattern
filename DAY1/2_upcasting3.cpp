// upcasting3.cpp
class Animal 
{
public: 
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
	Dog* pDog = static_cast<Dog*>(p);

	std::cout << pDog << std::endl;
}

int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);

}













