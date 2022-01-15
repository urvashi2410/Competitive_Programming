#include<bits/stdc++.h>
using namespace std;

int findMex(unordered_set<int> s){
    int mex = 0;
    while(s.find(mex) != s.end()){
        mex++;
    }
    
    return mex;
}

int grundy(int a){
    if(a == 0 || a == 1 || a == 2 || a == 3){
        return a;
    }
    
    unordered_set<int> s;
    for(int i = 1; i <= 3; i++){
        s.insert(a - i);
    }
    
    return findMex(s);
}

string Prediction(int A[], int n){
    int XOR = grundy(A[0]);
    
    for(int i = 1; i < n; i++){
        XOR = XOR^grundy(A[i]);
    }
    
    if(XOR != 0){
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
    cout << Prediction(A, n) << endl;
    return 0;
}