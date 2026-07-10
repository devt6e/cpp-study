//이 코드가 컴파일 에러나는 이유를 설명하라
//정의되지 않은 count에 접근하려 했다는 오류가 나온다.
//잘모르겠다.

//일반 멤버 변수는 객체가 생성될 때 메모리에 올라가지만
//모든 객체가 공유하는 변수 static 변수는 아니다.
//따라서 클래스 외부 전역 스코프에서 딱 한 번 더 정의 내려줘야 한다.

#include <iostream>

class Counter
{
public:
    Counter() { count++; }
    static int count;
};

//해결법
int Counter::count = 0;

int main()
{
    Counter cnt;
    std::cout << "hello world" << std::endl;
}