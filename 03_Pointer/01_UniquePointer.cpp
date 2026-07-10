#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> a = make_shared<int>(10);
    cout << a.use_count() << endl;  //1

    shared_ptr<int> b = a;
    cout << a.use_count() << endl;  //2

    {
        shared_ptr<int> c = a;  
        cout << a.use_count() << endl;  //3
    }

    cout << a.use_count() << endl;  //2

    return 0;
}