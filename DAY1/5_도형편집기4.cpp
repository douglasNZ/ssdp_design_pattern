#include <iostream>
#include <vector>

// 5. 다형성 : 동일한 표현식이 상황에 따라 다르게 동작하는 것
//    => 다형성 기반의 코드는 "OCP"를 만족하는 좋은 코드가 된다.


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
				p->draw();	// 핵심 !
							// 다형성( Polymorphism )
							// 동일한 표현식이 상황(객체의 종류)에 따라
							// 다르게 동작하는것. 
			// 객체지향 언어의 3대 특징 : 캡슐화, 상속, 다형성
		}
	}
}
