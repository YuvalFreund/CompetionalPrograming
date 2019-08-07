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
#define EPS 1e-9
bool isZero(int n){
    return n<=EPS &&n>=-EPS;
}

int main() {
    ll res[64] = {0};
    res[1] = 1;
    res[2] = 1;
    res[3] = 1;
    for (int k = 4; k < 64; k++) {
        res[k] = res[k - 1] + res[k - 2] + res[k - 3];
    }
    int index = 0;
    while (1) {
        int temp;
        cin >> temp;
        if (temp == 0) break;
        ll out = res[temp];
        index++;
        cout << "Case "<<index<<": "<<out << endl;
    }
    return 0;
}