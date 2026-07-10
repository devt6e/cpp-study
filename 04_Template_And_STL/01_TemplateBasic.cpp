//템플릿 기본
#include <iostream>

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}


template <typename F>
class Box
{
public:
    Box(F value) : data(value) {}
    F GetValue() { return data; }
private:
    F data;
};

int main()
{
    int a = 10, b = 20;
    std::cout << Max(a,b) << std::endl;
    std::cout << Max(3.4, 5.6) << std::endl;

    Box<int> intBox(10);
    Box<std::string> strBox("hello");

    std::cout << intBox.GetValue() << std::endl;
    std::cout << strBox.GetValue() << std::endl;

    return 0;
}