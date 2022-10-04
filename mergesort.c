#include <stdio.h>

void merge(int A[], int mid, int first_index, int last_index)
{
    int i, j, k;
    int b[10];
    i = first_index;
    j = mid + 1;
    k = first_index;

    while (i <= mid && j <= last_index)
    {
        if (A[i] <= A[j])
        {
            b[k] = A[i];
            i++;         
            k++;
        }
        else
        {
            b[k] = A[j];
            j++;
            k++;
        }
    }
    if(j > last_index){
    while (i <= mid)
    {
        b[k] = A[i];
        i++;
        k++;
    }
    }
    else{
    while (j <= last_index)
    {
        b[k] = A[j];
        j++;
        k++;
    }
    }
    for (int i = first_index; i <= last_index; i++)
    {
        A[i] = b[i];
    }
}

void mergesort(int A[], int first_index, int last_index)
{
    int mid;

    if (first_index < last_index)
    {
        mid = (first_index + last_index) / 2;
        mergesort(A, first_index, mid);
        mergesort(A, mid + 1, last_index);
        merge(A, mid,first_index,last_index);
    }
}
int main()
{
    int n,i;
    int a[100];
    printf("Enter the nunmber of elements in the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("unsorted Array:\t");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", a[i]);
    }
    printf("\n\n");
    mergesort(a, 0, (n-1));
    printf("Sorted Array:\t");
    for (i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}