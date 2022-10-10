#include <stdio.h>
#include <conio.h>

void bucketsort(float a[],int size){
    int b[10];
    int i,floor;
    for (i=0;i<10;i++){
        b[i]=0;
    }
    for (i=0;i<size;i++){
        floor = (a[i]*10)/10;
        b[floor] = a[i];
    }
    for ( i = 0; i < size ; i++)
    {
        if (b[i] == 0){
            i++;
        }
        else{
            a[i] = b[i];
        }
    }
    
}

int main(){
    int n,i;
    float a[100];
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    printf("enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%f",&a[i]);
    }
    printf("\nUnsorted array:\t");
    for (i=0;i<n;i++){
        printf("%f",a[i]);
    }
    bucketsort(a,n);
    printf("\nSorted array:\t");
    for (i=0;i<n;i++){
        printf("%2f\t",a[i]);
    }
    getch();
    return 0;
}