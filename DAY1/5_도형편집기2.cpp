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
			for (auto p : v) // 여기서 p는 Shape* 인데
				p->draw();   // Shape 에는 draw()가 없습니다.
							// error
		}
	}
}
// 이 코드는 왜 에러일까요 ?
// 어떻게 해결해야 할까요 ?
// 해결책 1. p 를 Rect* 나 Circle* 로 캐스팅 하자
//			=> 코드 작성시 p가 가리키는 곳을 알수 없다.
//          => 물론, dynamic_cast로 조사는 가능하지만.. 좋지 않은 코드
// 
//       2. Shape안에 draw()를 만들자.  ===> 정답!!
