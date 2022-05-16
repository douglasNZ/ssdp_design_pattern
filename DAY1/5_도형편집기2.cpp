#include <iostream>
#include <vector>

class Shape
{
};

class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect" << std::endl; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle" << std::endl; }
};

int main()
{
	std::vector<Shape*> v; 

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if      (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto p : v) // ���⼭ p�� Shape* �ε�
				p->draw();   // Shape ���� draw()�� �����ϴ�.
							// error
		}
	}
}
// �� �ڵ�� �� �����ϱ�� ?
// ��� �ذ��ؾ� �ұ�� ?
// �ذ�å 1. p �� Rect* �� Circle* �� ĳ���� ����
//			=> �ڵ� �ۼ��� p�� ����Ű�� ���� �˼� ����.
//          => ����, dynamic_cast�� ����� ����������.. ���� ���� �ڵ�
// 
//       2. Shape�ȿ� draw()�� ������.  ===> ����!!
