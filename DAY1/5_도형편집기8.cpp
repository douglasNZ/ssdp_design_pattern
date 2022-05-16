#include <iostream>
#include <vector>

struct NotImplemented {};

class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

protected:
	virtual void draw_imp() = 0;

public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}

	virtual Shape* clone()
	{
		throw NotImplemented();
	}
};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect" << std::endl; }

	Rect* clone() override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};


class Circle : public Shape
{
public:
	void draw_imp()  override { std::cout << "draw circle" << std::endl; }
	Circle* clone() override
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

		// 도전 과제 1. 객체의 생성을 OCP를 만족하게 다형적으로 할수 없을까 ?
		//				Triangle 추가되어도 아래 코드가 수정되지 않도록..!
		// ==> 추상 팩토리 패턴을 도입하면 됩니다. 목요일날 배웁니다

		// 도전 과제 2. Undo/Redo를 하려면 어떻게 코드를 작성 해야 할까요 ?
		// ==> Command 패턴을 알면 됩니다... Undo/Redo 에 사용하는 코딩 패턴에
		//								이름을 붙여 놓은것
		//		목요일날 배웁니다.

		if (cmd == 1) v.push_back(new Rect);
		
		else if (cmd == 2) v.push_back(new Circle);


		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw(); // 다형성. OCP 만족
		}

		else if (cmd == 8)
		{
			std::cout << "몇 번째 도형을 복제 할까요 >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // 다형성. OCP 만족

		}
	}
}

