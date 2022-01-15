#include <bits/stdc++.h>
using namespace std;

int noOfOccurrences(int* A, int n, int x){
    int lb = lower_bound(A, A+n, x) - A;
    int ub = upper_bound(A, A+n, x) - A;
    
    if(lb >= 0 && lb < n && ub > 0 && ub <= n){
        return (ub - lb);
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    int x;
    cin >> x;
    cout << noOfOccurrences(A, n, x) << endl;
    return 0;
}