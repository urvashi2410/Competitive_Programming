#include <bits/stdc++.h>
using namespace std;

int factorial(int n, int m){
    int fact = 1;
    for(int i = n; i >= 1; i--){
        fact *= i;
        fact %= m;
    }
    return fact;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    cout << factorial(n, m) << endl;
    return 0;
}