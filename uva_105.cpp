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

int main() {
    vector<int> starts;
    vector<int> endings;
    vector<vector<int>> right_heights(10000);
    vector<vector<int>> left_heights(10000);
    map<int, int> heights;
    int Li, Hi, Ri;
    int max_all=0;
    bool flag = false;
    while(scanf("%d %d %d",&Li, &Hi, &Ri)!=EOF){
        right_heights[Ri].push_back(Hi);
        left_heights[Li].push_back(Hi);
        if(max_all<Ri) max_all =Ri;
    }
    int build_count = 0;
    int curr_height = 0;
    for(int i = 0; i<max_all+1 ;i++ ) {
        int insertion_max = 0;
        if (!left_heights[i].empty()) {
            for (int j = 0; j < left_heights[i].size(); j++) {
                build_count++;
                auto it = heights.find(left_heights[i][j]);
                if (left_heights[i][j] > insertion_max) insertion_max = left_heights[i][j];
                if (it == heights.end()) {
                    heights.insert(make_pair(left_heights[i][j], 1));
                } else {
                    (*it).second++;
                }
            }
        }
        if (insertion_max > curr_height) {
            cout <<i<<" ";
            cout << insertion_max;
            curr_height = insertion_max;
            flag=true;
        }
        if (!right_heights[i].empty()) {
            for (int j = 0; j < right_heights[i].size(); j++) {
                build_count--;
                auto it = heights.find(right_heights[i][j]);
                (*it).second--;
                if((*it).second == 0){
                    heights.erase(it);
                }
            }
            if(build_count==0){
                curr_height =0;
                cout<<i<<" ";
                cout<<"0";
                flag=true;

            }
            else {
                auto rit = heights.rbegin();
                if ((*(rit)).first < curr_height) {
                    curr_height = (*(rit)).first;
                    cout << i << " ";
                    cout << curr_height;
                    flag=true;

                }
            }
        }
        if(flag && i<max_all){
            cout<<" ";
            flag = false;
        }
    }
    cout<<endl;
    return 0;
}