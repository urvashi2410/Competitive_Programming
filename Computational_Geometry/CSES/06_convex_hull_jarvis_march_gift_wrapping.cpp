#include <bits/stdc++.h>
using namespace std;
#define point pair<int, int>
int orientation(point a, point b, point c){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    int x3 = c.first;
    int y3 = c.second;
    
    int ans = (y3 - y2)*(x2 - x1) - (y2 - y1)*(x3 - x2);
    if(ans == 0){
        return 0;
    }
    else if(ans > 0){
        return 1;
    }
    return 2;
}

int distance(point a, point b){
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    
    return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

set<point> convex_hull(vector<point> vertices){
    set<point>hull;
    int n = vertices.size();
    point start = vertices[0];
    for(int i = 1; i < n; i++){
        if(start.first > vertices[i].first){
            start = vertices[i];
        }
    }
    
    point current = start;
    vector<point> collinear_pts;
    hull.insert(start);
    
    while(true){
        point next = vertices[0];
        
        for(int i = 1; i < n; i++){
            if(vertices[i] == current){
                continue;
            }
            
            int o = orientation(current, next, vertices[i]);
            
            // found vertex in the left
            if(o == 2){
                next = vertices[i];
                collinear_pts.clear();
            }
            
            // collinear 
            else if(o == 0){
                int d1 = distance(current, next);
                int d2 = distance(current, vertices[i]);
                
                if(d1 > d2){
                    collinear_pts.push_back(vertices[i]);
                }
                else{
                    collinear_pts.push_back(next);
                    next = vertices[i];
                }
            }
        }
        
        vector<point> :: iterator it;
        for(it = collinear_pts.begin(); it != collinear_pts.end(); it++){
            hull.insert(*it);
        }
        
        // means we have traversed the whole hexagon 
        if(next == start){
            break;
        }
        
        hull.insert(next);
        current = next;
    }
    
    return hull;
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
    
    set<point>hull;
    hull = convex_hull(vertices);
    cout << hull.size() << endl;
    for(point p : hull){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}