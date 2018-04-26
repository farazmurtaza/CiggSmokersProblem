# CiggSmokersProblem

Contirbutors:

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
4. Navigate to the target directory through terminal by ``` cd CiggSmokersProblem/```
5. Compile the code by typing ``` gcc -o main main.c -lpthread ``` 
6. Execute the compiled program by typing ``` ./main ```

