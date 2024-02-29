
// g++ -std=c++11 playground.cpp -o playground

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <random>
#include <string>

class Soldier
{
    virtual void attack(Soldier& enemy) = 0;
};

class Archer
{
protected:
    int health;
    int range;
    int damage;
    std::string name = "archer";
    // int attackSpeed;
public:
    Archer(int health, int range, int damage)
    {
        this->health = health;
        this->range = range;
        this->damage = damage;
    }

    void getDetails()
    {
        std::cout << "health: " << health << std::endl;
        std::cout << "range: " << range << std::endl;
        std::cout << "damage: " << damage << std::endl;
    }

    int getHealth()
    {
        return health;
    }

    void attack(Archer &enemy)
    {

        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, damage);
        std::cout << name << " Attacking" << std::endl;
        int factor = distrib(gen);
        std::cout << "enemy got " << damage - factor << " damage" << std::endl;
        enemy.health -= damage - factor;
    }
};

class ChineseArcher : public Archer
{
public:
    // ChineseArcher():
    ChineseArcher(int health, int range, int damage) : Archer(health, range, damage)
    {
        name = "ChineseArcher"; // Setting name in the derived class
    }
};

int main()
{
    int rounds = 0;
    std::vector<int> foo = {1, 3};
    Archer archer1 = Archer(100, 10, 20);
    ChineseArcher archer2 = ChineseArcher(50, 8, 7);

    while (archer2.getHealth() > 0)
    {
        rounds++;
        archer1.attack(archer2);
        if (archer2.getHealth() > 0)
        {
            std::cout << "---------enemy status:-----------" << std::endl;
            std::cout << "remaining health: " <<archer2.getHealth() << std::endl;
        } else {
            std::cout << "enemy is dead" << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "total rounds:" << rounds << std::endl;
    // archer1.attack(archer2);
    // std::cout << "---------enemy status:-----------" << std::endl;
    // //  std::cout << "--------------------" << std::endl;
    // archer2.getDetails();
    // std::cout << std::endl;
    // archer2.attack();
    return 0;
}
