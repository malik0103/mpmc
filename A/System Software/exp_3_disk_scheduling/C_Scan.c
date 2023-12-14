#include <stdio.h>
void main(){
    int n, disk, sum = 0, d[20], max, dloc, i;
    printf("\nNo.of locations:\t");
    scanf("%d", &n);
    printf("\nPosition of head:\t");
    scanf("%d", &disk);
    printf("\nElements of the disk queue:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &d[i]);
    d[n] = disk;
    n++;
    for (i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (d[i] > d[j]){
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
    max = 199;
    for (i = 0; i < n; i++)
        if (disk == d[i]){
            dloc = i;
            break;
        }
    for (i = dloc; i < n; i++)
        printf(" %d -->", d[i]);
    printf(" 199 --> 0 --> ");
    for (i = 0; i < dloc; i++)
        printf("%d --> ", d[i]);
    sum = d[i - 1] + (max - disk) + max;
    printf("\nTotal cylinders :%d", sum);
}