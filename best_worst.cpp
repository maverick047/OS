Here's the full code you provided:

```c
#include <stdio.h>
#include <conio.h>

void main() {
    int f3[20], f2[20], r[20], r1[20], ms, bod, sb[20], nsb[20], nsb1[20], np, sp[20];
    int f[20], i, j, l, k, z[20], s = 0;
    
    clrscr();
    
    printf("Enter the memory size:");
    scanf("%d", &ms);
    
    printf("\nEnter the number of blocks for the division of memory:");
    scanf("%d", &bod);
    
    printf("Enter the size of each block:\n");
    for (i = 1; i <= bod; i++) {
        printf("Block[%d]:", i);
        scanf("%d", &sb[i]);
        f[i] = 1;
        f2[i] = 1;
        f3[i] = 1;
        r[i] = 1;
        r1[i] = 1;
        z[i] = sb[i];
    }
    
    printf("\nEnter the number of processes:");
    scanf("%d", &np);
    
    printf("\nEnter the size of each process:\n");
    for (i = 1; i <= np; i++) {
        printf("Process[%d]:", i);
        scanf("%d", &sp[i]);
    }
    
    printf("\nFIRST FIT");
    printf("\n*********\n");
    
    for (i = 1; i <= np; i++) {
        for (j = 1; j <= bod; j++) {
            if ((sb[j] >= sp[i]) && (f[j] != 0)) {
                printf("\nProcess p[%d] is allocated to Block[%d]", i, j);
                f[j] = 0;
                z[j] = sb[j] - sp[i];
                s++;
                goto l1;
            }
        }
        printf("\nProcess p[%d] cannot be allocated", i);
    l1:
        printf(" ");
    }
    
    printf("\n\nRemaining space left in each block\n");
    printf("**********************************\n");
    
    for (i = 1; i <= bod; i++) {
        printf("\nBlock[%d]: free space = %d", i, z[i]);
    }
    
    printf("\n\nUnallocated Blocks");
    printf("\n******************\n");
    
    for (i = 1; i <= bod; i++) {
        if (f[i] != 0) {
            printf("\nBlock [%d] unallocated", i);
        }
    }
    
    if (s == bod) {
        printf("\nNo Block is left unallocated");
    }
    
    getch();
    clrscr();
    s = 0;
    getch();
    
    printf("\nBEST FIT");
    printf("\n********\n");
    
    for (i = 2; i <= bod; i++) {
        for (j = 1; j < i; j++) {
            if (sb[i] >= sb[j]) {
                r[i]++;
            }
            else {
                r[j]++;
            }
        }
    }
    
    for (i = 1; i <= bod; i++) {
        nsb[r[i]] = sb[i];
        z[r[i]] = sb[i];
    }
    
    for (i = 1; i <= np; i++) {
        for (j = 1; j <= bod; j++) {
            if ((nsb[j] >= sp[i]) && (f2[j] != 0)) {
                for (k = 1; k <= bod; k++) {
                    if (r[k] == j) {
                        l = k;
                    }
                }
                printf("\nProcess p[%d] is allocated to Block[%d]", i, l);
                f2[j] = 0;
                z[j] = nsb[j] - sp[i];
                s++;
                goto l2;
            }
        }
        printf("\nProcess p[%d] cannot be allocated", i);
    l2:
        printf(" ");
    }
    
    printf("\nFree space in each block\n");
    printf("************************\n");
    
    for (i = 1; i <= bod; i++) {
        printf("\nBlock [%d]: free space = %d", i, z[r[i]]);
    }
    
    printf("\n\nUnallocated Blocks");
    printf("\n******************\n");
    
    for (i = 1; i <= bod; i++) {
        if (f2[r[i]] != 0) {
            printf("\nBlock [%d] unallocated", i);
        }
    }
    
    if (s == bod) {
        printf("\nNo Block is left unallocated");
    }
    
    getch();
    clrscr();
    s = 0;
    getch();
    
    printf("\nWORST FIT");
    printf("\n*********\n");
    
    for (i = 2; i <= bod; i++) {
        for (j = 1; j < i; j++) {
            if (sb[i] <= sb[j]) {
                r1[i]++;
            }
            else {
                r1[j]++;
            }
        }
    }
    
    for (i = 1; i <= bod; i++) {
        nsb1[r1[i]] = sb[i];
        z[r1[i]] = sb[i];
    }
    
    for (i = 1; i <= np; i++) {
        for (j = 1; j <= bod; j++) {
            if ((nsb1[j] >= sp[i]) && (f3[j] != 0)) {
                for (k = 1; k <= bod; k++) {
                    if (r1[k] == j) {
                        l = k;
                    }
                }
                printf("\nProcess p[%d] is allocated to Block[%d]", i, l);
                f3[j] = 0;
                z[j] = nsb1[j] - sp[i];
                s++;
                goto l3;
            }
        }
        printf("\nProcess p[%d] cannot be allocated", i);
    l3:
        printf(" ");
    }
    
    printf("\nFree space in each block\n");
    printf("************************\n");
    
    for (i = 1; i <= bod; i++) {
        printf("\nBlock [%d]: free space = %d", i, z[r1[i]]);
    }
    
    printf("\n\nUnallocated Blocks");
    printf("\n******************\n");
    
    for (i = 1; i <= bod; i++) {
        if (f3[r1[i]] != 0) {
            printf("\nBlock [%d] unallocated", i);
        }
    }
    
    if (s == bod) {
        printf("\nNo Block is left unallocated");
    }
    
    getch();
    printf("\n");
}
```

Please note that this code is essentially the same as the one you provided earlier. I have not made any changes to the logic or functionality. It includes First Fit, Best