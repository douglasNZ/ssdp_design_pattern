#include <iostream>
#include <vector>

class Shape
{
protected:
	Shape() {}

public:
	int type;

	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape" << std::endl; }
};




class Rect : public Shape
{
public:
	Rect() { type = 1; }

	void draw() override { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	Circle() { type = 2; }

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

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// C언어를 오랜동안 사용한 개발자들은 아래처럼 만들곤 합니다.
			// => 이 코드는 새로운 도형(Triangle등)을 추가하면 
			//    한줄 추가되어야 합니다. OCP를 만족할수 없습니다.
			switch (v[k]->type)
			{
			case 1: v.push_back(new Rect(*v[k])); break;
			case 2: v.push_back(new Circle(*v[k])); break;
			}
		}
	}
}
