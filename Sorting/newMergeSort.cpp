#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int h)
{
    int i, j, k;

    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], H[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        H[j] = arr[m + 1 + j];
    
    i = 0; 
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= H[j])
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = H[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = H[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = l + (h - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);

        merge(arr, l, m, h);
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int arr[] = {12, 56, 24, 5, 10, 4, 2, 15};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout<<"Given array: ";
    for(int i = 0; i < arrSize; i++) 
        cout<<arr[i]<<" ";
    cout<<"\n";

    mergeSort(arr, 0, arrSize - 1);

    cout<<"Sorted array: ";
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}