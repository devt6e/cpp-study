//버추얼 함수를 생성자에서 호출하면 어떻게 되는가?
//(결과) vptr이 아직 

#include <iostream>

class Enemy
{
public:
    Enemy() {Attack();}
    virtual void Attack() { std::cout << "Attack" << std::endl; }

};

class Dragon : public Enemy
{
public:
    void Attack() override { std::cout << "Fire Breath !!" << std::endl; }
private:
    int firelevel;
};

int main()
{
    Dragon d;   //출력 : Attack 

    Enemy* e = new Dragon();

    e-> Attack();
    

    return 0;
}