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
    int idx = lower_bound(A, A+n, x) - A;
    idx--;
    
    if(idx >= 0){
        cout << idx << endl;
    }
    else{
        cout << -1 << endl;
    }
}