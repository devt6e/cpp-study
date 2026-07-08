//앞에서 참조에 대한 기본적인 공부를 했으니 활용해보자 !

#include <iostream>

// void SwapLegacy(int& ra, int& rb)
// {
//     int& temp = ra;
//     ra = rb;
//     rb = temp;
// }
void Swap(int& ra, int& rb)
{
    int temp = ra;
    ra = rb;
    rb = temp;
}


int main()
{
    int a = 763, b = 10;
    int &aRef = a, &bRef = b;
    std::cout << "Before Swap A, B : " << a << ", " << b << std::endl;
    Swap(aRef, bRef);
    std::cout << "After Swap A, B : " << a << ", " << b << std::endl;
   
    return 0;
}

/*


SwapLegacy 사용
예측 결과
763, 10
10, 763

실행 결과
763, 10
10, 10

*/