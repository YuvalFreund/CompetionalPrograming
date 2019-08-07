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

int main() {
    int size;
    int operations;
    int m,n;
    while (scanf("%d",&size)!=EOF){
        scanf("%d",&operations);
        vi values;
        values.push_back(1);
        vi zero_vector;
        vi negative_vector;
        int counter=1;
        int temp;
        string operation;
        string out="";
        for(int i=0; i<size;i++){
            cin>>temp;
            values.push_back(temp);
            if(temp==0){
                zero_vector.push_back(counter);
            }
            if (temp < 0){
                negative_vector.push_back(counter);
            }
            counter++;
        }
        for(int k=0; k<operations; k++){
            cin>>operation>>m>>n;
            int tmp_value;
            if(operation=="C"){
                tmp_value = values[m];
                if(tmp_value==0) {
                    auto iter = find(zero_vector.begin(), zero_vector.end(), m);
                    zero_vector.erase(iter);
                }else if(tmp_value<0){
                    auto iter = find(negative_vector.begin(), negative_vector.end(), m);
                    negative_vector.erase(iter);
                }
                values[m] = n;
                if(n<0){
                    auto iter = lower_bound(negative_vector.begin(), negative_vector.end(), m);
                    negative_vector.insert(iter,m);
                } else if (n==0){
                    auto iter = lower_bound(zero_vector.begin(), zero_vector.end(), m);
                    zero_vector.insert(iter,m);
                }
            }
            if (operation == "P"){
                int zero_count;
                vector<int>::iterator  upper_zero_bound = upper_bound(zero_vector.begin(), zero_vector.end(), n);
                vector<int>::iterator  lower_zero_bound = lower_bound(zero_vector.begin(), zero_vector.end(), m);
                vector<int>::iterator vec_zero_iter = lower_zero_bound ;
                for(zero_count = 0;vec_zero_iter!=upper_zero_bound;vec_zero_iter++){
                    zero_count++;
                }
                if(zero_count>0){
                    out+="0";
                }else{
                    vector<int>::iterator upper_negative_bound  = upper_bound(negative_vector.begin(), negative_vector.end(), n);
                    vector<int>::iterator lower_negative_bound = lower_bound(negative_vector.begin(), negative_vector.end(), m);
                    vector<int>::iterator vec_iter = lower_negative_bound ;
                    int negative_count;
                    for(negative_count = 0;vec_iter!=upper_negative_bound;vec_iter++){
                        negative_count++;
                    }
                    if(negative_count%2==0){
                        out+="+";
                    }else{
                        out+="-";
                    }
                }
            }
        }
        cout<<out<<endl;
    }
    return 0;
}