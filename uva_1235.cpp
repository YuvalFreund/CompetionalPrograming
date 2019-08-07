 Home
Problem
Status
Contest
User
Group
Forum
Article
Logout
yuval_freund
Begin: 2019-06-18 17:30 UTC+3
 Class 12
End: 2019-06-18 19:15 UTC+3
01:45:00
Elapsed: 01:52:44 Running Remaining: -1:52:15
Overview
Problem
Status
Rank (01:45:00)
0 Comments
Previous12345…Next
Username
Prob
	Result 
	Time
(ms)	Mem
(MB)	Lang 
	Submit Time
yuval_freund
B
Accepted
690		
C++
41 min ago
           
All Copyright Reserved © 2010-2019 Xu Han
Server Time: 2019-06-18 19:22:44 UTC+3

#20090340 | yuval_freund's solution for [UVA-1235] [Problem B]
Status
Accepted
Time
690ms
Length
3447
Lang
C++11 5.3.0
Submitted
2019-06-18 18:41:07
Shared

RemoteRunId
23487824
Select Code
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

using namespace std;
/*
vector<iii> edges;
#define S 1000
#define T 1001
,string.
void connect(i,j,vectormatrix);

int main() {
    string line;
    while (getline(cin, line) {
        vector<string> matrix;
        while (line != "") {
            matrix.push_back(line);
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                connect(i,j,matrix);
                if(matrix[i][j]=='W')
                    edges.push_back(make_pair(1,make_pair(S,i*j+j)));
                else if(matrix[i][j]=='N')
                    edges.push_back(make_pair(1,make_pair(i*j+j,T)));
            }
        }
    }
    return 0;
}
*/


struct unionfind {
    vector<int> rank;
    vector<int> parent;

    unionfind (int size) {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        for(int i=0;i<size;i++) parent[i]=i;
    }

    int find(int x) {
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x) {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember;
        }
        return x;
    }

    void unite(int p, int q) {
        p = find(p);
        q = find(q);
        if(q==p) return;
        if(rank[p] < rank[q]) parent[p] = q;
        else parent[q] = p;
        if(rank[p] == rank[q]) rank[p]++;
    }
};
int Kruskal(vector<iii>& edges, int n) {
    sort(edges.begin(), edges.end());
    int mst_cost = 0;
    unionfind components(n);
    for (iii e : edges) {
        if (components.find(e.second.first) != components.find(e.second.second)) {
            mst_cost += e.first;
            components.unite(e.second.first, e.second.second);
        }
    }
    return mst_cost;
}
int get_dist(string a, string b) {
    int all=0;
    for(int i= 0 ; i<4; i++) {
        int val = abs (a[i]-b[i]);
        all += min (10 -(val),val);
    }
    return all;
}
int main(){
    int cases;
    cin>>cases;
    while(cases--) {
        int vert;
        cin >> vert;
        map<string, int> mp;
        vector<string> codes;
        for (int i = 0; i < vert; i++) {
            string temp;
            cin >> temp;
            codes.push_back(temp);
            mp[temp] = i;
        }
        vector<iii> graph;
        for (int i = 0; i < vert; i++) {
            for (int j =0; j < vert; j ++){
                if(i!=j){
                    int dist = get_dist(codes[i],codes[j]);
                    graph.push_back(make_pair(dist,make_pair(mp[codes[j]],mp[codes[i]])));
                }
            }
        }
        int min =100000;
        for(int k =0; k<vert; k++){
            int temp = get_dist("0000",codes[k]);
            if(temp<min) min= temp;
        }
        int result = Kruskal (graph, vert+1);
        cout<<result+min<<endl;
    }
    return 0;
}


Comment in Markdown
Preview:
