#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

class Player
{
    public:
        Player();
        
        // Mutator Functions
        void incMoney(int amt);
        bool decMoney(int amt);
        
        // Accessor Functions
        int money();
    
    private:
        int m_money;

};

class Dog
{
    public:

        Dog(string name, int age);

        // Mutator Functions
        void incHealth(int amt);
        void decHealth(int amt);
        void feed();
        void getHungry();
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
        int m_health;
        bool m_hunger;
        bool m_sick;
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
        int m_day;
};

// Player Implementation

Player::Player()
{
    m_money = 300;
}

// Increase the player's budget.
void Player::incMoney(int amt)
{
    m_money += amt;
    return;
}

// Decrease the player's budget.
bool Player::decMoney(int amt)
{
    // Verify that player can afford to pay
    if (m_money - amt < 0)
    {
        cout << "You cannot pay for this!" << endl;
        return false;
    }

    m_money -= amt;

    return true;
}

// Return the player's budget.
int Player::money()
{
    return m_money;
}

// Dog Implementation

// Dog constructor
Dog::Dog(string name, int age)
{
    m_name = name;
    m_age = age;        
    m_health = 100;
    m_hunger = false;
    m_sick = false;
}

// Increase the health of the dog
void Dog::incHealth(int amt)
{
    m_health += amt;

    // The dog's health cannot exceed 100
    if (m_health > 100)
    {
        m_health = 100;
    }

    return;
}

// Decrease the health of the dog
void Dog::decHealth(int amt)
{
    m_health -= amt;
    return;
}

// Feed the dog
void Dog::feed()
{
    incHealth(25);
    m_hunger = false;
}

// Dog gets hungry
void Dog::getHungry()
{
    m_hunger = true;
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
    m_day = 0;

    cout << endl << "In this game, you will have three dogs. Try not to let them die." << endl << endl;
    
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
    // Keep taking turns while there are dogs are still alive
    while (m_dogs.size() > 0)
    {
        // Generate a random event for each dog
        vector<Dog>::iterator dog;

        for (dog = m_dogs.begin(); dog != m_dogs.end(); dog++)
        {
            // Dog dog = *ptr;

            int num = rand() % 8184;

            millionChance();
            endGame();
            break;
            /*
            // Call event depending on the number
            switch (num)
            {
                // Coyote attack
                case 1:
                    // coyote(dog);
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
            */
            
            // Dog gets hungry every three days
            if (!(m_day % 3))
            {
                dog->getHungry();
            }

            string choice;

            // Feed the dog if needed
            if (dog->hunger())
            {
                cout << dog->name() << " is hungry. Would you like to feed " << dog->name() << "for $25? (y/n) ";
                getline(cin, choice);

                // Convert the string to lowercase
                for (int i = 0; i < choice.size(); i++)
                {
                    tolower(choice[i]);
                }

                if (choice.compare("y"))
                {
                    // If the player cannot afford to feed the dog, decrease dog's health
                    if (!m_player.decMoney(25))
                    {
                        dog->decHealth(25);
                    }
                    else
                    {
                        dog->feed();
                    }
                }
                else if (choice.compare("n"))
                {
                    dog->decHealth(25);
                }
                else
                {
                    cout << "Please enter either y or n." << endl;
                }
            }

            // Remove dead dogs
            if (dog->health() == 0)
            {
                m_dogs.erase(dog);
                dog--;
            }
        }

        // Print the status of the remaining dogs
        printStatus();

        cout << "Press enter to continue." << endl;
        cin.ignore(1000,'\n');
        m_day++;
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


void CurrencyConverter();

void Game::millionChance()
{
    CurrencyConverter();
}

// End the game, regardless of conditions within the game
void Game::endGame()
{
    // Kill all the dogs
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
    cout << "It is day " << m_day << "." << endl;
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

// Converts your currency
void CurrencyConverter()
{
    // Exchange rate matrix
    // As of 30 August 2019
    float rate[6][6] =
    {
        1, 0.91, 106.3, 1210.151, 20, 448,
        1.09, 1, 117.03, 1332.83, 22.1, 493.32,
        0.009407, 0.008544, 1, 11.39, .19, 4.20,
        0.00082634, 0.00075028, 0.08779, 1, 0.017, 0.37,
        0.05, 0.04524, 5.263, 58.823, 1, 22.33,
        0.002232, 0.002027, 0.2380, 2.702, 0.0447, 1 
    };

    string money[6] = { "USD", "Euros", "Yen", "Won", "Pesos", "Francs" };

    int choice1;
    int choice2;

    float amt1;
    float amt2;
    
    cout << "LMAO you got the one in a million chance, what a loser. You're now in a currency converter." << endl;
    cout << "Which currency are you starting in? \n (1) US Dollars \n (2) Euros \n (3) Yen \n (4) Won \n (5) Pesos \n (6) Francs \n";
    cin >> choice1;
    choice1--;

    cout << "Which currency would you like to convert to?" << endl;
    cout << " (1) US Dollars \n (2) Euros \n (3) Yen \n (4) Won \n (5) Pesos \n (6) Francs \n";
    cin >> choice2;
    choice2--;

    cout << "Please enter how much money you are converting: ";
    cin >> amt1;

    amt2 = amt1 * rate[choice1][choice2];

    cout << amt1 << " " << money[choice1] << " is " << amt2 << " " << money[choice2] << "." << endl << endl;
}

int main()
{
    srand(time(NULL));

    Game start;
    start.takeTurn();

    cout << "Thanks for playing!" << endl;

    return 0;
}