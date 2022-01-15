#include<bits/stdc++.h>
using namespace std;
#define point pair<int, int> 

int orientation(point a, point b, point c){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int x3 = c.first;
    int y3 = c.second;
    
    int slope = (y3 - y2)*(x2 - x1) - (x3 - x2)*(y2 - y1);
    
    if(slope == 0){
        return 0;
    }
    else if(slope > 0){
        return 1;
    }
    return 2;
}

bool onSegment(point a, point b, point c){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int x3 = c.first;
    int y3 = c.second;
    
    if(x3 >= min(x1, x2) && y3 >= min(y1, y2) && x3 <= max(x1, x2) && y3 <= max(y1, y2) ){
        return true;
    }
    
    return false;
}

bool isIntersection(point a, point b, point c, point d){
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);
    
    if(o1 != o2 && o3 != o4){
        return true;
    }
    return false;
}

void solve(vector<point>&vertices, vector<point>&poi){
    int count = 0;
    int n = vertices.size();
    
    for(auto cp : poi){
        bool isBoundary = false;
        point infinity = make_pair(cp.first, INT_MAX);
        
        for(int i = 0; i < n; i++){
            point a = vertices[i];
            point b = vertices[(i+1)%n];
            
            if(orientation(a, b, cp) == 0 && onSegment(a, b, cp)){
                isBoundary = true;
                break;
            }
            
            else if(isIntersection(a, b, cp, infinity)){
                count++;
            }
        }
        
        if(isBoundary){
            cout << "BOUNDARY" << endl;
        }
        
        else{
            if(count&1){
                cout << "INSIDE" << endl;
            }
            else{
                cout << "OUTSIDE" << endl;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<point>vertices;
    while(n--){
        int x, y;
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }
    
    vector<point>poi;
    while(m--){
        int x, y;
        cin >> x >> y;
        poi.push_back(make_pair(x, y));
    }
    
    solve(vertices, poi);
}