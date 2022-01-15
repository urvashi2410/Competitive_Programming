#include <bits/stdc++.h>
using namespace std;

string Prediction(int A[], int n){
    int XOR = A[0];

    for(int i = 1; i < n; i++){
        XOR = XOR^A[i];
    }

    if(XOR != 0 || n&1){
        return "Player1";
    }
    return "Player2";
}
int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    cout << Prediction(A, n);
}