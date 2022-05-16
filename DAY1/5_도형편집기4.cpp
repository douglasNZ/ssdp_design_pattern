#include <iostream>
#include <vector>

// 5. ������ : ������ ǥ������ ��Ȳ�� ���� �ٸ��� �����ϴ� ��
//    => ������ ����� �ڵ�� "OCP"�� �����ϴ� ���� �ڵ尡 �ȴ�.


class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape" << std::endl; }
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw()  override { std::cout << "draw circle" << std::endl; }
};

class Triangle : public Shape
{
public:
	void draw()  override { std::cout << "draw triangle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw();	// �ٽ� !
							// ������( Polymorphism )
							// ������ ǥ������ ��Ȳ(��ü�� ����)�� ����
							// �ٸ��� �����ϴ°�. 
			// ��ü���� ����� 3�� Ư¡ : ĸ��ȭ, ���, ������
		}
	}
}
