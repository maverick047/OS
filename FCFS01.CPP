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

2) Priority scheduling

#include <stdio.h>
#include <conio.h>

void main() {
    int nop, t, wt[10], twt, tat[10], ttat, i, j, p[10], b[10], tmp;
    float awt, atat;
    clrscr();
    awt = 0.0;
    atat = 0.0;
    printf("Enter the number of processes:");
    scanf("%d", &nop);
    for (i = 0; i < nop; i++) {
        printf("Enter the burst time of Process %d:", i);
        scanf("%d", &b[i]);
        printf("Enter the priority number of Process %d:", i);
        scanf("%d", &p[i]);
    }

    // Sorting processes based on priority
    for (i = 0; i < nop; i++) {
        for (j = i + 1; j < nop; j++) {
            if (p[i] > p[j]) {
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = b[0];
    twt = wt[0];
    ttat = tat[0];

    // Calculating waiting times and turnaround times
    for (i = 1; i < nop; i++) {
        wt[i] = wt[i - 1] + b[i - 1];
        tat[i] = wt[i] + b[i];
        twt += wt[i];
        ttat += tat[i];
    }

    awt = (float)twt / nop;
    atat = (float)ttat / nop;

    // Displaying results
    printf("Process No:\tPriority:\tBurst Time:\tWaiting Time\tTurnaround Time:\n");
    for (i = 0; i < nop; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, p[i], b[i], wt[i], tat[i]);

    printf("Total Turnaround Time:%d\n", ttat);
    printf("Total Waiting Time:%d\n", twt);
    printf("Average Waiting Time:%f\n", awt);
    printf("Average Turnaround Time:%f\n", atat);
    getch();
}


