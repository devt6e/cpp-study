#include <iostream>

int main()
{
    std::cout << "hello cpp" << std::endl;
    int a[5];
    a[0] = 10;
    std::cout << a << std::endl;
    std::cout << &a[1]-1 << std::endl;
    std::cout << *a << std::endl;
    
    return 0;
}  