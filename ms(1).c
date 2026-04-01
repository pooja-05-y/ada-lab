

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100000];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n, arr[100000], i;
    clock_t start, end;
    double time_taken;
    n=105000;
//
//    printf("Enter no of elements: ");
//    scanf("%d", &n);

//    printf("Enter the elements:\n");
//    for (i = 0; i < n; i++)
//        scanf("%d", &arr[i]);

    printf("start");
    for (int i = 0; i<n; i++) {
        arr[i]=rand();
    }
    printf("end");

    start = clock();

    sort(arr, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\n Sorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n Time taken to sort %d elements = %f seconds\n", n, time_taken);

    return 0;
}
