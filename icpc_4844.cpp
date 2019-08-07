#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <map>
#include <queue>

#define ll long long
using namespace std;

bool f(vector<int> &vec){
    if(vec.empty()) return  true;
    int size=vec.size();
    for (int i = 0; i < size; ++i) {
        if(vec[i]< 2) continue;
        int curr=vec[i];
        vec.erase(vec.begin()+i);
        if(i==0 || i==size-1){
            if(f(vec)) return true;
        }else{
            int tmp=vec[i];
            vec[i-1]+=tmp;
            vec.erase(vec.begin()+i);
            if(f(vec)) return true;
            vec[i-1]-=tmp;
            vec.insert(vec.begin()+i,tmp);
        }
        vec.insert(vec.begin()+i,curr);
    }
    return false;
}

int main() {
    int T;
    cin>>T;
    string s;
    while (T--) {
        cin >>s;
        if(s.size()==1){
            cout<<0<<endl;
            continue;
        }
        int counter=1;
        char c=s[0];
        vector<int> v;
        for (int i = 1; i <s.size(); ++i) {
            if(s[i]!=c)  {
                v.push_back(counter);
                counter=1;
                c=s[i];
                if(i==s.size()-1)
                    v.push_back(counter);
            }else{
                counter++;
                if(i==s.size()-1)
                    v.push_back(counter);
            }
        }
        if(f(v)) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}