#include<bits/stdc++.h>
using namespace std;
#define point pair<int, int>

int crossProduct(point a, point b){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    
    return (y2*x1 - x2*y1);
}


int area(vector<point> &vertices){
    int ans = 0;
    int n = vertices.size();
    
    for(int i = 0; i < n; i++){
        point a = vertices[i];
        point b = vertices[(i+1)%n];
        ans += crossProduct(a, b);
    }
    
    return abs(ans) / 2;
}

// function to count lattice points between two vertices 
int latticeOnSegment(point a, point b){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    
    int fvalue = abs(y2 - y1);
    int svalue = abs(x2 - x1);
    
    return __gcd(fvalue, svalue) - 1;
}

point solve(vector<point> &vertices){
    int n = vertices.size();
    int Area = area(vertices);
    point ans;
    int segmentLattice = 0;
    
    // this will add all the lattice points between all the vertices
    for(int i = 0; i < n; i++){
        point a = vertices[i];
        point b = vertices[(i+1)%n];
        segmentLattice += latticeOnSegment(a, b);
    }
    
    // adding the vertices also in the lattice points 
    segmentLattice += n;
    
    // by pick's theorem 
    // A = i + (b/2) - 1 
    int insideLattice = (Area + 1 - (segmentLattice >> 1));
    ans.first = insideLattice;
    ans.second = segmentLattice;
    return ans;
}

int main(){
    int n;
    cin >> n;
    
    vector<point> vertices;
    while(n--){
        int x, y;
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }
    
    point ans = solve(vertices);
    cout << ans.first << " " << ans.second << endl;
}