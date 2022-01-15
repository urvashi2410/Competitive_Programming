#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n){
    
    // only one way to reach stair 0 from 0 by standing
    if(n == 0){
        return 1;
    }
    
    if(n < 0){
        return 0;
    }
    
    int a = climbStairs(n - 1);
    int b = climbStairs(n - 2);
    int c = climbStairs(n - 3);
    return (a + b + c);
}

int climbStairsTD(int n, int* dp){
    if(n == 0){
        return 1;
    }
    
    if(n < 0){
        return 0;
    }
    
    if(dp[n] > 0){
        return dp[n];
    }
    
    int a = climbStairsTD(n - 1, dp);
    int b = climbStairsTD(n - 2, dp);
    int c = climbStairsTD(n - 3, dp);
    
    int ans = a + b + c;
    dp[n] = ans;
    return ans;
}

int climbStairsBU(int n){
    int* dp = new int[n + 1];
    if(n < 0){
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        if(i == 1){
            dp[i] = dp[i - 1];
        }
        else if(i == 2){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        else{
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
    }
    
    int ans = dp[n];
    delete dp;
    return ans;
}

int main(){
    int n;
    cin >> n;
    
    // cout << climbStairs(n) << endl;
    
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    // cout << climbStairsTD(n, dp) << endl;
    
    cout << climbStairsBU(n) << endl;
    
}