#include <iostream>

class Monster
{
public:
    Monster() { count++; }
    void DisplayMonsterCount() {std::cout << count << std::endl;}

private:
    static int count;
};

int Monster::count = 0;

int main()
{
    Monster mon1;
    mon1.DisplayMonsterCount();
    Monster mon2;
    mon2.DisplayMonsterCount();

    return 0;
}