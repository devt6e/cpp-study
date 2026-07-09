//다형성을 이해하고 작성한 코드
//다형성에 대한 정리 : https://app.notion.com/p/TIL-10-39818bcf56de80e48ef8ef94e6ccd7af#39818bcf56de802f93a1e5b47164ef0d
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
    void Attack() {std::cout<<"Goblin Swing!!!"<<std::endl;}
private:
    int speed;
};

class Dragon : public Enemy
{
public:
    void Attack() {std::cout<<"Fire Breath!!!"<<std::endl;}
private:
    int heart;
};

void func(Enemy* e)
{
	e->Attack();
}

int main()
{
    Enemy* e = new Goblin();
    Enemy* e2 = new Dragon();

		func(e);
		func(e2);
    
    delete e;
    delete e2;
    return 0;
}