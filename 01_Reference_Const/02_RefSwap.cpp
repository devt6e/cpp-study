//레퍼런스 변수는 주소값을 저장하지 않는다는 것을 01_Refbasic.cpp에서 확인헀다.
//그럼 함수의 인자로 전달하면 어떨지 스왑함수를 통해 알아보자.
#include <iostream>

void Swap(int& ra, int& rb)
{
    int& temp = ra;
    ra = rb;
    rb = temp;
}

int main()
{
    int a = 763, b = 10;
    int& aRef = a, bRef = b;
    std::cout << "Before Swap A, B : " << a << ", " << b << std::endl;
    Swap(aRef, bRef);
    std::cout << "After Swap A, B : " << a << ", " << b << std::endl;
   
    return 0;
}

/*
예측 결과
763, 10
10, 763

실행 결과
763, 10
10, 10

*/