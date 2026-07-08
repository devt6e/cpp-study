//복사생성자에 대한 연습
#include <iostream>

using namespace std;

class Buffer
{
public:
	Buffer(int data) :data(data) {}
    Buffer(Buffer& other)
    {
        cout << "I'm Copy Constructor" << endl;
        this->data = other.data;
    }
    void Display() { cout << data << endl; }
private:
	int data;
}; 

int main()
{
	Buffer a(1);
	Buffer b(a);
    
    a.Display();
    b.Display();

	return 0;
	
}