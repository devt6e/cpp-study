//가상 함수를 이해하고 다시 작성해본 코드

#include <iostream>

class Enemy
{
public:
    virtual void Attack() {std::cout<<"Attack!!"<<std::endl;}
private:
    int damage;
};

class Goblin : public Enemy
{
public:
    void Attack() override {std::cout<<"Goblin Swing!!!"<<std::endl;}
private:
    int speed;
};

int main()
{
    Enemy* e = new Goblin();

    e->Attack();
    
    delete e;
    return 0;
}