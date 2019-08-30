#include <iostream>
#include <string>
#include <ctime>
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
        void coyote();

    private:
        //Dog m_dogs[3];
        int m_numDogs;
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

void Game::coyote()
{   
     cout << "You encounter an coyote. Oof!" << endl;
        int fate = rand() %10;
        cout << fate << endl;
        if (fate <= 5){
            cout << "Your dog ate that hoe like a Big Mac" << endl;
        }
        else{
            cout << "The coyote ate your dog like a Quarter Pounder With Cheese" << endl;
        }

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

int main()
{
    srand(time(NULL));
    Game g1;
    g1.coyote();
    return 0;
}