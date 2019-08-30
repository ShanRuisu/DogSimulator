#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
        
        // Mutator Functions
        void incMoney(float amt);
        void decMoney(float amt);
        
        // Accessor Functions
        float money();
    
    private:
        float m_money = 300;

};

class Dog
{
    public:

        Dog(string name, int age);

        // Mutator Functions
        void incHealth(int amt);
        void decHealth(int amt);

        // Accessor Functions
        string name();
        int age();
        int health();

    private:
        string m_name;
        int m_age;
        int m_health = 100;
        
};

// Player Implementation
void Player::incMoney(float amt)
{
    m_money = m_money + amt;
    return;
}

void Player::decMoney(float amt)
{
    m_money = m_money - amt;
    return;
}

float Player::money()
{
    return m_money;
}

// Dog Implementation
Dog::Dog(string name, int age)
{
    m_name = name;
    m_age = age;
}

void Dog::incHealth(int amt)
{
    m_health += amt;
    return;
}

void Dog::decHealth(int amt)
{
    m_health -= amt;
    return;
}

string Dog::name()
{
    return m_name;
}

int Dog::age()
{
    return m_age;
}

int Dog::health()
{
    return m_health;
}


int main()
{
    Player Phil;
    cout << Phil.money() << endl;
    Phil.decMoney(10);
    cout << Phil.money() << endl;
    Phil.incMoney(50);
    cout << Phil.money() << endl << endl;

    Dog One("Bork", 3);
    cout << One.name() << endl;
    cout << One.age() << endl;
    cout << One.health() << endl;
    
    return 0;
}