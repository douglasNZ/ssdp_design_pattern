// protected �������� �ǹ� : �ڽ��� ��ü�� �����Ҽ� ������(�߻��� ����)
//			�Ļ� Ŭ������ ��ü�� �����Ҽ��ִ�.(��ü�� ����(concrete))

class Animal
{
protected:    
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}  // Dog() : Animal() {}
};
int main()
{
	// ������ ������ ��� ��� ������
	Animal a; // error
	Dog    d; // ok
}



