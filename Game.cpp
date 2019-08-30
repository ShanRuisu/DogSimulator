#include <iostream>
#include <string>
#include <ctime>
<<<<<<< HEAD
#include <vector>
=======
>>>>>>> upstream/master
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
<<<<<<< HEAD
        Game();
        void takeTurn();

        // Random Events
        void coyote();

        // Accessor Functions
        void printStatus();

    private:
        vector<Dog> m_dogs;
=======
        void coyote();

    private:
        //Dog m_dogs[3];
        int m_numDogs;
>>>>>>> upstream/master
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

<<<<<<< HEAD
=======
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
>>>>>>> upstream/master
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
Game::Game()
{
<<<<<<< HEAD
    cout << endl << "In this game, you will have three dogs. Try not to let them die." << endl;
    
    // Create the dogs.
    for (int i = 0; i < 3; i++)
    {
        string newName;
        int newAge;
        
        // Name your dog
        cout << "What would you like to name your new dog? ";
        getline(cin, newName);

        // Specify their age
        cout << "How old is your dog? ";
        cin >> newAge;
        cin.ignore(1000, '\n');

        // Create a new dog object
        Dog newDog(newName, newAge);
        m_dogs.push_back(newDog);

        cout << endl;
    }

    printStatus();

}

// TODO: Will implement later
/*
void Game::takeTurn()
{
    // Keep taking turns while there are dogs are still alive
    while (m_numDog.size() > 0)
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

void Game::coyote()
{   
    int fate;
    cout << "You encounter an coyote. Oof!" << endl;
    fate = rand() %9;




}

void Game::printStatus()
{
    cout << endl << "Here are your dogs:" << endl << endl;

    // Iterate through the dog vector
    vector<Dog>::iterator ptr;
    for (ptr = m_dogs.begin(); ptr != m_dogs.end(); ptr++)
    {
        // Create dog pointer
        Dog dog = *ptr;

        cout << "Name: " << dog.name() << endl;
        cout << "Age: " << dog.age() << endl;
        cout << "Health: " << dog.health() << endl << endl;
    }
}

int main()
{
    srand(time(NULL));

    Game start;

=======
    srand(time(NULL));
    Game g1;
    g1.coyote();
>>>>>>> upstream/master
    return 0;
}