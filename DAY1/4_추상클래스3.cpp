#include <iostream>



// 카메라를 먼저 만들지 말고 카메라와 사용자간에 지켜야 하는 규칙을 먼저 설계한다.

// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.
//      => 의도 : 모든 카메라에는 "Take()" 라는 이름의 함수 가 있어야한다.
class ICamera
{
public:
	virtual void Take() = 0;
};

// 실제 카메라는 아직 없지만, 규칙이 있다.
// 카메라 사용자는 규칙 대로만 사용하면 된다.
class People
{
public:
	void UseCamera(ICamera* p) { p->Take(); }
};

// 이제, 모든 카메라는 규칙대로 만들어야 합니다.
// 규칙 : ICamera로 부터 파생되어야 한다.
class Camera : public ICamera
{
public:
	void Take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take HD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hdc;
	p.UseCamera(&hdc); // ??


}





