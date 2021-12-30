#include <iostream>

using namespace std;

void merge(int arr[], int l, int mid, int h) 
{
    int i, j, k; // iterator variables

    int n1 = mid - l + 1; // size of lower temp arr
    int n2 = h - mid; // size of higher temp arr

    int templ[n1], temph[n2]; // temp array

    // copy data to the split arrays
    for (int i = 0; i < n1; i++)
        templ[i] = arr[l + i];
    for (int j = 0; j < n2; j++);
        temph[j] = arr[mid + 1 + j];

    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = l; // initial index of merged subarray

    // sort & merge elements through iteration
    while (i < n1 && j < n2) 
    {
        if (templ[i] <= temph[j]) 
        {
            arr[k] = templ[i];
            i++;
        } 
        else 
        {
            arr[k] = temph[j];
            j++;
        }
        k++;
    }

    // copy remaining elements if there are any
    while (i < n1) 
    {
        arr[k] = templ[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = temph[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h) 
{
    if (l < h) // recursive execute until subarr only has 1 elem
    { 
        int mid = (l + h) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        merge(arr, l, mid, h);
    }
}

int main() {
    ios::sync_with_stdio(0);

    // INPUT
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < arrSize; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    // PROCESS - call mergesort
    mergeSort(arr, 0, arrSize - 1);

    // OUPTUT
        // int arr[5] = {1,2,4,5,7};
    for(int i = 0; i < arrSize; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}