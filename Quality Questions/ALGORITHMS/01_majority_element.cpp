#include<bits/stdc++.h>
using namespace std;

int majorityElementN2(int arr[], int n){
    int element = arr[0];
    int count = 1;
    
    for(int i = 1; i < n; i++){
        if(arr[i] == element){
            count++;
        }
        else if(count == 0){
            element = arr[i];
        }
        else{
            count--;
        }
    }
    
    count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == element){
            count++;
        }
    }
    
    if(count > n/2){
        return element;
    }
    
    return -1;
}

vector<int> majorityElementN3(int arr[], int n){
    vector<int>v;
    
    int element1 = arr[0];
    int count1 = 0;
    int element2 = 0;
    int count2 = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == element1){
            count1++;
        }
        
        else if(arr[i] == element2){
            count2++;
        }
        
        else if(count1 == 0){
            element1 = arr[i];
            count1 = 1;
        }
        
        else if(count2 == 0){
            element2 = arr[i];
            count2 = 1;
        }
        
        else{
            count1--;
            count2--;
        }
    }
    
    count1 = 0;
    count2 = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] == element1){
            count1++;
        }
        
        else if(arr[i] == element2){
            count2++;
        }
    }
    
    if(count1 > n/3){
        v.push_back(element1);
    }
    
    if(count2 > n/3){
        v.push_back(element2);
    }
    
    return v;
}


int main(){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // cout << majorityElementN2(arr, n) << endl;
    
    vector<int>v = majorityElementN3(arr, n);
    
    for(auto i : v){
        cout << i << " ";
    }
    
    return 0;
}