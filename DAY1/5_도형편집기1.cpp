#include <iostream>
#include <vector>

// 1. ��� ������ Ÿ������ �����ϸ� ���ϴ�.

// 2. ��� ������ ������ ��� Ŭ������ �ִٸ�
//    ��� ������ �ϳ��� �����̳ʿ� �����Ҽ� �ִ�.

class Shape
{
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
//	std::vector<Rect*> v; // Rect �� ���� ������ vector
	std::vector<Shape*> v; // ��� ������ ���� ������ vector!! �ٽ�!!

}

