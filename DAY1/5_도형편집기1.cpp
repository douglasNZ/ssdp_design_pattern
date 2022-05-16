#include <iostream>
#include <vector>

// 1. 모든 도형을 타입으로 설계하면 편리하다.

// 2. 모든 도형의 공통의 기반 클래스가 있다면
//    모든 도형을 하나의 컨테이너에 보관할수 있다.

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
//	std::vector<Rect*> v; // Rect 만 보관 가능한 vector
	std::vector<Shape*> v; // 모든 도형을 보관 가능한 vector!! 핵심!!

}

