#include <iostream>
#include <string>
#include <ctime>
#include <list>
using namespace std;

// Player Class
class Player
{
    public:
        Player();
        
        // Mutator Functions
        void incMoney(int amt);
        bool decMoney(int amt);
        
        // Accessor Functions
        const int money();
        const char job();
    
    private:
        int m_money;
        char m_job;

};

// Dog Class
class Dog
{
    public:
        Dog(string name, int age);

        // Mutator Functions
        void incHealth(int amt);
        void decHealth(int amt);
        void getOlder();
        void feed();
        void getHungry();
        void heal();
        void getSick();

        // Accessor Functions
        const string name();
        const int age();
        const int health();
        const bool hunger();
        const bool sick();

    private:
        string m_name;
        int m_age;
        int m_health;
        bool m_hunger;
        bool m_sick;
};

// Game Class
class Game
{
    public:
        Game();
        
        void gamePlay();
        void takeTurn();

        // Random Events
        void coyote(Dog &dog);
        void atf(Dog &dog);
        void CurrencyConverter(const Dog dog);

        // Auxiliary Functions
        void endGame();
        const void printStatus();

        // Accessor Functions
        const int day();

    private:
        list<Dog> m_dogs;
        Player m_player;
        int m_day;
};

// Player Class Implementation

// Player Constructor
Player::Player()
{
    m_money = 300;

    // Randomly determine the player's income
    int salary = rand() % 100;

    if (salary <= 4)
    {
        m_job = 'B';                // Bottlecap Salesman job
    }
    else if (salary <= 14)
    {
        m_job = 'D';                // Bus Driver job
    }
    else if (salary <= 84)
    {
        m_job = 'M';                // McDonald's Worker job
    }
    else if (salary <= 94)
    {
        m_job = 'G';                // George Bush's Toilet Seat Warmer job
    }
    else
    {
        m_job = 'T';                // High Quality Twitch Streamer but not as good as Aespirin job
    }
}

// Increase the player's budget by amt
void Player::incMoney(int amt)
{
    m_money += amt;
    return;
}

// Decrease the player's budget by amt
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

// Return the player's budget
const int Player::money()
{
    return m_money;
}

// Return the player's job
const char Player::job()
{
    return m_job;
}

// Dog Class Implementation

// Dog constructor
Dog::Dog(string name, int age)
{
    m_name = name;
    m_age = age;        
    m_health = 100;
    m_hunger = false;
    m_sick = false;
}

// Increase the health of the dog by amt
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

// Decrease the health of the dog by amt
void Dog::decHealth(int amt)
{
    m_health -= amt;
    return;
}

// Dog ages one year
void Dog::getOlder()
{
    m_age++;
    return;
}

// Feed the dog
void Dog::feed()
{
    incHealth(10);
    m_hunger = false;
    return;
}

// Set m_hunger to true
void Dog::getHungry()
{
    m_hunger = true;
    return;
}

// Set m_sick to false
void Dog::heal()
{
    m_sick = false;
    return;
}

// Set m_sick to true
void Dog::getSick()
{
    m_sick = true;
    return;
}

// Return the dog's name
const string Dog::name()
{
    return m_name;
}

// Return the dog's age
const int Dog::age()
{
    return m_age;
}

// Return the dog's health
const int Dog::health()
{
    return m_health;
}

// Return if the dog is hungry
const bool Dog::hunger()
{
    return m_hunger;
}

// Return if the dog is sick
const bool Dog::sick()
{
    return m_sick;
}

// Game Class Implementation

// Game constructor
Game::Game()
{
    m_day = 0;

    cout << endl << "In this game, you will have some dogs. Try not to let them die." << endl << endl;
    
    // Create the dogs.
    for (;;)
    {
        string newName;
        int newAge;
        
        // Name your dog
        cout << "What would you like to name your new dog? Enter '-1' to exit. ";
        getline(cin, newName);

        // Verify that at least dog is created
        if (newName == "-1")
        {
            if (m_dogs.size() == 0)
            {
                cout << "Please make at least one dog." << endl;
                continue;
            }
            else
            {
                break;
            }
        }

        // Specify your dog's age
        for(;;)
        {
            cout << "How old is your dog? ";
            cin >> newAge;
            cin.ignore(1000, '\n');

            if (newAge < 0 || newAge > 16)
            {
                cout << "Please enter a valid age between 0 and 16 (inclusive)." << endl;
            }
            else
            {
                break;
            }
        }

        // Create a new dog object
        Dog newDog(newName, newAge);
        m_dogs.push_back(newDog);
    }

    // Print the starting status of each dog.
    printStatus();

    // Print the player's job.
    switch(m_player.job())
    {
        case 'B':
            cout << "You are a Bottlecap Salesman.\n";
            break;
        case 'D':
            cout << "You are a Bus Driver. Thank you.\n";
            break;
        case 'M':
            cout << "You are a McDonald's Worker. I would like a Happy Meal please.\n";
            break;
        case 'G':
            cout << "You are George Bush's Toiler Seat Warmer. I'm sorry.\n";
            break;
        case 'T':
            cout << "You are High Quality Twitch Streamer. Support me on Patreon.\n";
            break;
        default:
            cout << "This isn't a valid job.\n";                                                // Catching any unexpected values
            break;
    }

    cout << "Press enter to continue." << endl;
    cin.ignore(1000,'\n');

    // Start the game on day 1.
    m_day++;

}

void Game::gamePlay()
{
    for(;;)
    {
        this->takeTurn();

        // End the game if there are no more dogs alive
        if (m_dogs.size() == 0)
            break;

        // Print the status of the remaining dogs
        printStatus();

        cout << "Press enter to continue." << endl;
        cin.ignore(1000,'\n');

        // Increment and the following days
        m_day++;
    }
}

// Determines event for each dog on each turn
void Game::takeTurn()
{
    cout << endl;

    // Keep taking turns while there are dogs are still alive
    list<Dog>::iterator ptr;

    for (ptr = m_dogs.begin(); ptr != m_dogs.end(); ptr++)
    {
        int chance1 = rand() % 3;
    
        // Call event depending on the number
        switch (chance1)
        {
            case 0:
                coyote(*ptr);                     // Coyote attack
                break;
            case 1:
                atf(*ptr);                        // ATF arrives at your front door
                break;
            case 2:
                ptr->getSick();                   // Dog gets sick
                break;
            default:
            {
                int chance2 = rand() % 1000;

                switch (chance2)
                {
                    case 1:
                        CurrencyConverter(*ptr);     // Currency Calculator
                        break;
                    default:
                        cout << "Nothing happened on this day." << endl;
                        break;
                }
            }
        }

        // Decrease dog's health for every day it is sick
        if (ptr->sick())
        {
            // Keeping prompting for input until a valid response is given
            do
            {
                string input;
                cout << ptr->name() << " is sick. Would you like to heal " << ptr->name() << " for $30 (y/n)? ";
                getline(cin, input);

                // Convert input to lowercase
                tolower(input[0]);

                if (input[0] == 'y')
                {
                    // If player cannot afford to treat the dog, decrease the dog's health
                    if (m_player.decMoney(30))
                    {
                        ptr->decHealth(35);
                        break;
                    }
                    else
                    {
                        ptr->heal();
                        break;
                    }
                }
                else if (input[0] == 'n')
                {
                    ptr->heal();
                    break;
                }
                else
                {
                    cout << "Please enter either 'y' or 'n'." << endl << endl;
                }
            } while (0 == 0);
        }

        // Dog gets hungry every three days
        if (!(m_day % 3) && ptr->health() > 0 && m_day != 0)
            ptr->getHungry();

        // Feed the dog if needed
        if (ptr->hunger() && ptr->health() > 0)
        {
            // Keeping prompting for input until a valid response is given
            do
            {   
                string choice;        
                cout << ptr->name() << " is hungry. Would you like to feed " << ptr->name() << " for $25? (y/n) ";
                getline(cin, choice);

                // Convert choice to lowercase
                tolower(choice[0]);
        
                if (choice[0] == 'y')
                {
                    // If the player cannot afford to feed the dog, decrease dog's health
                    if (!m_player.decMoney(25))
                    {
                        ptr->decHealth(25);
                        break;
                    }
                    else
                    {
                        ptr->feed();
                        break;
                    }
                }
                else if (choice[0] == 'n')
                {
                    ptr->decHealth(25);
                    break;
                }
                else
                {
                    cout << "Please enter either y or n." << endl << endl;
                }
            } while (0 == 0);
        }

        // Player gets paid every 7 days
        if (!(m_day % 7))
        {
            char job = m_player.job();

            // Player is paid by what job he/she has.
            switch(job)
            {
                case 'B':
                    m_player.incMoney(10);
                    break;
                case 'D':
                    m_player.incMoney(50);
                    break;
                case 'M':
                    m_player.incMoney(120);
                    break;
                case 'G':
                    m_player.incMoney(500);
                    break;
                case 'T':
                    m_player.incMoney(800);
                    break;
                default:
                    cout << "Bye.\n";
                    break;
            }
        }

        // Dogs age every 15 days
        if (!(m_day % 15) && ptr->health() > 0 && m_day != 0)
            ptr->getOlder();

        // Dogs die after reaching age 17
        if (ptr->age() >= 17 && ptr->health() > 0)
            ptr->decHealth(100);
        
        // Remove dead dogs
        if (ptr->health() <= 0)
        {
            cout << ptr->name() << " has died." << endl << endl;
            m_dogs.erase(ptr);
            ptr--;
        }
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
        cout << dog.name() << " ate that hoe like a Big Mac." << endl << endl;
    }
    else
    {
        cout << "The coyote ate " << dog.name() << " like a Quarter Pounder With Cheese." << endl << endl;
        dog.decHealth(100);
    }

    return;
}

// ATF shoots your dog
void Game::atf(Dog &dog)
{
    cout << "The ATF are at your front door!" << endl;

    int death = rand() % 10;

    // The ATF has a high chance to kill your dog
    if (death < 9)
    {
        cout << "The ATF shot your dog!" << endl << endl;
        dog.decHealth(100);
    }
    else
    {
        cout << "The ATF didn't see your dog." << endl << endl;
    }

    return;
}

// Converts your currency
void Game::CurrencyConverter(Dog dog)
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
    
    cout << "LMAO " << dog.name() << " got the one in a million chance, what a loser. You're now in a currency converter." << endl;
    cout << "Which currency are you starting in? \n (1) US Dollars \n (2) Euros \n (3) Yen \n (4) Won \n (5) Pesos \n (6) Francs \n";
    
    for(;;)
    {
        cin >> choice1;

        // Verify that the choice entered is valid
        if (choice1 < 1 || choice1 > 6)
        {
            cout << "Please enter a valid number. ";
            continue;
        }
        else
        {
            choice1--;
            break;
        }
    }

    cout << "Which currency would you like to convert to?" << endl;
    cout << " (1) US Dollars \n (2) Euros \n (3) Yen \n (4) Won \n (5) Pesos \n (6) Francs \n";

    for(;;)
    {
        cin >> choice2;

        // Verify that the choice entered is valid
        if (choice2 < 1 || choice2 > 6)
        {
            cout << "Please enter a valid number. ";
            continue;
        }
        else
        {
            choice2--;
            break;
        }
    }

    cout << "Please enter how much money you are converting: ";

    for (;;)
    {
        cin >> amt1;

        // Verify a positive amount is inputted
        if (amt1 <= 0)
        {
            cout << "Please enter a positive amount of money. ";
            continue;
        }
        else
        {
            break;
        }
    }

    amt2 = amt1 * rate[choice1][choice2];

    cout << amt1 << " " << money[choice1] << " is " << amt2 << " " << money[choice2] << "." << endl << endl;
}

// End the game, regardless of conditions within the game
void Game::endGame()
{
    // Kill all the dogs
    list<Dog>::iterator ptr;

    for (ptr = m_dogs.begin(); ptr != m_dogs.end(); ptr++)
        ptr->decHealth(100);
}

// Give feedback to the player on the status of their dogs
const void Game::printStatus()
{
    cout << endl << "It is day " << m_day << "." << endl;
    cout << endl << "Here are your dogs:" << endl << endl;

    // Iterate through the dog vector
    list<Dog>::iterator ptr;
    for (ptr = m_dogs.begin(); ptr != m_dogs.end(); ptr++)
    {
        // Create dog object
        Dog dog = *ptr;

        cout << "Name: " << dog.name() << endl;
        cout << "Age: " << dog.age() << endl;
        cout << "Health: " << dog.health() << endl;

        cout << "Hunger: ";
        if (dog.hunger())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        cout << "Sick: ";
        if (dog.sick())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        cout << endl;
    }

    cout << "You have $" << m_player.money() << "." << endl << endl; 
}

const int Game::day()
{
    return m_day;
}

int main()
{
    srand(time(NULL));

    Game start;
    start.gamePlay();

    cout << "Thanks for playing!" << endl;

    return 0;
}
