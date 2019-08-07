#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
void func(string &s,vector<pair<string,int>> &vector1){
    int counter=0;
    for(auto &p:vector1){
        if(counter>=10) break;
        if(p.first.find(s)!=string::npos){
            if(counter==0)
                cout<<p.second;
            else
                cout<<" "<<p.second;
            counter++;
        }
    }
    if(counter==0) cout<<-1;
    cout<<endl;
}

int main() {
    int N,Q;
    string s;
    cin>>N;
    vector<pair<string,int>> vector1;
    for (int i = 1; i <=N; ++i) {
        cin>>s;
        vector1.push_back(make_pair(s,i));
    }
    sort(vector1.begin(),vector1.end(),[](const pair<string,int> p1,const pair<string,int> p2){
        if(p1.first.size() != p2.first.size()) return p1.first.size() < p2.first.size();
        else if(p1.first != p2.first) return p1.first < p2.first;
        else return p1.second<p2.second;
    });
    cin>>Q;
    while(Q--){
        cin>>s;
        func(s,vector1);
    }
    return 0;
}