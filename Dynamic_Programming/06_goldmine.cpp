#include <bits/stdc++.h>
using namespace std;

int maxGold(vector<vector<int>> &A, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m));
    
    for(int i = (n - 1); i >= 0; i--){
        for(int j = (m - 1); j >= 0; j--){
            if(i == (n - 1) && j == (m - 1)){
                dp[i][j] = A[i][j];
            }
            else if(i == (n - 1)){
                dp[i][j] = A[i][j] + dp[i][j + 1];
            }
            else if(j == (m - 1)){
                dp[i][j] = A[i][j] + dp[i + 1][j];
            }
            else{
                dp[i][j] = A[i][j] + max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i][0]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> A(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> A[i][j];
        }
    }
    
    cout << maxGold(A, n, m) << endl;
    return 0;
}