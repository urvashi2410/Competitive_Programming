#include <bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
};

int hcf(int a, int b){
    for(int i = a<b?a:b; i >= 1; i--){
        if(a%i == 0 && b%i == 0){
            return i;
        }
    }
    return 1;
}

int gcdEuclid(int a, int b){
    if(b == 0){
        return a;
    }
    
    if(a > b){
        return gcdEuclid(b, a%b);
    }
    
    return gcdEuclid(b, a);
}

Triplet extendedEuclid(int a, int b){
    if(b == 0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    
    Triplet smallAns;
    smallAns = extendedEuclid(b, a%b);
    Triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = (smallAns.x - (a/b)*(smallAns.y));
    return myAns;
}

int main(){
    int a;
    int b;
    cin >> a >> b;
    Triplet ans;
    ans = extendedEuclid(a, b);
    cout << ans.gcd << endl;
    cout << ans.x << endl;
    cout << ans.y << endl;
}

