//CH2-TextRPG 만들다가 생긴 궁금증
//배열을 const int& 형식의 인자로 넘기려고 했는데 안됨
//배열의 이름은 포인터임
//일단 배열을 참조하는 형식은 어떤건지 확인하기
#include <iostream>

void print(const int& a)
{
    std::cout << a << std::endl;
}

void print(const int (&arr)[4])
{
    for(int i = 0; i < 4; i++)
    {
        std::cout << arr[i] << std::endl;

    }
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    int (&refarr)[4] = arr;

    print(arr);

    return 0;
}