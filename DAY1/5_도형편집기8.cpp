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

		// ���� ���� 1. ��ü�� ������ OCP�� �����ϰ� ���������� �Ҽ� ������ ?
		//				Triangle �߰��Ǿ �Ʒ� �ڵ尡 �������� �ʵ���..!
		// ==> �߻� ���丮 ������ �����ϸ� �˴ϴ�. ����ϳ� ���ϴ�

		// ���� ���� 2. Undo/Redo�� �Ϸ��� ��� �ڵ带 �ۼ� �ؾ� �ұ�� ?
		// ==> Command ������ �˸� �˴ϴ�... Undo/Redo �� ����ϴ� �ڵ� ���Ͽ�
		//								�̸��� �ٿ� ������
		//		����ϳ� ���ϴ�.

		if (cmd == 1) v.push_back(new Rect);
		
		else if (cmd == 2) v.push_back(new Circle);


		else if (cmd == 9)
		{
			for (auto p : v)
				p->draw(); // ������. OCP ����
		}

		else if (cmd == 8)
		{
			std::cout << "�� ��° ������ ���� �ұ�� >> ";
			int k;
			std::cin >> k;

			v.push_back(v[k]->clone()); // ������. OCP ����

		}
	}
}

