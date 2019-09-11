# DogSimulator

**Created by:**</br>
*Shawn Lewis (shawnmaslewis@gmail.com)*</br>
*Nicholas Yamamoto (nicholas.yamamoto@gmail.com)*</br>
*Thomas Kaneshige (tykaneshige.work@gmail.com)*</br>

Created in August 2019

---

## Overview

**This is just your average everyday dog simulator. No surprises to be found here.**

---

## Game Events


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
    not take place in the game, so the need for a vector is elimnated.

    * Day: This variable tracks the number of days the player has had at least one dog alive.