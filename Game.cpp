#include <iostream>
#include <string>
#include <ctime>
#include <vector>
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

        // Copy Constructor
        Dog(Dog copy);

        // Mutator Functions
        void incHealth(int amt);
        void decHealth(int amt);
        void kill();

        // Accessor Functions
        string name();
        int age();
        int health();

    private:
        string m_name;
        int m_age;
        int m_health = 100;
        
};

class Game
{
    public:
        void takeTurn();

    private:
        vector<Dog> m_dogs;
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

Dog::Dog(Dog copy)
{
    m_name = copy.m_name;
    m_age = copy.m_age;
    m_health = copy.m_health;
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

void Dog::kill()
{
    m_health = 0;
}

// Game Implementation

// TODO: Will implement later
/*
void Game::takeTurn()
{
    // Keep taking turns while there are dogs are still alive
    while (m_numDog > 0)
    {
        // Generate a random event for each dog
        vector<Dog>::iterator ptr;

        for (ptr = m_Dogs.begin(); ptr != m_Dogs.end(); ptr++)
        {
            int num = rand() % 5;

            // Call event depending on the number
            switch (num)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                default:
            }

            Dog* dog = *ptr;
            if (dog->health() == 0)
            {

            }
        }
    }
}
*/

int main()
{
    srand(time(NULL));

    return 0;
}