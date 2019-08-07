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
        this->letters = vector<trie*>(11, NULL);
    }
    int get_active(){
        int count = 0;
        for(int i =0; i<11; i++){
            if(letters[i]!=NULL) count++;
        }
        return count;
    }
    bool add_word(string s){
        trie* current = this;
        for(int i=0; i< s.size(); i++){
            if(current->letters[10]!=NULL){
                return false; //a shorter word was stopped
            }
            if(current->letters[s[i]-'0']!=NULL){
                current = current->letters[s[i]-'0'];
            }
            else{
                current->letters[s[i]-'0'] = new trie();
                int j = s[i];
                current = current->letters[s[i]-'0'];
            }
        }
        if(current->get_active()!=0){
            return false; //this word is prefix of exisitng word
        }
        current->letters[10] = new trie();
        return true;
    }
};

int main(){
    int cases;
    cin>>cases;
    for (int i = 0; i<cases; i++){
        trie words = trie();
        int words_num;
        cin>>words_num;
        string s;
        bool flag = true;
        bool temp_flag;
        for (int i=0; i<words_num; i++){
            cin>>s;
            temp_flag = words.add_word(s);
            if(!temp_flag){
                flag = temp_flag;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        };
    }
    return 0;
}