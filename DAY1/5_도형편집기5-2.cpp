// #include <iostream>
#include <vector>

class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	// 다형성은 OCP를 만족하는 좋은 특징입니다
	// 다형성은 결국 C++에서는 "가상함수"를 의미 합니다.
	// 자신의 복제본을 만드는 가상함수는 항상 유용하게 사용됩니다.
	
	virtual Shape* clone()
	{
		Shape* p = new Shape(*this); // 자신과 동일한 객체 생성(복사생성자사용)
		return p;
	}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

class Circle : public Shape
{
public:
	void draw()  override { std::cout << "draw circle" << std::endl; }

	Shape* clone() override
	{
		Circle* p = new Circle(*this);
		return p;
	}
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

			v.push_back( v[k]->clone() );// 다형성..
						// v[k] 가 가리키는 도형이 어떤 도형인지 알필요없습니다.
						// Triangle이 추가되어도 이 한줄은 수정되거나 추가될 필요
						// 없습니다.
		}
	}
}
