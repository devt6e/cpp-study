//가상함수를 공부하다보니 왜? 등장했는지가 궁금해졌고
//업캐스트에 대해 알게되었다.
//업캐스트가 다형성의 출발점 같다고 생각해 업캐스트에 대해 알아보자.

#include <iostream>

class Enemy
{
public:
    void Attack() {std::cout<<"Attack!!"<<std::endl;}
private:
    int damage;
};

class Goblin : public Enemy
{
public:
    void Attack() {std::cout<<"Goblin Swing!!!"<<std::endl;}
    void print() {std::cout<<"Hello Goblin"<<std::endl;}
private:
    int speed;
};

int main()
{
    Enemy* e = new Goblin();

    e->Attack();
    // e->print();

    delete e;
    return 0;
}