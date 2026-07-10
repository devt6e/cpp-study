#include <iostream>

using namespace std;

class Buffer
{
public:
	Buffer(int size){
		data = new int[size];
		length = size;
	}
	~Buffer() {
        std::cout << "delete : " << data << std::endl;
		delete[] data;
	}
    void Display() {
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

    a.Display();
    b.Display();
}