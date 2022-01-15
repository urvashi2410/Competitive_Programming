#include<bits/stdc++.h>
using namespace std;

double multiply(double num, int n){
    double mul = 1.0;
    for(int i = 0; i < n; i++){
        mul *= num;
    }
    return mul;
}

double nthRoot(int n, int m){
    double low = 1;
    double high = m;
    double limit = 1e-6;
    
    while((high - low) > limit){
        double mid = (high + low) / 2;
        
        if(multiply(mid, n) > m){
            high = mid;
        }
        else{
            low = mid;
        }
    }
    return low;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    cout << nthRoot(n, m) << endl;
    return 0;
}