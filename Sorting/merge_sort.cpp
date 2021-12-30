// #include <iostream>

// using namespace std;

// void merge(int arr[], int l, int mid, int h) {
//     int i, j, k; // iterator variables
//     int n1 = mid - l + 1; // size of lower temp arr
//     int n2 = h - mid; // size of higher temp arr

//     int templ[n1], temph[n2]; // temp array

//     // copy data to the split arrays
//     for (i = 0; i < n1; i++)
//         templ[i] = arr[l + i];
//     for (j = 0; j < n2; j++);
//         temph[j] = arr[mid + 1 + j];

//     i = 0; // initial index of first subarray
//     j = 0; // initial index of second subarray
//     k = l; // initial index of merged subarray

//     // sort & merge elements through iteration
//     while (i < n1 && j < n2) {
//         if (templ[i] <= temph[j]) {
//             arr[k] = templ[i];
//             i++;
//         } else {
//             arr[k] = temph[j];
//             j++;
//         }
//         k++;
//     }

//     // copy remaining elements if there are any
//     while (i < n1) {
//         arr[k] = templ[i];
//         i++;
//         k++;
//     }
//     while (j < n2) {
//         arr[k] = temph[j];
//         j++;
//         k++;
//     }
// }

// void mergeSort(int arr[], int l, int h) {
//     if (l < h) { // recursive execute until subarr only has 1 elem
//         cout<<"merged"<<endl;
//         int mid = l + (h - 1) / 2;

//         mergeSort(arr, l, mid);
//         mergeSort(arr, mid + 1, h);

//         merge(arr, l, mid, h);
//     }
// }

// void printArray(int a[], int size) {
//     int i;
//     for(int i = 0; i < size; i++) {
//         cout<<a[i]<<" ";
//     }
//     cout<<"\n";
// }

// int main() {
//     // INPUT
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     // int arr[5];
//     // for(int i = 0; i < 5; i++)
//     //     cin>>arr[i];
//     int arrSize = sizeof(arr) / sizeof(arr[0]);

//     // PROCESS - call mergesort
//     mergeSort(arr, 0, arrSize - 1);

//     // OUPTUT
//         // int arr[5] = {1,2,4,5,7};
//     printArray(arr, arrSize);

//     return 0;
// }

#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        
        int m = l + (r - 1) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    ios::sync_with_stdio(0);

    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout<<"Before merge sort: ";
    for (int n = 0; n < 6; n++) 
        cout<<arr[n]<<" ";
    cout<<"\n";

    mergeSort(arr, 0, arrSize - 1);

    cout<<"After merge sort: ";
    for (int n = 0; n < 6; n++)
        cout<<arr[n]<<" ";
    cout<<"\n";

    return 0;
}