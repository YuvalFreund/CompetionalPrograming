#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
int main() {
    int number;
    while (scanf("%d",&number)!=EOF){
        if(number % 6 == 0){
            cout << "Y"<<endl;
        } else{
            cout << "N"<<endl;
        }
    }
    return 0;
}
