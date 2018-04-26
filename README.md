# CiggSmokersProblem

Contributors:

Faraz Murtaza	k16-4054
Okesh Kumar	k16-4026
Syed Hamza	k16-4059

# Introduction

The cigarette smokers’ problem is a concurrency problem in Computer Science, originally described in 1971 by Suhas Patil.
In this problem The Agent represents the Operating System and the smokers represent the processes/threads. In this problem, The Agent (Operating System) should allocate resources to smokers (Processes/Threads) and at the same time avoid Deadlock.

Assume a cigarette requires three ingredients to make and smoke: tobacco, paper, and matches. There are three smokers around a table, each of whom has an infinite supply of one of the three ingredients — one smoker has an infinite supply of tobacco, another has paper, and the third has matches.

There is also a non-smoking agent who enables the smokers to make their cigarettes by arbitrarily selecting two of the supplies to place on the table. The smoker who has the third supply should remove the two items from the table, using them (along with their own supply) to make a cigarette, which they smoke for a while. Once the smoker has finished his cigarette, the agent places two new random items on the table. This process continues forever.


# Getting Started

Installaton Procedure:

1. Open up Terminal By pressing ``` Ctrl + Alt + T ```
2. Type ``` sudo apt-get install git ``` to install git on your Linux machine.
3. After the installation is complete, type ``` git clone https://github.com/farazmurtaza/CiggSmokersProblem.git ```
4. Navigate to the target directory through terminal by ``` cd CiggSmokersProblem```
5. Compile the code by typing ``` gcc -o main main.c -lpthread ``` 
6. Execute the compiled program by typing ``` ./main ```

# Explanation

Three semaphores are used to represent the three smokers; the agent increases the appropriate semaphore to signal that an item has been placed on the table. Also, each smoker has an associated semaphore that they use to signal to the agent that they are done smoking (in this case: ``` smokerReady ```); the agent has a semaphore (``` agentReady ```) that waits on each smoker's semaphore to let it know that it can place the new items on the table.

# Glossary

1. Threads:

A thread of execution is the smallest sequence of programmed instructions that can be managed independently by a scheduler, which is typically a part of the operating system. The implementation of threads and processes differs between operating systems, but in most cases a thread is a component of a process. Multiple threads can exist within one process, executing concurrently and sharing resources such as memory, while different processes do not share these resources. In particular, the threads of a process share its executable code and the values of its variables at any given time. 

```
pthread_t: is the data-type for the threads being used that is included in the library pthread.

pthread_create(): is a function used to create threads. It requires four parameters: 
pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);

pthread_join(): is also a function that shall suspend execution of the calling thread until the target thread terminates, unless the target thread has already terminated. This function requires two parameters:
pthread_join(pthread_t thread, void **value_ptr);
```
    
2. Semaphores:
    ``` sem_t ```
    ``` sem_init() ``` 
    
