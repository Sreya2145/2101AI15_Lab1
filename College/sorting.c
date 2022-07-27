#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
void selectionSort(int arr[], int size)
{
    int i, j;
    for (i = 0 ;  i < size;i++)
    {
        for (j = i ; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}
void insertionSort(int arr[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++) 
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) 
        {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    printf("Enter the size of array\n");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Choose your desired sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        bubbleSort(a, n);
        Printarray(a, n);
    }
    else if(choice==2){
        selectionSort(a,n);
        Printarray(a,n);
    }
    else if(choice==3){
        insertionSort(a,n);
        Printarray(a,n);
    }
    

}
