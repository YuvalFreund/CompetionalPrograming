#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> ps(n + 1, true);
    ps[0] = false;
    ps[1] = false;
    int sqrtn = sqrt(n);
    for (int i = 0; i <= sqrtn; ++i) {
        if (ps[i]) {
            for (int j = i * i; j <= n; j += i) {
                ps[j] = false;
            }
        }
    }
    return ps;
}

int main() {
    int L, U;
    vector<bool> isPrime = sieve(10000);
    vector<int> primes;
    for (int i = 0; i < isPrime.size(); i++) {
        if (isPrime[i] == true) {
            primes.push_back(i);
        }
    }
    int num, count, high, low, sum;
    while(1){
        cin>>num;
        if(num==0) break;
        if(num==2 || num ==3){
            cout<<"1"<<endl;
            continue;
        }
        high=1; low =0; count =0;
        sum=5;
        while(primes[high]<=num){
            if(sum==num){
                count++;
                sum-=primes[low];
                low++;
                continue;
            }
            if(sum>num){
                sum-=primes[low];
                low++;
                continue;
            }
            if(sum<num){
                high++;
                sum+=primes[high];
                continue;
            }
        }
        cout<<count<<endl;
    }

    return 0;
}