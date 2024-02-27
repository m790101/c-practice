
// g++ -std=c++11 playground.cpp -o playground

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <random>
#include <string>
class Archer
{
protected:
    int maxHealth;
    int range;
    int damage;
    std::string name = "archer";
    // int attackSpeed;
public:
    Archer(int maxHealth, int range, int damage)
    {
        this->maxHealth = maxHealth;
        this->range = range;
        this->damage = damage;
    }

    void getDetails()
    {
        std::cout << "maxHealth: " << maxHealth << std::endl;
        std::cout << "range: " << range << std::endl;
        std::cout << "damage: " << damage << std::endl;
    }

    void attack()
    {

        std::random_device rd;  // a seed source for the random number engine
        std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> distrib(0, damage);
      
        std::cout << name <<" Attacking" << std::endl;
        int factor = distrib(gen);
        std::cout << "enemy got " << damage - factor << " damage" << std::endl;
    }
};


class ChineseArcher : public Archer{
    public:

    // ChineseArcher():
    ChineseArcher(int maxHealth, int range, int damage):Archer(maxHealth, range, damage){
        name = "ChineseArcher"; // Setting name in the derived class
    }
};

int main()
{
    std::vector<int> foo = {1, 3};
    Archer archer1 = Archer(100, 10, 20);
    archer1.attack();

    ChineseArcher archer2 = ChineseArcher(50, 8, 7);
    archer2.attack();
    return 0;
}
