#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void fillArray(int *ar, int length, int upperBound)
{
    for (int i = 0; i < length; i++)
    {
        ar[i] = random() % upperBound;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void prtArray(int *ar, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", ar[i]);
    }
    printf("\n");
}

void merge(int *ar, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int *L = (int *)malloc(sizeof(int) * n1);
    int *R = (int *)malloc(sizeof(int) * n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = ar[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = ar[m + j + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *ar, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(ar, l, m);
        mergeSort(ar, m + 1, r);
        merge(ar, l, m, r);
    }
}

int qsPartition(int *ar, int l, int r)
{
    int pivot = ar[r];
    int i = (l - 1);

    for (int j = l; j < r; j++)
    {
        if (ar[j] < pivot)
        {
            i++;
            swap(&ar[i], &ar[j]);
        }
    }
    swap(&ar[i + 1], &ar[r]);
    return (i + 1);
}

void quickSort(int *ar, int l, int r)
{
    if (l < r)
    {
        int partitionIndex = qsPartition(ar, l, r);

        quickSort(ar, l, partitionIndex - 1);
        quickSort(ar, partitionIndex + 1, r);
    }
}

void bubbleSort(int *ar, int length)
{
    while (--length)
    {
        for (int i = 0; i < length; i++)
        {
            if (ar[i] > ar[i + 1])
            {
                swap(&ar[i], &ar[i + 1]);
            }
        }
    }
}

void insertSort(int *array, int length)
{
    for (int j = 1; j < length; j++)
    {
        int key = array[j];
        int i = j - 1;
        while (i >= 0 && array[i] > key)
        {
            array[i + 1] = array[i];
            i--;
        }
        array[i + 1] = key;
    }
}

void selectionSort(int *ar, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (ar[j] < ar[index])
            {
                swap(&ar[index], &ar[j]);
            }
        }
    }
}

int binarySearch(int *ar, int target, int l, int r)
{
    if (l >= r)
    {
        return false;
    }

    int mid = l + (r - l) / 2;
    if (ar[mid] == target)
    {
        return true;
    }
    else if (ar[mid] < target)
    {
        return binarySearch(ar, target, mid, r);
    }
    else
    {
        return binarySearch(ar, target, l, mid);
    }
}

int main()
{
    int *ar = (int *)malloc(10 * sizeof(int));
    int length = 4, upperBound = 30;
    if (ar == NULL)
    {
        return -1;
    }

    fillArray(ar, length, upperBound);
    prtArray(ar, length);
    //    insertSort(ar, length);
    //    selectionSort(ar, length);
    //    bubbleSort(ar, length);
    mergeSort(ar, 0, length - 1);
    //    quickSort(ar, 0, length - 1);
    prtArray(ar, length);
    binarySearch(ar, 13, 0, length - 1);
    free(ar);
}