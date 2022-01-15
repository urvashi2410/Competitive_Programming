#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        string s1;
        cin >> s1;
        
        string s2;
        cin >> s2;
        
        int arr[3] = {0};
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] == 'b' || s2[i] == 'b'){
                arr[i] = 1;
            }
        }
        
        int countb = 0;
        for(int i = 0; i < 3; i++){
            if(arr[i] == 1){
                countb++;
            }
        }
        
        if(countb <= 1){
            cout << "no" << endl;
        }
        else if(countb == 2){
            int idx;
            
            for(int i = 0; i < 3; i++){
                if(arr[i] == 0){
                    idx = i;
                }
            }
            
            if(s1[idx] == 'o' || s2[idx] == 'o'){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
        
        else if(countb == 3){
            int counto = 0;
            
            for(int i = 0; i < s2.size(); i++){
                if(s2[i] == 'o'){
                    counto++;
                }
            }
            
            if(counto == 0){
                cout << "no" << endl;
            }
            else{
                cout <<"yes" << endl;
            }
        }
    }
    return 0;
}