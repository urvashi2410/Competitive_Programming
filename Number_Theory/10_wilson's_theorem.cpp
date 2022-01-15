// Wilson's theorem : (p-1)! % p = p-1

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void print_primes(ll n){
    ll fact = 1;
    for(ll i = 2; i < n; i++){
        fact *= (i-1);
        
        if((fact + 1) % i == 0){
            cout << i << " ";
        }
    }
}

int main(){
    ll n;
    cin >> n;
    print_primes(n);
    return 0;
}