#include <iostream>
#include <vector>


// 3. 모든 도형의 공통의 특징은 반드시 Shape 에도 있어야 한다.
//    그래야, Shape 포인터로 도형을 묶을때, 해당 기능을 사용할수 있다.

// 4. 기반 클래스가 가진 함수중, 파생 클래스에서 재정의하게 되는 것은
//    반드시 가상함수로 만들어야 한다.
//    "가상함수가 아닌 함수를 재정의 하지 말라" - Effective-C++ 책의 격언

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
