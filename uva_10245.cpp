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

double dist(pair<double, double> p1, pair<double, double> p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.first - p2.first, p1.second - p2.second);
}           // return double

double get_dist(pair<double, double> p, double d, set<pair<double, double>> &px) {
    double shem = INF;
    set<pair<double, double>> result;
    auto i = px.lower_bound(make_pair(p.first - d, p.second));
    while (i != px.end()) {
        if ((*i).first == p.first && (*i).second == p.second) {
            ++i;
            continue;
        }
        if ((*i).first > p.first) {
            break;
        }
        if ((*i).second < p.second + d && (*i).second > p.second - d) {
            result.insert((*i));
        }
        ++i;
    }
    auto j = result.begin();
    while (j != result.end()) {
        if (dist(p, (*j)) < shem) {
            shem = dist(p, (*j));
        }
        ++j;
    }
    return shem;
}

int main() {
    int num_points;
    while (scanf("%d", &num_points)) {
        if(num_points == 0) {
            break;
        }
        set<pair<double, double>> px, py;
        bool shit = false;
        for (int i = 0; i < num_points; i++) {
            double x, y;
            cin >> x >> y;
            if(px.insert(make_pair(x, y)).second == false) {
                shit = true;
            }
        }
        if(shit) {
            printf("0.0000\n");
            continue;
        }
        double dist = 10001;
        auto i = px.begin();
        while (i != px.end()) {
            double temp = get_dist(*i, dist, px);
            if (temp < dist) {
                dist = temp;
            }
            ++i;
        }
        if (dist > 10000) {
            cout << "INFINITY\n";
        } else {
            printf("%.4lf\n", dist);
        }
    }
    return 0;
}
