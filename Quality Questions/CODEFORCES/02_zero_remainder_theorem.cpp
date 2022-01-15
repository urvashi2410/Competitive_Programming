// zero remainder theorem = sum of 2 numbers is divisible by k,
// if sum of their remainder is divisible by k 

#include<bits/stdc++.h>
using namespace std;

int minimum_steps(int arr[], int n , int k){
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++){
        int x = arr[i] % k;
        if(x){
            m[x]++;
        }
    }
    
    int ans = 0;
    for(auto i : m){
        int rem = i.first;
        int count = i.second;
        
        ans = max(ans, count*k - rem);
    }
    
    if(ans > 0){
        ans++;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        cout << minimum_steps(arr, n, k) << endl;
    }
    return 0;
}