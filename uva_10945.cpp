#include <iostream>
#include <vector>
#include <string>
#include <stdbool.h>
using std::string;
bool check_pali(string string1){
    int len = static_cast<int>(string1.size());
    len--;
    for(int i=0; i<len; i++){
        if (string1[i] != string1[len]){
            return  false;
        }
        len--;
    }
    return true;
}
using namespace std;
int main() {
    string buf;
    while(getline(cin,buf)){
        if (check_pali(buf)){
            cout<<"You won't be eaten!"<<endl;
        } else{
            cout<<"Uh oh.."<<endl;
        }
    }
    return 0;
}
