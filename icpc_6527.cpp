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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

using namespace std;
long  long calc(long long a, long long b);
long long long_pow(long long base, long long exp){
    long long result =1;
    while(exp>0){
        result*=base;
        exp--;
    }
    return  result;
}
int main() {
    long long a, b;
    while (cin>>a>>b){
        long long result = calc(a,b+1);
        cout<<result<<endl;
    }
    return 0;
}

long long calc(long long a, long long b){
    vector<long long> a_ones;
    vector<long long> b_ones;
    long long a_len = 0 , b_len = 0;
    long long a_sum = 0, b_sum = 0 ;
    long long temp_a = a;
    long long temp_b = b;
    while(temp_a > 0){
        if (temp_a % 2 == 1) a_ones.push_back(a_len);
        temp_a/=2;
        a_len++;
    }
    while(temp_b > 0){
        if (temp_b % 2 == 1) b_ones.push_back(b_len);
        temp_b/=2;
        b_len++;
    }
    temp_a = a;
    temp_b = b;
    for(long long i = a_len; i > 0; i--){
        if((temp_a>>i) % 2 == 1){
            a_sum += (i * long_pow(2,i-1));
        }
    }
    for(long long i = 0 ; i < a_ones.size(); i++){
        a_sum+= i*long_pow(2, a_ones[a_ones.size() - i - 1]);
    }
    for(long long i = b_len; i >0; i--){
        if((temp_b>>i)%2==1){
            b_sum+= (i*long_pow(2,i-1));
        }
    }
    for(long long i = 0 ; i < b_ones.size(); i++){
        b_sum+= i*long_pow(2, b_ones[b_ones.size() - i - 1]);
    }
    return b_sum - a_sum;
}