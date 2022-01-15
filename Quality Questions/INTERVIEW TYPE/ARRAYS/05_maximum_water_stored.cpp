#include <bits/stdc++.h>
using namespace std;

int maxWaterContainer(int* A, int n){
    int area = 0;
    int left = 0;
    int right = n - 1;
    
    while(left < right){
        area = max(area, (min(A[right], A[left]) * (right - left - 1)));
        
        if(A[left] > A[right]){
            right--;
        }
        else{
            left++;
        }
    }
    return area;
}

int main(){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    cout << maxWaterContainer(A, n);
    return 0;
}