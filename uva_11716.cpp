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
bool  is_squared(double n){
    double res = sqrt(n);
    return res - int(res) == 0;
}
int main() {
    int cases;
    string tem;
    cin>>cases;
    getline(cin,tem);
    for(int i=0; i<cases; i++){
        string temp;
        getline(cin,temp);
        if (!is_squared(temp.size())){
            cout<<"INVALID"<<endl;
            continue;
        }
        double root = sqrt(temp.size());
        for (int k = 0; k<root; k++){
            for(int m = 0; m<temp.size(); m+=root){
                cout<<temp[m+k];
            }
        }
       cout<<endl;
    }
    return 0;
}