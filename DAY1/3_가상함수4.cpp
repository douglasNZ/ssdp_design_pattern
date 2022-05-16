class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived1 : public Base
{
public:
	// 가상함수 재정의시 실수(오타)가 발생했습니다.
	// => 에러가 아니라, 컴파일러는 새로운 가상함수를 추가했다고 생각하게됩니다.
	// => 버그의 원인..
	virtual void fooo() {}
	virtual void goo(double){}
};
class Derived2 : public Base
{
public:
	// C++11 부터. 위 문제를 해결하기 위해 "override" 키워드가 도입되었습니다.
	// => 해당 함수가 기반 클래스에 없는 경우 "컴파일 에러"
//	virtual void fooo() override {}
//	virtual void goo(double)  override {}

	void foo()    override {}
	void goo(int) override {}
};

int main()
{
	Base* p = new Derived1;
	p->foo();
}





