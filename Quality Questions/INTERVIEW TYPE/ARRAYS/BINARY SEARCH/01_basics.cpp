#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    int x;
    cin >> x;
    
    // it tells whether that number is prsent or not
    int idx = binary_search(A, A+n, x);
    // cout << idx << endl;
    
    // returns first occurrence index
    int idx1 = lower_bound(A, A+n, x) - A;
    
    // returns one index after last occurrence
    int idx2 = upper_bound(A, A+n, x) - A;
    
    cout << idx1 << endl;
    cout << idx2 << endl;
}