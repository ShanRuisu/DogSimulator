# DogSimulator

**Created by:**</br>
*Shawn Lewis (shawnmaslewis@gmail.com)*</br>
*Nicholas Yamamoto*</br>
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
    * Day: This variable tracks the number of days the player has had at least one dog alive.
    * Dog List: This linked list holds all dogs currently alive within the game.