#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    
    if(a > b){
        return gcd(b, a%b);
    }
    return gcd(b, a);
}

long advanced_gcd(int a, string s){
    long ans = 0;
    for(int i = 0; s[i] != '\0'; i++){
        ans = (ans*10 + (s[i] - '0')) % a;
    }
    return ans;
}

int main() {
	int a;
	string s;
	cin >> a >> s;
	int small_b = advanced_gcd(a, s);
	cout << gcd(a, small_b) << endl;
	return 0;
}
