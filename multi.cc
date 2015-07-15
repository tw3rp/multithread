#include <pthread.h>
#include <iostream>
#include <semaphore.h>
#include <unistd.h>

//global constants
using namespace std;
const int max_thread = 10;
const int counter_up = 100;

//variables

int counter = 0; //counter to be incremented
sem_t semaphore; //global semaphores defined in semaphore.h
pthread_t tid[ max_thread ];  /*array of threads defined in pthread.h*/

//do the folowing up counter everytime the thread gets the resourse.

void *
upcount(void *arg)
{
	int temp;
	//thread number is passed as an argument and this has to be parsed
	int id = (int) arg;
	cout<<"thread "<< id << " is running"<< endl;
	//increment the counter everytime you have the resource that is protect it with a semaphore

	for( int j=0; i<counter_up; j++)
	{
		sem_wait( &semaphore);//wait for the semaphore
		counter++;
		usleep(100);
		sem_post( &semaphore);//signal the semaphore
	}
	cout<< "thread "<< id << " is ending"<<endl;
	return NULL;
}

int main()
{
	int i, no_threads;
	cout<< "enter the number if threads to creat: "<< endl;
	cin<< no_threads;
	if( (no_threads <=0) || (no_threads >= counter_up))
	{
		cout<<"invalid thread count -- setting default"<<endl;
		no_threads=4;
	}
	
	//initialize the mutual exclusion semaphore
	sem_init( &semaphore, 0 ,1);
	//creat no_threads identical threads
	for(i=0; i<no_threads; i++)
	{
		pthread_create( &tid[i], NULL, upcount, (void *) i);
	
	}
	for(i=0;i< no_threads; i++)
	{
		pthread_join( tid[i], NULL;
	}
	cout<<endl<<"Final value of counter: "<<counter;
	cout<< " (should be " <<no_threads*count_up<< " )" << endl;
	return 0;
}


