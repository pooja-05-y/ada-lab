#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int arr[100000], n, i;
    clock_t start, end;
    double time_taken;
    n=150000;

    printf("start");
    for (int i = 0; i<n; i++) {
        arr[i]=rand();
    }

//
//    printf("Enter number of elements: ");
//    scanf("%d", &n);
//
//    printf("Enter elements:\n");
//    for(i = 0; i < n; i++)
//        scanf("%d", &arr[i]);

    start = clock();

    quicksort(arr, 0, n - 1);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\nTime taken = %f seconds\n", time_taken);

    return 0;
}

void quicksort(int arr[], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(1)
    {
        while(i <= high && arr[i] <= pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            temp = arr[low];
            arr[low] = arr[j];
            arr[j] = temp;
            return j;
        }
    }
}




