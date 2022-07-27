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
void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int A[n1], B[n2];

  for (int i = 0; i < n1; i++)
    A[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    B[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (A[i] <= B[j]) {
      arr[k] = A[i];
      i++;
    } else {
      arr[k] = B[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = A[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = B[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {    
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
int partition(int array[], int l, int h) {
  
    int pivot = array[h];
    int i = (l - 1);
    for (int j = l; j < h; j++) {
    if (array[j] <= pivot) {
        i++;
        swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[h]);
    return (i + 1);
}

void quickSort(int array[], int l, int h) {
  if (l < h) {
    
    
    int pi = partition(array, l, h);
    
    quickSort(array, l, pi - 1);
    
    quickSort(array, pi + 1, h);
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
    else if(choice==4){
        mergeSort(a,n);
        Printarray(a,n);
    }
    else if(choice==5){
        quickSort(a, 0, n - 1);
        Printarray(a,n);
    }
    
    

}
