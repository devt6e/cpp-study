#include <iostream>

int main()
{
    int a = 63;
    // int& aRefLegacy;
    int& aRef = a;
    int b = 763;

    std::cout << "a : " << a << std::endl;
    std::cout << "aRef : " << aRef << std::endl;
    
    aRef = b;

    std::cout << "a : " << a << std::endl;
    std::cout << "aRef : " << aRef << std::endl;

/*
결과 예측
a : 63
aRef : a의 주소값
a : 763
aRef : a의 주소값

실제 결과
a : 63
aRef : 63
a : 763
aRef : 736
-> ????? 왜 주소값이 아니지?
*/

    return 0;
}