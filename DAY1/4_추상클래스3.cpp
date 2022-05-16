#include <iostream>

// 약한 결합(looselty coupling)
// 하나의 클래스가 다른 클래스 사용시
// 규칙을 담은 인터페이스(추상클래스)를 통해서 사용하는 것

// 확장성 있는 유연한 디자인
// OCP를 만족하는 디자인


// 인터 페이스 : 지켜야 하는 규칙(순수가상함수)만 있는 경우 
// 추상 클래스 : 지켜야 하는 규칙(순수가상함수) + 다른 멤버들도 있는 경우






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

class UHDCamera : public ICamera
{
public:
	void Take() { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.UseCamera(&c);

	HDCamera hdc;
	p.UseCamera(&hdc); 

	UHDCamera uhdc;
	p.UseCamera(&uhdc); 
}





