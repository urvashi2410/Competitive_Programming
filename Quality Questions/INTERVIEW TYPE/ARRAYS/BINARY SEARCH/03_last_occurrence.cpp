#include <bits/stdc++.h>
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
    int idx = upper_bound(A, A+n, x) - A;
    idx--;
    
    if(idx >= 0 && A[idx] == x){
        cout << idx << endl;
    }
    else{
        cout << -1 << endl;
    }
}