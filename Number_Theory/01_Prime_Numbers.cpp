#include <bits/stdc++.h>
using namespace std;

bool isPrime1(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool isPrimeSqrt(int n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool primeSieve(int n){
    bool primes[n];
    memset(primes, true, sizeof(primes));
    
    primes[0] = false;
    primes[1] = false;
    
    for(int i = 2; i <= n; i++){
        if(primes[i]){
            for(int j = i*2; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
    
    for(int i = 0; i <= n; i++){
        if(primes[i]){
            cout << i << " ";
        }
    }
}

// Time complexity: loglogn
bool primeSieveOptimised(int n){
    bool primes[n];
    memset(primes, true, sizeof(primes));
    
    primes[0] = false;
    primes[1] = false;
    
    for(int i = 2; i*i <= n; i++){
        if(primes[i]){
            for(int j = i*i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
    
    for(int i = 0; i <= n; i++){
        if(primes[i]){
            cout << i << " ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    primeSieveOptimised(n);
}