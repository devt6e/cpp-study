//클로드 작성 코드
//prompt : 그럼 컴파일 단계에서 virtual 키워드를 만나면 vtable이란 것을 생성하고 객체마다 자신의 vtable을 가지고 있다는거지? 그리고 부모 포인터에 할당될 때에도 이것을 가지고 있다가 함수를 호출하면 알맞은 vtable을 가진 클래스의 함수를 실행한다는것이고? 그럼 vtable은 어떤 형태로 존재하는거야? 메모리에 존재해? 내가 직접 확인할 수 있는 방법이 있을까?

#include <iostream>

class NoVirtual
{
public:
    void print() { std::cout << "no v" << std::endl; }
};

class HasVirtual
{
public:
    virtual void print() {std::cout << "has v" << std::endl;}
};


int main()
{
    std::cout << sizeof(NoVirtual) << std::endl;
    std::cout << sizeof(HasVirtual) << std::endl;
    return 0;
}