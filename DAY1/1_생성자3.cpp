// protected 생성자의 의미 : 자신의 객체는 생성할수 없지만(추상적 존재)
//			파생 클래스의 객체는 생성할수있다.(구체적 존재(concrete))

class Animal
{
protected:    
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}  // Dog() : Animal() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a; // error
	Dog    d; // ok
}



