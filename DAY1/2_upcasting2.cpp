// upcasting2.cpp
#include <vector>

class Animal {};
class Dog : public Animal {};
class Cat : public Animal {};

int main()
{
	std::vector<Dog*>    v1; // Dog �� �����ϴ� vector
	std::vector<Animal*> v2; // ����(Animal�� ���� �Ļ��� ��� Ŭ����)
							// �� �����ϴ� �����̳�. 
							// 
	// upcasting Ȱ�� 1. ������ �����ϴ� �����̳� �����. 

}