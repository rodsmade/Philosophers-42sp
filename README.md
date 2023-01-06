# Philosophers-42sp :spaghetti:
A study on Multithreading in C! No deadlocks and no data races.

![image](https://user-images.githubusercontent.com/49699403/210902076-f5092b2b-fccf-43b7-b8f4-570443beb406.png)


## The dining philosophers problem
Originally formulated in 1965 by Edsger Dijkstra, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

In this project, the concept of **execution threads** is introduced so that students can write a program that models the famous dining problem through lines of code. The rules are simple:

1. There is an **n** number of philosophers having a synchronised spaghetti meal at a round table! :spaghetti:
2. Each philosopher brought one for to the gathering.
3. However, each of them needs 2 forks to eat :fork_and_knife: The forks are thus shared so that some will have to wait while others have their meals.
4. After eating their meal, each philosopher lets go of the forks used for the meal (so others can have their go), and proceeds to take a nap.
5. Upon awakening, each philosopher will resume eating their meal if forks are available, otherwise they'll wait patiently for their turn.

But **wait**! There's a catch! The philosophers have a very short **lifespan**. It resets every time they start a meal - hurray! - but oh!, does it ever run down! If a philosopher's lifespan is up before they get to start another meal, it's time to kick the bucket!

Students are invited to use their knowledge on multithreading to write an algorithm that best tries and keep everyone alive.

## Running the simulation
The goal of this project is to write a simulation of a certain number of philosophers having dinner in the aforementioned terms, given the time parameters for each action in a philosopher's lifetime in miliseconds. For example:

| `./philo` | `2` | `500` | `200` | `100` | `1` |
| :-: | :-: | :-: | :-: | :-: | :-: |
| path to binary | `number_of_philosophers` | `time_to_die` | `time_to_eat` | `time_to_sleep` | `number_of_meals` (optional) |

Shall simulate a dinner of `2` philosophers, each of them with a lifespan of `500 ms`, each of them taking `200 ms` to eat and `100 ms` to nap. The simulation will go on until each philosophers has had at least `1` meals.

The simulation shall produce a log that narrates the activity during dinnertime:

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 2 has taken a fork
200 2 has taken a fork
200 2 is eating
300 1 is thinking
400 2 is sleeping
500 2 is thinking
```

The leading number in every log line represents a timestamp in miliseconds relative to the program starting time.

You can play with the arguments when calling the `philo` program and read through the logs to understand more about the nature of multithreading processing.

## Final note
If you're a 42 student struggling to understand this project, I got your back! Please refer to this Notion page that I wrote covering the general concepts related to this project! It's in Portuguese :cactus:

> [Acelera — Philosophers](https://rodsmade.notion.site/Acelera-Philosophers-a82a52edabe24ea4a382393fae6c4531)
