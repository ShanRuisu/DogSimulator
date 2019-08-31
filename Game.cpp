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

        // Mutator Functions
        void incHealth(int amt);
        void decHealth(int amt);
        void kill();

        // Accessor Functions
        string name();
        int age();
        int health();
        bool hunger();
        bool sick();

    private:
        string m_name;
        int m_age;
        int m_health = 100;
        bool m_hunger = false;
        bool m_sick = false;
};

class Game
{
    public:

        Game();
        
        void takeTurn();

        // Random Events
        void coyote(Dog &dog);
        void millionChance();

        // Auxiliary Functions
        void endGame();

        // Accessor Functions
        void printStatus();

    private:
        vector<Dog> m_dogs;
        Player m_player;
};

// Player Implementation

// Increase the player's budget.
void Player::incMoney(float amt)
{
    m_money += amt;
    return;
}

// Decrease the player's budget.
void Player::decMoney(float amt)
{
    m_money -= amt;
    return;
}

// Return the player's budget.
float Player::money()
{
    return m_money;
}

// Dog Implementation

// Dog constructor
Dog::Dog(string name, int age)
{
    m_name = name;
    m_age = age;
}

// Increase the health of the dog
void Dog::incHealth(int amt)
{
    m_health += amt;
    return;
}

// Decrease the health of the dog
void Dog::decHealth(int amt)
{
    m_health -= amt;
    return;
}

// Set the dog's health to 0
void Dog::kill()
{
    m_health = 0;
}

// Return the dog's name
string Dog::name()
{
    return m_name;
}

// Return the dog's age
int Dog::age()
{
    return m_age;
}

// Return the dog's health
int Dog::health()
{
    return m_health;
}

// Return if the dog is hungry
bool Dog::hunger()
{
    return m_hunger;
}

// Return if the dog is sick
bool Dog::sick()
{
    return m_sick;
}

// Game Implementation

// Game constructor
Game::Game()
{
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

// Determines event for each dog on each turn
void Game::takeTurn()
{
    int num = 0;

    // Keep taking turns while there are dogs are still alive
    while (m_dogs.size() > 0)
    {
        // Generate a random event for each dog
        vector<Dog>::iterator ptr;

        for (ptr = m_dogs.begin(); ptr != m_dogs.end(); ptr++)
        {
            Dog dog = *ptr;

            int num = rand() % 8184;

            // Call event depending on the number
            switch (num)
            {
                // Coyote attack
                case 1:
                    coyote(dog);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    switch (num)
                    {
                        case 0:
                            millionChance();
                            break;
                        default:
                            break;
                    }
            }

            // Remove dead dogs
            if (dog.health() == 0)
            {
                m_dogs.erase(ptr);
                ptr--;
            }
        }

        // Print the status of the remaining dogs
        // printStatus();

        cout << num << endl;
        num++;
    }
}

// Coyote attacks one of your dogs
void Game::coyote(Dog &dog)
{   
    cout << "You encounter an coyote. Oof!" << endl;
    
    int fate = rand() %10;

    // Determine if the dog or coyote survives the encounter  
    if (fate <= 5)
    {
        cout << dog.name() << " ate that hoe like a Big Mac." << endl;
    }
    else
    {
        cout << "The coyote ate " << dog.name() << " like a Quarter Pounder With Cheese." << endl;
        dog.kill();
    }
}

// TODO: Implement some crazy outcome
void Game::millionChance()
{
    endGame();
}

// End the game, regardless of conditions within the game
void Game::endGame()
{
    vector<Dog>::iterator ptr;

    for (ptr = m_dogs.begin(); ptr != m_dogs.end(); ptr++)
    {
        m_dogs.erase(ptr);
        ptr--;
    }
}

// Give feedback to the player on the status of their dogs
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
    start.takeTurn();

    end:
        cout << "Thanks for playing!" << endl;

    return 0;
}