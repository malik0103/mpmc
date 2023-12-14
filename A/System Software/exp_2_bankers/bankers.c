#include <stdio.h> 
int max[100][100], alloc[100][100], need[100][100], avail[100]; 
int n, r, i, j; 
void input(); 
void show(); 
void cal(); 
int main(){ 
    printf("********** Banker's Algorithm ************\n"); 
    input(); 
    show(); 
    cal(); 
    return 0; 
} 

void input(){ 
    printf("Enter the no of Processes : \t"); 
    scanf("%d", &n); 
    printf("\nEnter the no of resources instances : \t"); 
    scanf("%d", &r); 
    printf("\nEnter the Max Matrix\n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < r; j++) 
            scanf("%d", &max[i][j]); 
    printf("\nEnter the Allocation Matrix\n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < r; j++) 
            scanf("%d", &alloc[i][j]); 
    printf("\nEnter the available Resources\n"); 
    for (j = 0; j < r; j++) 
        scanf("%d", &avail[j]); 
} 

void show(){ 
    printf("Process\t Allocation\t\t Max\t\t Available"); 
    for (i = 0; i < n; i++){ 
        printf("\nP%d\t ", i + 1); 
        for (j = 0; j < r; j++) 
            printf("\t%d ", alloc[i][j]); 
        printf("\t"); 
        for (j = 0; j < r; j++) 
            printf("\t%d ", max[i][j]); 
        printf("\t"); 
        if (i == 0) 
            for (j = 0; j < r; j++) 
                printf("%d ", avail[j]); 
    } 
} 

void cal(){ 
    int finish[100], temp, need[100][100], flag = 1, k, c1 = 0, safe[100]; 
    printf("\nSafe Sequence is:"); 
    for (i = 0; i < n; i++) 
        finish[i] = 0; 
    // find need matrix 
    for (i = 0; i < n; i++) 
        for (j = 0; j < r; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    printf("\n"); 
    while (flag){ 
        flag = 0; 
        for (i = 0; i < n; i++){ 
            int c = 0; 
            for (j = 0; j < r; j++) 
                if ((finish[i] == 0) && (need[i][j] <= avail[j])){ 
                    c++; 
                    if (c == r){ 
                        for (k = 0; k < r; k++){ 
                            avail[k] += alloc[i][j]; 
                            finish[i] = 1; 
                            flag = 1; 
                        } 
                        printf("P%d->", i + 1); 
                        if (finish[i] == 1) 
                            i = n; 
                    } 
                } 
        } 
    } 
    for (i = 0; i < n; i++){ 
        if (finish[i] == 1) 
            c1++; 
        else 
            printf("P%d->", i); 
    } 
    if (c1 == n) 
        printf("\n The system is in safe state"); 
    else{ 
        printf("\n Process are in dead lock"); 
        printf("\n System is in unsafe state");   } 
} 