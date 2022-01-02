#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[], int l, int mid, int h) 
{
    int i, j, k; // iterator variables

    int n1 = mid - l + 1; // size of lower temp array
    int n2 = h - mid; // size of higher temp array
    
    int templ[n1], temph[n2]; // temp array
    
    // copy data to the split arrays
    for (int i = 0; i < n1; i++)
        templ[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        temph[j] = arr[mid + 1 + j];

    i = 0; // initial index of first subarray
    j = 0; // initial index of second subarray
    k = l; // initial index fo merged subarray

    // sort & merge elements through iteration
        // this works cuz the temp arrays are already sorted
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
    if (l < h) // recursive execute until subarray only has 1 element
    { 
        int mid = l + (h - l) / 2; // same as (l + h) / 2, this arrangement helps deal with overflow

        mergeSort(arr, l, mid); // recursve call on the lower half of array
        mergeSort(arr, mid + 1, h); // recursive call on the higher half of the array

        merge(arr, l, mid, h);
    }
}

int main() 
{
    // INIT
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // INPUT
        // 12, 11, 13, 7, 6, 7
    int arr[6] = {12, 11, 13, 7, 6, 7}; // constant values; can be rewritten for user input
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout<<"Before sorting: ";
    for(int i = 0; i < arrSize; i++) 
        cout<<arr[i]<<" ";
    cout<<"\n";
    
    // PROGRESS
    mergeSort(arr, 0, arrSize - 1);
   
   // OUTPUT
    // 5, 6, 7, 11, 12, 13
   cout<<"After sorting: ";
    for(int i = 0; i < arrSize; i++) 
        cout<<arr[i]<<" ";
    cout<<"\n";

}