// #include <iostream>
#include <vector>

class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

	virtual void draw() { std::cout << "draw shape" << std::endl; }

	// �������� OCP�� �����ϴ� ���� Ư¡�Դϴ�
	// �������� �ᱹ C++������ "�����Լ�"�� �ǹ� �մϴ�.
	// �ڽ��� �������� ����� �����Լ��� �׻� �����ϰ� ���˴ϴ�.
	
	virtual Shape* clone()
	{
		Shape* p = new Shape(*this); // �ڽŰ� ������ ��ü ����(��������ڻ��)
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
			std::cout << "�� ��° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back( v[k]->clone() );// ������..
						// v[k] �� ����Ű�� ������ � �������� ���ʿ�����ϴ�.
						// Triangle�� �߰��Ǿ �� ������ �����ǰų� �߰��� �ʿ�
						// �����ϴ�.
		}
	}
}
