#include<stdio.h>
int main(){
    int i,j,sum=0,n,disk;
    int ar[20],tm[20];
    printf("Enter no.of locations: ");
    scanf("%d", &n);
    printf("Enter the position of head: ");
    scanf("%d", &disk);
    printf("\nEnter the elements of the disk queue:\n");
    for(i=0;i<n;i++){
        scanf("%d",&ar[i]);
        tm[i]=disk-ar[i];
        if(tm[i]<0){
            tm[i]=ar[i]-disk;
        }
        disk=ar[i];
        sum=sum+tm[i];
    }
    for(i=0;i<n;i++){
        printf("%d +",tm[i]);
    }
    printf("\nMovement of total cylinders =%d",sum);
    return 0;
}