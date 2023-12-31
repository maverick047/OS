#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int np, nr, r[10], safe[10], ava[10], aval[10], re[10], f[10], i, j, flag, z, index, pid;
int m[10][10], need[10][10], all[10][10];

void resource() {
    printf("\nEnter the number of resources: ");
    scanf("%d", &nr);
    printf("\nEnter the resource instances: \n");
    for (i = 0; i < nr; i++)
        scanf("%d", &r[i]);
}

void allocation() {
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    for (i = 0; i < np; i++) {
        f[i] = 0;
        for (j = 0; j < nr; j++) {
            printf("\nResource %d for process %d: ", j + 1, i + 1);
            scanf("%d", &all[i][j]);
        }
    }
}

void max_request() {
    printf("\nEnter the maximum request for each process: \n");
    for (i = 0; i < np; i++)
        for (j = 0; j < nr; j++)
            scanf("%d", &m[i][j]);

    printf("\nThe Available Matrix\n");
    printf("----------------------\n");
    for (i = 0; i < nr; i++) {
        z = 0;
        for (j = 0; j < np; j++)
            z += all[j][i];
        ava[i] = r[i] - z;
        printf("%d\t", ava[i]);
        aval[i] = ava[i];
    }
}

void calculate_need() {
    printf("\nThe Need Matrix \n");
    printf("-------------------\n");
    for (i = 0; i < np; i++) {
        printf("\n");
        for (j = 0; j < nr; j++) {
            need[i][j] = m[i][j] - all[i][j];
            printf("%d\t", need[i][j]);
        }
    }
    printf("\n\n");
}

void request_resources() {
    flag = 0;
    index = 0;
    printf("\nEnter the requesting process id: ");
    scanf("%d", &pid);
    printf("\nEnter the resource instances required:  \n");
    for (i = 0; i < nr; i++) {
        scanf("%d", &re[i]);
        if (re[i] > m[pid][i])
            flag = 1;
    }
    if (flag == 0) {
        for (i = 0; i < nr; i++)
            need[pid][i] = re[i];
        for (i = 0; i < np; i++) {
            printf("\n");
            for (j = 0; j < nr; j++)
                printf("%d \t", need[i][j]);
        }
    } else {
        printf("\nRequest exceeds maximum request\n");
        exit(0);
    }
}

void display_safe_sequence() {
    printf("The safe sequence is\n");
    for (i = 0; i < np; i++)
        printf("p[%d]\t", safe[i]);
    printf("\n\n");
}

void safety_algorithm() {
    flag = 0;
    i = 0;
    j = 0;
    z = 0;
    index = 0;
    while (1) {
        if (z++ > 2 * np) {
            printf("\nNo safe sequence\n");
            exit(0);
        }
        for (j = 0; j < nr; j++) {
            if (need[i][j] <= ava[j] && f[i] != 1) {
                flag = 0;
            } else {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            f[i] = 1;
            safe[index] = i;
            for (j = 0; j < nr; j++)
                ava[j] += all[i][j];
            index++;
            if (index >= np)
                return;
        }
        i++;
        if (i >= np)
            i = 0;
    }
}

int main() {
    clrscr();
    resource();
    allocation();
    max_request();
    calculate_need();
    safety_algorithm();
    display_safe_sequence();
    
    for (i = 0; i < np; i++) {
        f[i] = 0;
        safe[i] = 0;
    }
    
    request_resources();
    
for (j = 0; j < nr; j++)
        ava[j] = aval[j];
    
    safety_algorithm();
    display_safe_sequence();
    
    return 0;
}

2)producer consumer

    #include <stdio.h>
#include <conio.h>

int main() {
    int s, n, b = 0, p = 0, c = 0;
    clrscr();
    printf("\nProducer and Consumer Problem");
    
    do {
        printf("\nMenu");
        printf("\n1. Producer an item");
        printf("\n2. Consumer an item");
        printf("\n3. Add item to the buffer");
        printf("\n4. Display status");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &s);

        switch (s) {
            case 1:
                p = p + 1;
                printf("\nItem to be produced");
                break;

            case 2:
                if (b != 0) {
                    c = c + 1;
                    b = b - 1;
                    printf("\nItem to be consumed");
                } else {
                    printf("\nThe buffer is empty. Please wait...");
                }
                break;

            case 3:
                if (b < n) {
                    if (p != 0) {
                        b = b + 1;
                        printf("\nItem added to buffer");
                    } else {
                        printf("\nNo items to add...");
                    }
                } else {
                    printf("\nBuffer is full. Please wait.");
                }
                break;

            case 4:
                printf("No. of items produced: %d", p);
                printf("\nNo. of consumed items: %d", c);
                printf("\nNo. of buffered items: %d", b);
                break;

            case 5:
                exit(0);
        }
    } while (s <= 5);

    getch();
    return 0;
}

    
    
