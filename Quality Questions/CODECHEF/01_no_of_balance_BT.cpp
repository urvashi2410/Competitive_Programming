#include <bits/stdc++.h>
using namespace std;

int balanceBT(int h){
    if(h == 0 || h == 1){
        return 1;
    }
    
    int x = balanceBT(h - 1);
    int y = balanceBT(h - 2);
    
    // when height of left and right subtrees is h-1
    long res1 = (long)x*x;
    // when heights of left and right subtrees is h-1 and h-2 or h-2 and h-1
    long res2 = (long)x*y*2;
    
    // to prevent integer overflow we will take mod
    int m = pow(10, 9) + 7;
    int ans1 = (int)(res1 % m);
    int ans2 = (int)(res2 % m);
    return (ans1 + ans2) % m;
}

int main() {
    int h;
    cin >> h;
    cout << balanceBT(h) << endl;
	return 0;
}
