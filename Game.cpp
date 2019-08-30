#include <iostream>
#include <string>
using namespace std;

class Player
{
    public:
        void incMoney(float amt);
        void decMoney(float amt);
        float budget();
    
    private:
        float money = 300;

};

void Player::incMoney(float amt)
{
    money = money + amt;
    return;
}

void Player::decMoney(float amt)
{
    money = money - amt;
    return;
}

float Player::budget()
{
    return money;
}

int main()
{
    Player Phil;
    cout << Phil.budget() << endl;
    Phil.decMoney(10);
    cout << Phil.budget() << endl;
    Phil.incMoney(50);
    cout << Phil.budget() << endl;
    return 0;
}