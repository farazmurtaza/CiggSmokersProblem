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
void *smoker(void *pVoid)
{
    int *semNumber= (int*)(pVoid);

    // i indicates the number of times per thread smoking will be done
    for (int i = 0; i <7; ++i)
    {

        usleep( rand() % 50000 );
        cout<<"Smoker "<<*semNumber<<" waiting for "<<agentsDraw[*semNumber-1]<<" "<<endl;
        s++;
        if ( s>3 )
        sem_post(&smokerReady);

        sem_wait(&semaphoreSmokers[(*semNumber-1)]);
        if ( glob == 0 )
        {

            usleep( rand() % 50000 );
            cout<<"\033[0;35m==> \033[0;33mSmoker1 is making a cigarette\033[0;0m"<<endl;
	    sleep(1);
	    cout<<"\033[0;31mNow Smoking\033[0m \n";
	
            semWait[0]--;
            sem_post(&semaphoreAgents);


        }

        else  if ( glob == 1 )
        {

            usleep(rand()%50000);
            cout<<"\033[0;35m==> \033[0;33mSmoker2 is making a cigarette\033[0;0m"<<endl;
	    sleep(1);
	    cout<<"\033[0;31mNow Smoking\033[0m \n";
	    semWait[1]--;
            sem_post(&semaphoreAgents);

        }
        else if ( glob == 2 )
        {

            usleep(rand()%50000);
            cout<<"\033[0;35m==> \033[0;33mSmoker3 is making a cigarette\033[0;0m"<<endl;
	    sleep(1);
	    cout<<"\033[0;31mNow Smoking\033[0m \n";
	    semWait[2]--;
            sem_post(&semaphoreAgents);

        }

    }
		
    pthread_exit(NULL);

}


void *agent(void *pVoid)
{

    srand(time(NULL));
    int *semNumber= (int*)(pVoid);
    sem_wait(&agentReady);
    for (int i = 0; i < 21; ++i)
    {
	    sem_wait(&semaphoreAgents);

        while(true)
        {

            int randInt=(rand()%3);
                usleep(rand()%4000);
	    if( semWait[0]==0 && semWait[1]==0 && semWait[2]==0 )
            {

                allSmoked = true;
                break;

            }
            else if(semWait[randInt]!=0)
            {	sleep(1);
		cout<<"\n\033[0;37mAgent throw\033[0m "<<agentsDraw[randInt]<<endl;
                glob=randInt;
                sem_post(&semaphoreSmokers[randInt]);
                break;

            }	
	}
    }

}


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
