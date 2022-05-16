#include <iostream>
#include <vector>


// 3. ��� ������ ������ Ư¡�� �ݵ�� Shape ���� �־�� �Ѵ�.
//    �׷���, Shape �����ͷ� ������ ������, �ش� ����� ����Ҽ� �ִ�.

// 4. ��� Ŭ������ ���� �Լ���, �Ļ� Ŭ�������� �������ϰ� �Ǵ� ����
//    �ݵ�� �����Լ��� ������ �Ѵ�.
//    "�����Լ��� �ƴ� �Լ��� ������ ���� ����" - Effective-C++ å�� �ݾ�

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
				p->draw();   
		}
	}
}
