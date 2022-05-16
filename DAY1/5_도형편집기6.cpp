#include <iostream>
#include <vector>

// 7. template method 패턴 
//	  기반클래스가 가진 함수중, 
//    변하지 않은 코드 내의 변하는 부분만 가상함수화 한다.
//    파생 클래스는 변하지 않은 전체 흐름은 물려 받게 되고,
//    변하는 부분만 재정의 할수 있다.

// "template method"라는 이름의 패턴인데
// C++ 진영에서는 "NVI(non-virtual-interface)"라고도 합니다.


class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

	// 공통성과 가변성의 분리
	// 변하지 않은 흐름속에 있는 변해야 하는 코드는 분리 되어야 한다.
	// 변해야 하는 것을 가상함수로 분리한다.
protected:
	virtual void draw_imp() 
	{
		std::cout << "draw shape" << std::endl; 
	}
public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}


	virtual Shape* clone()
	{
		Shape* p = new Shape(*this); 
		return p;
	}
};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect" << std::endl; }

	Shape* clone() override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};

class Circle : public Shape
{
public:
	void draw_imp()  override { std::cout << "draw circle" << std::endl; }

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

			v.push_back(v[k]->clone());
					
		}
	}
}

