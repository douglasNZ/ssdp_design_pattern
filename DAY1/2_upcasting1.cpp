class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Dog* p1 = &d;   // ok
//	int* p2 = &d;	// error
	Animal* p3 = &d;// ok.. upcasting

	// �� �������� 3���� ����� �� ����ϼ���

	// �ٽ� 1. ��� Ŭ���� �����ͷ� �Ļ� Ŭ���� ��ü�� �ּҸ� ������ �ִ�.

	// �ٽ� 2. Animal* �� Dog�� ����ų��, �����ͷδ� Animal�� 
	//		  ����� �����Ҽ� �ִ�. (��ü�� Dog�� �ϴ���..)
	//	      �����Ϸ��� �׻� ������ Ÿ�����θ� ��� ������ Ȯ���Ѵ�.!
	p3->age = 10;   // ok
//	p3->color = 10; // error

	// �ٽ� 3. Dog ������ ����� �����Ϸ��� Dog*�� ĳ���� �Ѵ�.
	// => ��, p3�� ����Ű�� ���� Dog��� Ȯ���Ҽ� ��������..
	static_cast<Dog*>(p3)->color = 10; // ok
}











