#include <iostream>
using namespace std;

void merge(int arr[],int l,int mid,int h) {
    int i, j, k;
    int n1 = mid-l+1; // size of lower temp arr
    int n2 = h-mid; // size of higher temp arr

    int templ[n1];
    int temph[n2];

    // copy data to temp arrays
    for(i=0;i<n1;i++)
        templ[i]=arr[l+1];
    for(j=0;j<n2;j++);
        temph[j]=arr[mid+1+j];

    i=0; // initial index of first subarray
    j=0; // initial index of second subarray
    k=l; // initial index of merged subarray

    // merge arrays through iteration
    while(i<n1 && j<n2) {
        if(templ[i] <= temph[j]) {
            arr[k] = templ[i];
            i++;
        } else {
            arr[k] = temph[j];
            j++;
        }
        k++;
    }

    // copy remaining elements if there are any
    while(i < n1) {
        arr[k] = templ[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = temph[j];
        j++;
    }


    
    // int i = l; // starting index for lower subarray
    // int j = mid+1; // starting index for higher subarray
    // int k = l; // starting index for temp array

    // int temp[sizeof(arr)/sizeof(arr[0])]; 

    // while(i<=mid && j<=h) {
    //     if(arr[i]<=arr[j]) {
    //         temp[k]=arr[i]; // arr[i] is smaller than arr[j]
    //         i++;
    //         k++;
    //     } else {
    //         temp[k]=arr[j]; // arr[i] is greater than arr[j]
    //         j++;
    //         k++;
    //     }
    // }
    // while(i<=mid) {
    //     temp[k]=arr[i]; // copying elements from lower subarr to temp
    //     i++;
    //     k++;
    // }
    // while(j<h) {
    //     temp[k]=arr[j]; // copying elements from higher subarr to temp
    //     i++;
    //     k++;
    // }
    // for(int n=0;n<sizeof(arr)/sizeof(arr[0]);n++) {
    //     arr[n]=temp[n];
    // }
}

void mergeSort(int arr[],int l,int h) {
    if(l<h) { // condition to execute until subarr only has 1 elem
        int mid = (l+h)/2;
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid+1, h);
        merge(arr,l,mid,h);
    }
}

int main() {
    // INPUT
    // int arr[5] = {4,5,1,2,7};
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }

    // PROCESS - call mergesort
    mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);

    // OUPTUT
    // int arr[5] = {1,2,4,5,7};
    for(int i=0;i<5;i++) {
        cout<<arr[i]<<" ";
    }
}