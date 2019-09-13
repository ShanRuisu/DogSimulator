# DogSimulator

**Created by:**</br>
*Shawn Lewis (shawnmaslewis@gmail.com)*</br>
*Nicholas Yamamoto (nicholas.yamamoto@gmail.com)*</br>
*Thomas Kaneshige (tykaneshige.work@gmail.com)*</br>

Created in August 2019

**This was primairily created to review and to teach basic concepts of C++, such as variables,**
**arrays, if-else statements, functions, and classes (Everything except pointers).**

---

## Overview

**This is just your average everyday dog simulator. No surprises to be found here.**

---

## Game Events

### Normal Events
1. Coyote Attack
    * On any given day, one of your dogs may be attacked by a coyote. However, your dog might be able to 
    overcome the coyote. There is a 60% chance for your dog to kill the coyote, and a 40% chance for your
    dog to be eaten by the coyote.
2. ATF
    * If you're unlucky, the ATF will show up at your front door. And much to your despair, the ATF showing
    up at your front door will almost always (90%) result in the death of one of your dogs. However, rest 
    assured, your dog will have a 10% chance to not be seen by the ATF when they appear.
3. Sickness
    * Your dog on any given day has a random chance to get sick. And since you live in the United States, 
    it costs $30 to procure the medicine your dog needs to get well again. But if you cannot afford (or are
    not willing to pay) for the medicine, your dog will lose 35 health it is left untreated.
1. Nothing Happens
    * There is a chance for simply nothing to happen to your dog. 


### Recurring Events
1. Hunger
    * Every 3 days, your dog will get hungry. Dog food is somewhat expensive, so it will cost you $25
    to feed just one dog. For every day that your dog is left unfed, it will lose 25 health. Upon feeding
    a hungry dog, it will gain 10 health back.


### Rare Events
1. Currency Converter
    * There is a very small chance (Approximately .1% chance) that your game session might execute
    its Currency Converter functionality. Feel free to convert currency between dollars, euros, yen
    won, pesos, and francs to your leisure.

---

## Documentation

* Player Class
  * Properties
    * Money: This is the player's budget for the game. The player will start with $300.
    * Job: This determines the player's income in the game. This will be represented by a char. 
    Here is the listings for the possible jobs:
      * 5%: "Bottlecap Salesman" - $10.
      * 10%: "Bus Driver" - $50.
      * 70%: "McDonald's Worker" - $120.
      * 10%: "George W. Bush's Toilet Seat Warmer" - $500.
      * 5%: "High Quality Twitch Streamer" - $800.

* Dog Class
  * Properties
    * Name
    * Age: All dogs will die after reaching age 17.
    * Health: The maximum health level is 100. If a dog's health hits 0 or goes below 0, the dog
    will die. The dog will start with 100 health at the beginning of the game.
    * Hunger: If the dog is hungry, it will lose 25 health each day it is left unfed. When fed,
    the dog will regain 10 health.
    * Sick: If the dog is sick, it will lose 35 health each day is is left untreated. 

* Game Class
  * Properties
    * Dog List: This linked list holds all dogs currently alive within the game. A linked list was
    used because there will deletions happening at random points in the list. Random access does
    not take place in the game, so the need for a vector is eliminated.
    * Player: This holds the player's stats for the game.
    * Day: This variable tracks the number of days the player has had at least one dog alive.