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
#define K 15
#define N 1121
using namespace std;
vector<bool> sieve(int n){
    vector<bool> ps(n+1,true);
    ps[0] = false;
    ps[1] = false;
    int sqrtn = sqrt(n);
    for (int i = 0; i <= sqrtn; ++i) {
        if(ps[i]){
            for (int j = i*i; j <= n; j+=i) {
                ps[j] = false;
            }
        }
    }
    return ps;
}
int main() {
    vector<bool> first_line = sieve(N);
    vector<int> primes;
    for(int i=0; i<N; i++){
        if(first_line[i]==true){
            primes.push_back(i);
        }
    }
    ll P = primes.size();
    vector<vector<vector<int>>> all(P+1,vector<vi>(N, vector<int> (K, 0)));
    all[0][0][0]=1;
    for(int i=1;i<P+1; i++){
        int temp = primes[i-1];
        for(int j=0; j <N; j++){
            for(int m =0; m<=K; m++){
                if( m<K && j+temp <N){
                    all[i][j+temp][m+1] +=all[i-1][j][m];
                }
                all[i][j][m]+=all[i-1][j][m];
            }
        }
    }
    int num, dividers;
    while (1){
        cin>>num>>dividers;
        if(num == 0 && dividers == 0) break;
        else{
            cout<<all[P][num][dividers]<<endl;
        }

    }
    return 0;
}