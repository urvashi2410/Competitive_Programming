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
    
    else if(o1 == 0 && onSegment(a, b, c)){
        return true;
    }
    
    else if(o2 == 0 && onSegment(a, b, d)){
        return true;
    }
    
    else if(o3 == 0 && onSegment(c, d, a)){
        return true;
    }
    
    else if(o4 == 0 && onSegment(c, d, b)){
        return true;
    }
    
    return false;
}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        
        point a = make_pair(x1, y1);
        point b = make_pair(x2, y2);
        point c = make_pair(x3, y3);
        point d = make_pair(x4, y4);
        
        if(isIntersection(a, b, c, d)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
}