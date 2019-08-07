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
#include <list>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

using namespace std;

int main() {
    string temp, prev_cut, next_cut;
    char prev_char, next_char;
    int seq_len = 0,max_len = 0;
    list<char> res;
    set<char> found;
    vector<string> words;
    while(cin>>temp){
        if(temp == "#") break;
        words.push_back(temp);
        if(temp.length()>max_len) max_len = temp.length();
    }

    for (;seq_len <= max_len ;seq_len ++) {
        for (int i = 0; i < words.size()-1 ; ++i) {
            if(words[i].length()<seq_len) continue;
            prev_cut = words[i].substr(0,seq_len);
            next_cut = words[i+1].substr(0,seq_len);
           // cout<<"seq_len: "<<seq_len<<endl;
           // cout<<"prev cut: "<<prev_cut<<endl;
           // cout<<"next cut: "<<next_cut<<endl;

            if(next_cut == prev_cut) {
                prev_char = words[i][seq_len];
                next_char = words[i+1][seq_len];
            //    cout<<"prev char: "<<prev_char<<endl;
            //     cout<<"next char: "<<next_char<<endl;
                if (next_char != prev_char) {
                    if (found.find(prev_char) == found.end()
                        &&found.find(next_char) == found.end()
                        &&prev_char!=NULL) {
                        res.emplace_back(prev_char);
                        res.emplace_back(next_char);
                        found.insert(next_char);
                        found.insert(prev_char);
              //          cout<<"inserted: "<<prev_char<<","<<next_char<<endl;
                    } else {
                        if (found.find(next_char) == found.end()) {
                            for (auto it = res.begin(); it != res.end(); ++it) {
                                if ((*it) == prev_char) {
                                    it++;
                                    res.insert(it, next_char);
                                    found.insert(next_char);
                             //       cout << "inserted: " << next_char << endl;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for (auto it=res.begin(); it !=res.end(); ++it) {
        cout<<*it;
    }
    cout<<endl;
    return 0;
}