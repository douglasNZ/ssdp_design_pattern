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

void NewYear(Dog* pDog) // ���ڷ� Dog �� ������ �ִ� �Լ�
//void NewYear(Animal* p)   // ��� ������ ���ڷ� �޴� �Լ�.
{
	++(p->age); // ���ذ� �Ǹ� ���̰� ����.
	
}
int main()
{
	Animal a; NewYear(&a);
	Dog    d; NewYear(&d);
	Cat    c; NewYear(&c);

}













