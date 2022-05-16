#include <iostream>
#include <vector>

// �ڵ� ����!
// ���� ���� Ŭ���� ����� �Ʒ� ó�� �ƹ��� ����� ���� �ʾƵ� ���� �ڵ��Դϴ�.
// Ŭ���� �̸� ��ü�ε� ����� �ǹ� ������ �����մϴ�.
struct NotImplemented {};

class Shape
{
protected:
	Shape() {}

public:
	virtual ~Shape() {}

protected:
	// ���� �Լ�   : �Ļ� Ŭ������ ������ ���� ������ ����Ʈ ������ ���� �ְڴ�.
	// ���������Լ� : �Ļ� Ŭ������ ������ �Ѵ�. ������ �������� ������
	//										�Ļ� Ŭ������ ����Ҽ� ����.
	virtual void draw_imp() = 0;

public:
	void draw()
	{
		std::cout << "mutex lock" << std::endl;
		draw_imp();
		std::cout << "mutex unlock" << std::endl;
	}

	// clone ���� ���
	// 1. ���� ���� �Լ� - �Ļ� Ŭ���� �����ڿ��� �ݵ�� ������ ����.
//	virtual Shape* clone() = 0; 

	// 2. �⺻ ������ ������ �ִµ�, ���� �߻�
	// �ǵ� : clone()�� override ���� �ʰ�, ��뵵 ���� ������ ok
	//       clone()�� override ���� �ʰ�, ����ϸ� ���� �߻�
	//       clone()�� override �ϰ�,      ����ϸ� ok
	virtual Shape* clone()
	{
		throw NotImplemented();
	}
};


class Rect : public Shape
{
public:
	void draw_imp() override { std::cout << "draw rect" << std::endl; }

	// �����Լ� override �Ҷ� "��ȯ Ÿ��" �����Ҽ� �ֽ��ϴ�.
	// ��, ��Ӱ����� Ÿ�� ������ �����մϴ�.
	// clone()�� ���� Shape* ��ȯ�ε�, �Ʒ� ó�� Rect* �� �ص� �˴ϴ�.
	Rect* clone() override
	{
		Rect* p = new Rect(*this);
		return p;
	}
};
// Rect* r1 = new Rect;
// 
// Shape* r2 = r1->clone(); // ok
// r2->Rect_��_�����Ǹ���Լ�(); // error
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
			std::cout << "�� ��° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());

		}
	}
}

