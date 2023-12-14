#include <stdio.h> 
#include <stdlib.h> 

struct fcfs{ 
    int pid; 
    int btime; 
    int wtime; 
    int ttime; 
} p[10]; 

int main(){ 
    int i, n; 
    int totwtime = 0, totttime = 0; 
    printf("\n fcfs scheduling...\n"); 
    printf("enter the no of process : "); 
    scanf("%d", &n); 
    for (i = 0; i < n; i++){ 
        p[i].pid = 1 + i; 
        printf("\n Enter burst time of process %d : ", i + 1); 
        scanf("%d", &p[i].btime); 
    } 
    p[0].wtime = 0; 
    p[0].ttime = p[0].btime; 
    totttime += p[i].ttime; 
    for (i = 0; i < n; i++){ 
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime; 
        p[i].ttime = p[i].wtime + p[i].btime; 
        totttime += p[i].ttime; 
        totwtime += p[i].wtime; 
    } 
    printf("\n\n Process Scheduling....\n\nProcess "); 
    printf("\t burst time "); 
    printf("\t waiting time "); 
    printf("\t turn around time "); 
    for (i = 0; i < n; i++){ 
        printf("\n"); 
        printf("%d\t\t\t%d\t\t%d\t\t%d", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime); 
    } 
    printf("\n\n total waiting time :%d", totwtime); 
    printf("\n average waiting time :%f", (float)totwtime / n); 
    printf("\n total turn around time :%d", totttime); 
    printf("\n average turn around time: :%f", (float)totttime / n); 
} 