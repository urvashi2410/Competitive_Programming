#include <bits/stdc++.h>
using namespace std;

int power(int x, int y, int m){
    if(y == 0){
        return 1;
    }
    
    int ans = power(x, y/2, m) % m;
    int smallAns = (ans*ans) % m;
    
    if(y & 1){
        return (x * smallAns) % m;
    }
    return smallAns % m;
}

int modInverse(int a, int m){
    return power(a, m - 2, m);
}

long long solve(int n, int r, int p){
    if(r == 0){
        return 1;
    }
    if(r > n){
        return 0;
    }
    
    int* fact = new int[n + 1];
    fact[0] = 1;
    fact[1] = 1;
    
    for(int i = 2; i <= n; i++){
        fact[i] = (fact[i - 1]*i) % p;
    }
    
    int nfact = fact[n];
    int rfact = fact[r];
    int nrfact = fact[n-r];
    
    delete fact;
    return (nfact*(modInverse(rfact, p)) % p) * (modInverse(nrfact, p) % p) % p;
}

int main(){
    int n, r, p;
    cin >> n >> r >> p;
    cout << solve(n, r, p);
    return 0;
}
