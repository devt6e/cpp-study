#include <iostream>

class Enemy
{
public:
    virtual void Attack() {std::cout<< "generic attack" <<std::endl;}
    virtual ~Enemy() {}
};

class Dragon : public Enemy
{
public:
    void Attack() override {std::cout << "fire breath" << std::endl;}
};

int main()
{
    Enemy* e = new Dragon();
    e->Attack();

    return 0;
}