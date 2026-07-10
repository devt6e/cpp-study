#include <iostream>

using namespace std;

class Weapon
{
public:
    virtual void Fire() = 0;
};

class Pistol : public Weapon
{
public:
    void Fire() {cout << "틱(pistol)" << endl;}
};

class Shotgun : public Weapon
{
public:
    void Fire() {cout << "빵!!!(shotgun)" << endl;}
};

void GetInputMouseL(Weapon* w)
{
    w->Fire();
}

int main()
{
    // Weapon w; //이유 : 추상 클래스의 객체는 선언할 수 없다. vptr이 구현되지 않은 함수를 방지하기 위함
    Weapon* p = new Pistol();
    Weapon* s = new Shotgun();

    GetInputMouseL(p);
    GetInputMouseL(s);
}
