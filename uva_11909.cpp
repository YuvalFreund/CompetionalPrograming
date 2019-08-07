#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <fstream>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;


#define EPS 1e-9
#define MAX_SIZE 100

using namespace std;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))

double DEG_to_RAD(double d) { return d * PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / PI; }

int main() {
    double l, w, h;
    double teta;
    while (cin >> l >> w >> h >> teta) {
        double alpha = RAD_to_DEG(atan(h / l));
        if (teta < alpha) {
            double answer = l * w * h - (l * l * w * (tan(DEG_to_RAD(teta))) / 2);
            printf("%.3f", answer);
            cout << " mL\n";
        } else {
            double answer = h * w * h / (tan(DEG_to_RAD(teta)) * 2);
            printf("%.3lf", answer);
            cout << " mL\n";
        }
    }

//    int num_points;
//    while(scanf("%d", &num_points)) {
//        set<pair<double, double>> px, py;
//        for(int i=0;i<num_points;i++) {
//            double x,y;
//            cin >> x >> y;
//            px.insert(make_pair(x,y));
//            py.insert(make_pair(y,x));
//        }
//
//        sort(px.begin(), px.end());
//        sort(py.begin(), py.end());
//
//        
//    }

    return 0;
}