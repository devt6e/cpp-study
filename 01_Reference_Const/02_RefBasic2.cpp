//01_RefBasic 에서 레퍼런스 변수의 기본 형태를 알아보았다.
//레퍼런스 변수 자체를 출력하면 참조되는 변수의 값이 그대로 나온다.
//레퍼런스의 레퍼런스는 무엇인가에 대해 생각해보자.
//예측 레퍼런스의 레퍼런스도 원변수의 값이 나오지 않을까 생각한다.

#include <iostream>

int main()
{
    int a = 763;
    int& aRef = a;
    int& aRefRef = aRef;
    int b = 10;
    int c = 100;

    std::cout << "a : " << a << std::endl;
    std::cout << "aRef : " << aRef << std::endl;
    std::cout << "aRefRef : " << aRefRef << std::endl;

    aRef = b;
    std::cout << "a : " << a << std::endl;
    std::cout << "aRef : " << aRef << std::endl;
    std::cout << "aRefRef : " << aRefRef << std::endl;

    aRefRef = c;
    std::cout << "a : " << a << std::endl;
    std::cout << "aRef : " << aRef << std::endl;
    std::cout << "aRefRef : " << aRefRef << std::endl;

    return 0;
}

/*
예측 결과
a : 763
aRef : 763
aRefRef : 763

a : 10
aRef : 10
aRefRef : 10

a : 100
aRef : 100
aRefRef : 100

실행 결과
-> 예측과 동일

결론 : 레퍼런스 변수의 레퍼런스도 원래 변수의 값을 가리킨다? 가진다?
*/