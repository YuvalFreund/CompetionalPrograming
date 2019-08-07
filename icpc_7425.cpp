#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
typedef vector<vector<int>> vvi;
struct Point
{
    int x;
    int y;
    Point(int x,int y):x(x),y(y){}
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;

    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}



void bfs(const vvi& g, int s,vector<int> &dis) {
    queue<int> q;
    q.push(s);
    vector<bool> visible (g.size(),false);
    visible[s]=true;
    dis[0]=0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (!visible[v]) {
                visible[v] = true;
                q.push(v);
                dis[v]=dis[u]+1;
            }
        }
    }
}
bool isBipartite(vvi & graph , vector<int> &dis){
    for (int i = 0; i < graph.size(); ++i) {
        for(auto &x :graph[i]){
            if(dis[i]%2 ==dis[x]%2) return false;
        }
    }
    return true;
}


int main()
{
    int w,p,s,x,y;
    while(cin>>w>>p){
        vvi graph(p);
        vector<Point> wells;
        vector<pair<Point,Point>> pipe;
        for (int i = 0; i < w; ++i) {
            cin>>x>>y;
            wells.push_back(Point(x,y));
        }
        for (int i = 0; i < p; ++i) {
            cin>>s>>x>>y;
            pipe.push_back(make_pair(wells[s-1],Point(x,y)));
        }
        for (int i = 0; i <pipe.size() ; ++i) {
            for (int j = i+1; j <pipe.size(); ++j) {
                if(!(pipe[i].first.x == pipe[j].first.x && pipe[i].first.y == pipe[j].first.y)){
                    if(doIntersect(pipe[i].first,pipe[i].second,pipe[j].first,pipe[j].second)){
                        graph[i].push_back(j);
                        graph[j].push_back(i);
                    }
                }
            }
        }
        vector<int> dis(graph.size(),-1);
        for (int i = 0; i < graph.size(); ++i) {
            if(dis[i]==-1) bfs(graph,i,dis);
        }
        if(!isBipartite(graph,dis)) cout<<"impossible\n";
        else cout<<"possible\n";
    }
    return 0;
}

/*
3 3
0 0
0 2
2 0
1 2 3
2 2 2
3 0 3
2 3
0 0
0 10
1 5 15
1 2 15
2 10 10
 */
