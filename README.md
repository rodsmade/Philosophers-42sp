# Philosophers-42sp
A study on Multithreading in C!

## The dining philosophers problem
Originally formulated in 1965 by Edsger Dijkstra, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

In this project, the concept of **execution threads** is introduced so that students can write a program that models the famous dining problem through lines of code. The rules are simple:

1. There is an **n** number of philosophers having a synchronised spaghetti meal at a round table!
2. Each philosopher brought one for to the gathering.
3. However, each of them needs 2 forks to eat. The forks are thus shared so that some will have to wait while others have their meals.
4. After eating their meal, each philosopher lets go of the forks used for the meal (so others can have their go), and proceeds to take a nap.
5. Upon awakening, each philosopher will resume eating their meal if forks are available, otherwise they'll wait patiently for their turn.

But **wait**! There's a catch! The philosophers have a very short **lifespan**. It resets every time they start a meal - hurray! - but oh!, does it ever run down! If a philosopher's lifespan is up before they get to start another meal, it's time to kick the bucket!

Students are invited to use their knowledge on multithreading to write an algorithm that best tries and keep everyone alive.

## Running the simulation
The goal of this project is to write a simulation of a certain number of philosophers having a dinner in the aforementioned terms, given the time parameters for each action in a philosopher's lifetime:
```
.philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
| arg | 
`time_to_die`
`time_to_eat`
`time_to_sleep`
`number_of_times_each_philosopher_must_eat` (optional)

## Final note
If you're a 42 student struggling to understand this project, I got your back! Please refer to this Notion page that I wrote covering the general concepts related to this project! It's in Portuguese :cactus:

> [Acelera — Philosophers](https://rodsmade.notion.site/Acelera-Philosophers-a82a52edabe24ea4a382393fae6c4531)
