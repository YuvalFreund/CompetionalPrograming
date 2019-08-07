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
#include <sstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;


using namespace std;

int main() {
    string line;
    int loops = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater_equal<pair<int,pair<int,int>>>> heap;
    int start, interval;
    vector<string> words;
    while (getline(cin,line)){
        //cout<<"line is :"<<line<<endl;
        std::stringstream data(line) ;
        while(getline(data,line,' ')){
            words.push_back(line);
        }
        if(words[0]=="Register"){
            start = stoi(words[1], nullptr, 10);
            interval = stoi(words[2], nullptr, 10);
            pii temp1 = make_pair(start,interval);
            pair<int,pair<int,int>> temp2 = make_pair(interval, temp1);
            heap.push(temp2);
            words.clear();
        }
        else if (words[0]=="#"){
            words.clear();
            continue;
        }
        else {
            loops = stoi(words[0], nullptr, 10);
            break;
        }
    }
    pair<int,pair<int,int>> result;
    pii init_val;
    pair<int,pair<int,int>> new_val;
    int updated;
    for (int i=0; i<loops; i++){
        result = heap.top();
        heap.pop();
        init_val = result.second;
        updated = result.first;
        updated +=init_val.second;
        new_val = make_pair(updated,init_val);
        heap.push(new_val);
        cout<<init_val.first<<endl;
    }
    return 0;
}