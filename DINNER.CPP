#include<stdio.h>
#include<conio.h>
#define LEFT (i+4)%5
#define RIGHT (i+1)%5
#define THINKING 0
#define EATING 1
#define HUNGRY 2

int state[5];
void philoshopher(int);
void take_forks(int);
void put_forks(int);
void test(int);

void main(){
	int i;
	clrscr();
	for(i=0;i<5;i++){
		state[i]=THINKING;
	}
	for(i=0;i<5;i++){
		printf("\nPhilosopher %d is Thinking",i+1);
		philosopher(i);

		
	}
	getch();
}
void philosopher(int i){
	if(state[i]==THINKING){
		take_forks(i);
			if(state[i]==EATING)
				printf("\nPhilosopher %d is Eating.\n",i+1);
			put_forks(i);
	}
}
void take_forks(int i){
	state[i]=HUNGRY;
	printf("Philosopher %d is Hungry and going to take up forks.\n",i+1);
	test(i);
}
void put_forks(int i){
	state[i]=THINKING;
	printf("Philosopher %d has finished eating.\n",i+1);
	test(LEFT);
	test(RIGHT);
}
void test(int i){
	if(state[i]==HUNGRY && state[LEFT]!=EATING  && state[RIGHT]!=EATING){
		state[i]=EATING;
		printf("Phillosopher %d is now eating.\n",i+1);
	}
}