#include <iostream>

using namespace std;

int main(){

    // INITIALIZATION

    // fast i/o
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[8] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "size "<< n;

    // PROCESS (Bubble Sort algorithm)
    for (int i=0; i<n-1; i++){          // # of passes = length of list - 1
        for (int j=0; j<n-1-i; j++){    // 1 less comparison per pass (optimizes the algorithm)

            // compare adjacent items & swap if necessary
            if (arr[j]>arr[j+1] && arr[i]!=arr[j]){
                cout << "Compared values: " << arr[j] << ", " << arr[j+1] <<"\n";
                swap(arr[j], arr[j+1]);
                cout << "New values: " << arr[j] << ", " << arr[j+1] << "\n";
            }
        }
    }

    // ITERATIVE OUTPUT
    cout << "Here are the sorted values: ";
    for (auto i : arr)
        cout << " " << i;

}
