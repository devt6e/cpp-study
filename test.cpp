//그냥 연습장
//궁금했 던 문법을 작성하는 파일

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[2][3] = {{1,2,3}, {4,5,6}};	
    int (*ptr)[3] = arr;

    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[1]);
    printf("%p\n", &arr[0][0]);
    printf("%p\n", &arr[0][1]);
    printf("%p\n", &arr[1][1]);

    //4 5 6 7 8 9 a b c d e 0 
// int arr[2][4] = {{1,2,3,4},{5,6,7,8}};
// int (*ptr)[4] = arr;

// int ar[4] = {1,2,3,4};
// int (*pt)[4] = &ar;

// printf("*ptr : %p\n", *ptr);
// printf("arr : %p\n\n", arr);
// printf("*(ptr+1) : %p\n", *(ptr+1));
// printf("arr+1 : %p\n\n", arr+1);
// printf("*pt : %p\n", *pt);
// printf("ar : %p\n", ar);

    return 0;
}  