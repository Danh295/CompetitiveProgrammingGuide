#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);

    int arr[8] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"size "<<n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                cout<<arr[j]<<", "<<arr[j+1]<<"\n";
                swap(arr[j],arr[j+1]);
                cout<<"new: "<<arr[j]<<", "<<arr[j+1]<<"\n";
            }
        }
    }

    // for(auto i : arr){
    //     cout<<i<<"\n";
    // }

}
