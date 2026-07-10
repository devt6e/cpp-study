#include <iostream>

class Enemy
{
public:
    Enemy(int hp) : health(hp) { std::cout << "i'm base constructor" << std::endl; }
    void TakeDamage(int amount) { health -= amount;}
    ~Enemy() { std::cout << "i'm base destructor " << std::endl; }
private:
    int health;
};

class Goblin : Enemy
{
public:
    Goblin() : Enemy(50) {{ std::cout << "i'm derived constructor" << std::endl; }}
    ~Goblin() { std::cout << "i'm derived destructor " << std::endl; }
};

int main()
{
    Goblin g1;

    return 0;
}