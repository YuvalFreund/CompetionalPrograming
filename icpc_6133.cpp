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
class trie{
public:
    vector<trie*> letters;
    trie(){
        this->letters = vector<trie*>(27, NULL);
    }
    int get_active(){
        int count = 0;
        for(int i =0; i<27; i++){
            if(letters[i]!=NULL) count++;
        }
        return count;
    }
    void add_word(string s){
        trie* current = this;
        for(int i=0; i< s.size(); i++){
            if(current->letters[s[i]-'a']!=NULL){
                current = current->letters[s[i]-'a'];
            }
            else{
                current->letters[s[i]-'a'] = new trie();
                int j = s[i]-'a';
                current = current->letters[s[i]-'a'];
            }
        }
        current->letters[26] = new trie();
    }
};


int counter(string s){
    int count=1;
    int size = s.size();
    while(size!=0){
        if(size%2==1)break;
        size/=2;
        if(s.substr(0,size)!= s.substr(size,size)){
            break;
        }
        count++;
    }
    return count;
}

void get_result(trie* t,int count,vi& vec){
    int size = t->get_active();
    if(size==0){
        vec.push_back(count);
    } else if(size==1){
        for(int i=0; i<27;i++) {
            if (t->letters[i] != NULL) {
                get_result(t->letters[i], count, vec);

            }
        }
    }
    else {
        for (int i = 0; i < 27; i++) {
            if (t->letters[i] != NULL) {
                if(i==26){
                    get_result(t->letters[i], count, vec);
                }else{
                    get_result(t->letters[i], count+1, vec);
                }
            }
        }
    }
}
int main(){
    int input;
    while(cin>>input) {
        vi result;
        trie words = trie();
        string temp;
        for (int i = 0; i < input; i++) {
            cin >> temp;
            words.add_word(temp);
        }
        if(words.get_active()==1){
            get_result(&words, 1, result);
        }else{
            get_result(&words,0, result);
        }
        int usm=0;
        for (int k = 0; k < result.size(); k++) {
            usm += result[k];
        }
        double avg = (double)usm/(double)result.size();
        printf("%.2lf",avg);
        cout<<endl;
    }
    return 0;
}