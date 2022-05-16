// 1_추상클래스1.cpp - 10page
// 
// 추상클래스 : 순수 가상함수가 한개 이상 있는 클래스
// 특징      : 객체를 만들수 없다.
// 의도      : 특정한(약속된) 함수를 반드시 만들어야 한다고 지시하는 것 
class Shape
{
public:
	virtual void Draw() = 0; // 순수 가상함수(pure virtual function)
							 // 특징 : 구현이 없고, =0 으로 표기 
};
class Rect : public Shape
{
	// Draw()의 구현부를 만들지 않으면 역시 추상 클래스이다.
public:
	void Draw() override {}
};

int main()
{
//	Shape  s; // error
	Shape* p; // ok. 
	Rect  r;  // ok.
}
