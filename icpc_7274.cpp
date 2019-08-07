#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    int T;
    while(cin >> T) {
        for (int t = 0; t < T; t++) {
            int N;
            cin >> N;
            priority_queue<ll, vector<ll>, greater<ll>> canvases;
            for (int i = 0; i < N; i++) {
                ll input;
                cin >> input;
                canvases.push(input);
            }

            // Color every couple of canvases / group of canvases:
            ll total_ink = 0;
            while (canvases.size() > 1) {
                // Color 2 canvases / group of canvases:
                ll color1 = canvases.top();
                canvases.pop();
                ll color2 = canvases.top();
                canvases.pop();

                // Count the ink:
                ll color_size = color1 + color2;
                total_ink += color_size;

                // Insert them as group:
                canvases.push(color_size);
            }

            // Print the result:
            cout << total_ink << endl;
        }
    }
    return 0;
}