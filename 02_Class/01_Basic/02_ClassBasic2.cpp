//복사 생성자가 필요한 이유
//기본 복사 생성자의 경우 메모리의 새 공간에 데이터를 복사하는게 아니라
//같은 메모리 공간을 가리키도록 한다.
//이는 댕글링 레퍼런스 문제를 유발한다.

//댕글링 레퍼런스 보다는 이중 해제 문제가 발생한다.
// 

#include <iostream>

class Buffer
{
public:
    Buffer(int size){
        data = new int[size];
        length = size;
    }

    //해결법 -- 깊은 복사
    Buffer(const Buffer& other){
        length = other.length;
        data = new int[length];
        for(int i = 0; i < length; i++)
            data[i] = other.data[i];
    }
    //~해결법 -- 깊은 복사
    ~Buffer() {
        std::cout << "delete : " << data << std::endl;
        delete[] data;
    }
    void print() {
        std::cout << data << std::endl;
    }

private:
    int* data;
    int length;
};

int main()
{
    Buffer a(10);
    Buffer b = a;

    a.print();
    b.print();

    return 0;
}