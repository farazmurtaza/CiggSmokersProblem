#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <array>
#include <iostream>

using namespace std;
sem_t semaphoreSmokers[3];
sem_t semaphoreAgents;
int glob=-1;

int semWait[3];

bool allSmoked=false;
sem_t agentReady;
sem_t smokerReady;


int s=1;

string agentsDraw[]={"paper & matches"," paper & tobbaco ","tobaco and matchess"};

int main()
{

    for (int i = 0; i < 3; ++i)
    {
        semWait[i]=7;
    }
	//smoker 1 has tobbaco
	//smoker 2 has matches
	//smoker 3 has paper
    sem_init(&semaphoreSmokers[0],0,0);
    sem_init(&semaphoreSmokers[1],0,0);
    sem_init(&semaphoreSmokers[2],0,0);

    sem_init(&semaphoreAgents,0,1);

    sem_init(&agentReady,0,0);
    sem_init(&smokerReady,0,0);
   


    pthread_t smoker1,smoker2,smoker3,agent1,pusher,agent2,agent3;
    int * at = new int[1];
    at[0]=1;

    int * at1 = new int[1];
    at1[0]=2;

    int * at2 = new int[1];
    at2[0]=3;

    pthread_create(&smoker1, NULL, smoker,at );
	
    pthread_create(&smoker2,NULL,smoker,at1);
    	
    pthread_create(&smoker3,NULL,smoker,at2);

    pthread_create(&agent1,NULL,agent,at);

    pthread_create(&pusher,NULL,func,NULL);

    pthread_join(smoker1,NULL);
    pthread_join(smoker2,NULL);
    pthread_join(smoker3,NULL);


    return 0;
}
