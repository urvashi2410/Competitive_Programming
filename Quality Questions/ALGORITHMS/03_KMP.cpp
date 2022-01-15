#include <bits/stdc++.h>
using namespace std;

void pieTable(int* Pie, int m, string pattern){
    
    // initialising the pie table with all zeroes 
    for(int i = 0; i < m; i++){
        Pie[i] = 0;
    }
    
    int i = 0;
    int j = 1;
    
    while(j < m){
        if(pattern[i] == pattern[j]){
            Pie[j] = i + 1;
            i++;
            j++;
        }
        else{
            if(i == 0){
                Pie[j] = 0;
                j++;
            }
            else{
                i = Pie[i - 1];
            }
        }
    }
}

vector<int>KMP(string s, string pattern, int* Pie){
    int n = s.size();
    int m = pattern.size();
    
    vector<int>ans;
    int i = 0;
    int j = 0;
    
    while(i < n){
        if(s[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            ans.push_back(i - m);
            j = Pie[j - 1];
        }
        else if(i < n && pattern[j] != s[i]){
            if(j == 0){
                i++;
            }
            else{
                j = Pie[j - 1];
            }
        }
    }
    
    return ans;
}

int main(){
    string s;
    cin >> s;
    string pattern;
    cin >> pattern;
    
    int m = pattern.size();
    int Pie[m];
    
    pieTable(Pie, m, pattern);
    vector<int>ans = KMP(s, pattern, Pie);
    
    for(auto i : ans){
        cout << i << " ";
    }
    
    return 0;
    
}