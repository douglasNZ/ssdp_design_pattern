#include <iostream>
#include <vector>

// 7. template method ���� 
//	  ���Ŭ������ ���� �Լ���, 
//    ������ ���� �ڵ� ���� ���ϴ� �κи� �����Լ�ȭ �Ѵ�.
//    �Ļ� Ŭ������ ������ ���� ��ü �帧�� ���� �ް� �ǰ�,
//    ���ϴ� �κи� ������ �Ҽ� �ִ�.

// "template method"��� �̸��� �����ε�
// C++ ���������� "NVI(non-virtual-interface)"��� �մϴ�.


class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

	// ���뼺�� �������� �и�
	// ������ ���� �帧�ӿ� �ִ� ���ؾ� �ϴ� �ڵ�� �и� �Ǿ�� �Ѵ�.
	// ���ؾ� �ϴ� ���� �����Լ��� �и��Ѵ�.
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
			std::cout << "�� ��° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());
					
		}
	}
}

