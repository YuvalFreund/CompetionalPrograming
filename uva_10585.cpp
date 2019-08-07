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
    int cases;
    cin>>cases;
    while(cases--){
        int point_num;
        bool flag = true;
        set<pii> points;
        cin>>point_num;
        int x, y;
        double main_x=0, main_y=0;
        for(int i =0 ; i<point_num; i++){
            cin>>x>>y;
            pii xy = make_pair(x,y);
            points.insert(xy);
            main_x+=x;
            main_y+=y;
        }
        main_x/=point_num;
        main_y/=point_num;
        for (auto it = points.begin(); it!=points.end()   ;it ++) {
            pii temp = *it;
            //cout<<temp.first<<","<<temp.second<<endl;
            int temp_x = temp.first;
            int temp_y = temp.second;
            double dist_x = main_x - temp_x;
            double dist_y = main_y - temp_y;
            temp = make_pair(main_x+dist_x,main_y+dist_y);
            //cout<<temp.first<<","<<temp.second<<endl;
            if(points.find(temp)==points.end()){
                flag = false;
                break;
            }
        }
        if(flag)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}