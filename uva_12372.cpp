#include <iostream>
#include <vector>
#include <stdbool.h>
#define BOX 20
using namespace std;
int main() {
    int arr [3] = {0,0,0};
    int cases = 0;
    bool flag;
    scanf("%d",&cases);
    for (int i=0; i<cases; i++) {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        flag = arr[0] <= BOX && arr[1] <= BOX && arr[2] <= BOX;
        if (flag) {
            cout << "Case " << i + 1 << ": good" << endl;
        } else
            cout << "Case " << i + 1 << ": bad" << endl;
    }
    return 0;
}
