#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int gcd;
    int x;
    int y;
};

Triplet extendedEuclids(int a, int b){
    if(b == 0){
        Triplet smallAns;
        smallAns.gcd = a;
        smallAns.x = 1;
        smallAns.y = 0;
        return smallAns;
    }
    
    Triplet smallAns = extendedEuclids(b, a%b);
    Triplet ans;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*(smallAns.y);
    return ans;
}

int modInverse(int a, int m){
    if(__gcd(a, m) != 1){
        return -1;
    }
    
    int ans = extendedEuclids(a, m).x;
    return (ans%m + m) % m;
}

int crt(int rem[], int num[], int n){
    int prod = 1;
    
    for(int i = 0; i < n; i++){
        prod *= num[i];
    }
    
    int ans = 0;
    int pp[n];
    int modIn[n];
    
    for(int i = 0; i < n; i++){
        pp[i] = prod/num[i];
    }
    
    for(int i = 0; i < n; i++){
        modIn[i] = modInverse(pp[i], num[i]);
    }
    
    for(int i = 0; i < n; i++){
        ans += (rem[i] * pp[i] * modIn[i]);
    }
    
    return ans%prod;
}

int main(){
    int n;
    cin >> n;
    int rem[n];
    int num[n];
    
    for(int i = 0; i < n; i++){
        cin >> rem[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    
    cout << crt(rem, num , n);
    return 0;
}