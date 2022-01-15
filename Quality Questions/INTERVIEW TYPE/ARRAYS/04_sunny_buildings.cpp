#include <bits/stdc++.h>
using namespace std;

int noOfSunnyBuildings(int* A, int n){
    int maxHeight = INT_MIN;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(maxHeight < A[i]){
            maxHeight = A[i];
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    cout << noOfSunnyBuildings(A, n);
}