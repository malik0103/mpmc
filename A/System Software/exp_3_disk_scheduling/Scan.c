#include <stdio.h>
void main(){
    int   n, disk, sum = 0, d[20], max, dloc;
    printf("\nNo.of locations:\t");
    scanf("%d", &n);
    printf("\nPosition of head:\t");
    scanf("%d", &disk);
    printf("\nElements of the disk queue:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &d[i]);
    d[n] = disk;
    n += 1;
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (d[i] > d[j]){
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
    max = d[n - 1];
    for (int i = 0; i < n; i++){
        if (disk == d[i]){
            dloc = i;
            break;
        }
    }
    for (int i = dloc; i >= 0; i--)
        printf("%d -->", d[i]);
    printf(" 0 -->");
    for (int i = dloc + 1; i < n; i++)
        printf(" %d -->", d[i]);
    sum = disk + max;
    printf("\nTotal cylinders :%d", sum);
}