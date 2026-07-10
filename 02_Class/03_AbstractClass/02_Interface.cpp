#include <iostream>

using namespace std;

class Imovable
{
public:
    virtual void Move() = 0;
    virtual ~Imovable() {}
};

class IAttackable
{
public:
    virtual void Attack() = 0;
    virtual ~IAttackable() {}
};

class Player : public Imovable, public IAttackable
{
public:
    void Move() override { cout << "Player Move" << endl; }
    void Attack() override { cout << "Player Attack" << endl; }

};

int main()
{
    Player p;
    p.Attack();
    p.Move();
    Imovable* mp = &p;
    mp->Move();
    // mp->Attack();    //오류
    IAttackable* ap = &p;
    // ap->Move();      //오류
    ap->Attack();

}