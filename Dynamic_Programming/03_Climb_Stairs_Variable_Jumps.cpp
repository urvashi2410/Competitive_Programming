#include <bits/stdc++.h>
using namespace std;

int climbStairsVariableJumps(int n, int* A){
    int* dp = new int[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; j <= A[i]; j++){
            if(i + j <= n){
                dp[i] = dp[i] + dp[i + j];
            }
        }
    }
    
    int ans = dp[0];
    delete dp;
    return ans;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    cout << climbStairsVariableJumps(n, A) << endl;
}