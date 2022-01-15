#include <bits/stdc++.h>
using namespace std;

int next(vector<int> &v, int i){
    int n = v.size();
    return (i + v[i] + n) % n;
}

bool circularArray(vector<int> &v, int n){
    for(int i = 0; i < n; i++){
        if(v[i] == 0){
            continue;
        }
        
        int slow = i;
        int fast = i;
        
        while(
            v[slow]*v[next(v, slow)] > 0 &&
            v[fast]*v[next(v, fast)] > 0 &&
            v[fast]*v[next(v, next(v, fast))] > 0
        ){
            slow = next(v, slow);
            fast = next(v, next(v, fast));
            if(slow == fast){
                if(v[slow] == v[next(v, slow)]){
                    break;
                }
                return true;
            }
        }
        
        slow = i;
        int val = v[slow];
        while(val*v[slow] > 0){
            int x = slow;
            slow = next(v, slow);
            v[x] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    
    int x;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cout << circularArray(v, n);
    return 0;
}