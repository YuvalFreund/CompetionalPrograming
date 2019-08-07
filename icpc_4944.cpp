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
class participant{
    int index;
    int threshold;
    int paying;
public:
    participant(int index,int threshold ):index(index),threshold(threshold){
        paying = 0;
    }
    int get_index(){
        return this->index;
    }
    int get_threshold(){
        return this->threshold;
    }
    int get_paying(){
        return this->paying;
    }
    void  set_paying(int amount){
        this->paying = amount;
    }
    void inc_paying(){
        this->paying++;
    }

};
bool sort_participant_by_index(participant A, participant B){
    return A.get_index() < B.get_index();
}
bool sort_participant_by_threshold(participant A, participant B){
    if(A.get_threshold() == B.get_threshold()){
        return A.get_index() < B.get_index();
    }
    return A.get_threshold()>B.get_threshold();
}
int main(){
    int cases , temp;
    cin>>cases;
    for (int i = 0; i < cases; ++i) {
        vector<participant> participants;
        int avg, total, people, sum = 0;
        cin>>total;
        cin>>people;
        for (int j = 0; j < people; ++j) {
            cin >> temp;
            participants.emplace_back(participant(j, temp));
            sum += temp;
        }
        if(sum<total){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        sort(participants.begin(),participants.end(),sort_participant_by_threshold);

        int temp_people = people;
        while (total>0){
            avg = total / temp_people;
            int to_add = temp_people;
            if(avg==0){
                for (int j = 0; j < total; ++j) {
                    participants[j].inc_paying();
                }
                total=0;
            } else{
                sum = 0;
                for (int j = 0; j < to_add; ++j) {
                    if(participants[j].get_threshold() - participants[j].get_paying()<=avg){
                        sum+= participants[j].get_threshold()-participants[j].get_paying();
                        participants[j].set_paying(participants[j].get_threshold());
                        temp_people--;
                    }
                    else{
                        participants[j].set_paying(participants[j].get_paying()+avg);
                        sum+=avg;
                    }
                }
                total-=sum;
            }
        }
        sort(participants.begin(),participants.end(),sort_participant_by_index);
        for(int k=0; k<people-1; k++){
            cout<<participants[k].get_paying()<<" ";
        }
        cout<<participants[people-1].get_paying();
        cout<<endl;
    }

    return 0;
}