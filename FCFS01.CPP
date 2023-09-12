#include <stdio.h>
#include <conio.h>

void main(){
	int nop,bt[10],wt[10],tat[10],ttat,i,j,temp,twt;
	float awt,atat;
	clrscr();
	awt=0.0 ;
	atat=0.0 ;
	printf("Enter the no of process :  ");
	scanf("%d",&nop);
	for(i=0; i<nop ; i++)
	{
		printf("Enter the burst Time for the Process %d : ",i);
		scanf("%d", &bt[i]);
	}
	wt[0]=0;
	tat[0]=bt[0];
	ttat=tat[0];
	twt=wt[0];
	for(i=1 ; i < nop; i++){
		wt[i]=bt[i-1]+wt[i-1];
		tat[i]=wt[i]+bt[i];
		ttat+=tat[i];
		twt+=wt[i];
	}
	awt=(float)twt/nop;
	atat=(float)ttat/nop;
	printf("\n Process Id\tBurst Time\tWaiting Time\tTurnAround Time\n");
	for(i=0;i<nop;i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t",i+1,bt[i],wt[i],tat[i]);
	}
	printf("\nTotal Waiting Time:  %d " ,twt);
	printf("\nAverage WT : %f ",awt);
	printf("\nAverage TAT : %f  ",atat);

	getch();
}