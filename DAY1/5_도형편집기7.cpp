#include <iostream>
#include <vector>

// 코드 정리!
// 예외 전용 클래스 설계시 아래 처럼 아무런 멤버를 넣지 않아도 좋은 코드입니다.
// 클래스 이름 자체로도 충분히 의미 전달이 가능합니다.
struct NotImplemented {};

class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

protected:
	// 가상 함수   : 파생 클래스가 재정의 하지 않으면 디폴트 구현을 물려 주겠다.
	// 순수가상함수 : 파생 클래스가 만들어야 한다. 구현을 제공하지 않으면
	//										파생 클래스를 사용할수 없다.
	virtual void draw_imp() = 0;

public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}

	// clone 구현 방법
	// 1. 순수 가상 함수 - 파생 클래스 제작자에게 반드시 만들라고 지시.
//	virtual Shape* clone() = 0; 

	// 2. 기본 구현을 제공해 주는데, 예외 발생
	// 의도 : clone()을 override 하지 않고, 사용도 하지 않으면 ok
	//       clone()을 override 하지 않고, 사용하면 예외 발생
	//       clone()을 override 하고,      사용하면 ok
	virtual Shape* clone()
	{
		throw NotImplemented();
	}
};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect" << std::endl; }

	// 가상함수 override 할때 "반환 타입" 변경할수 있습니다.
	// 단, 상속관계의 타입 끼리만 가능합니다.
	// clone()은 원래 Shape* 반환인데, 아래 처럼 Rect* 로 해도 됩니다.
	Rect* clone() override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};
// Rect* r1 = new Rect;
// 
// Shape* r2 = r1->clone(); // ok
// r2->Rect_의_고유의멤버함수(); // error
// 
// Rect* r3 = r1->clone(); // ??



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

