#include<bits/stdc++.h>
using namespace std;
#define point pair<int, int>

int crossProduct(point a, point b){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    
    int cp = y2*x1 - x2*y1;
    return cp;
}

int areaPolygon(vector<point> &vertice){
    int ans = 0;
    int n = vertice.size();
    
    for(int i = 0; i < n; i++){
        point a = vertice[i];
        point b = vertice[(i+1)%n];
        
        int crP = crossProduct(a, b);
        ans += crP;
    }
    
    return abs(ans/2);
}

int main(){
    int n;
    cin >> n;
    
    vector<point>vertice;
    
    while(n--){
        int x, y;
        cin >> x >> y;
        vertice.push_back(make_pair(x, y));
    }
    
    cout << 2*areaPolygon(vertice) << endl;
}