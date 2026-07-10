//생성자 오버로딩&초기화리스트
//오버로딩이란 같은 이름의 메서드를 여러 방식(매개변수의 차이)으로 구현하는 것이다.
//초기화 리스트가 권장되는 이유는 잘 모르겠다..
//초기화 리스트를 통해 멤버를 초기화 하는 것은 생성과 초기화를 동시에 진행한다.
//하지만 함수구현을 통한 생성자는 멤버변수 생성 -> 대입 이기에 한 번 더 일한다.
//중요한 점은 const나 참조 형태의 멤버는 초기화 하면 변경될 수 없으므로 초기화 리스트로만 초기화 가능하다.

#include <iostream>

class Rectangle
{
public:
    // Rectangle(int w, int h){
    //     width = w;
    //     height = h;
    // }

    Rectangle(int w, int h) : width(w), height(h) {};

private:
    int width;
    int height;
};

int main()
{
    return 0;
}