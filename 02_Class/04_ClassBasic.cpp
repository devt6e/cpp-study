//this 포인터 : this 포인터는 지금 현재 코드가 실행되는 객체를 가리키는 포인터이다.

#include <iostream>

class Point
{
public:
    Point(int x, int y) {this->x = x; this->y = y;}
    void Display() { std::cout << x << ", " << y << std::endl; }
private:
    int x;
    int y;
};

int main()
{
    Point pt(1,2);
    pt.Display();
}