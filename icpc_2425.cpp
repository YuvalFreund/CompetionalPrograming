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

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;
const int INF = 1e9;

void Dijkstra(const vector<vii>& g, int s, vi& dist) {
    dist = vi(g.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ii front = q.top(); q.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // We may have found a shorter way to get to u after inserting it to q.
        // In that case, we want to ignore the previous insertion to q.
        for (ii next : g[u]) {
            int v = next.first, w = next.second;
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    int cases,N,E,T,M;
    cin>>cases;
    string empty;
    for (int j = 0; j <cases ; ++j) {
        getline(cin,empty);
        int a, b, dist;
        cin>>N>>E>>T>>M;
        vvii graph(M);
        vi dists(N);
        for(int i =0; i<N;i++){    ;
            graph.emplace_back(vii());
        }
        for (int i = 0; i < M; ++i) {
            cin>>a>>b>>dist;
            graph[b-1].emplace_back(make_pair(a-1,dist));
        }
        Dijkstra(graph,E-1,dists);
        int count = 0;
        for(int i=0; i<N; i++){
           if(dists[i]<=T) count++;
        }
        cout<<count;
        if(j<cases-1){
            cout<<endl<<endl;
        }
        else cout<<endl;

    }
    return 0;
}