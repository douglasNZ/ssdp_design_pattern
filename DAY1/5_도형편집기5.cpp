#include <iostream>
#include <vector>

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
				p->draw();	
		}

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// k 번째 도형의 복제본을 만들어서 v에 추가합니다.
			// 그런데, k번째 도형이 뭘까요 ?
			// 어떻게 구현 해야 할까요 ?
			
		}
	}
}
