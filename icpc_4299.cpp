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

int find_shortest_route(vector<vector<int>> &towns_map, int a, int b) {
    queue<int> route = queue<int>();
    route.push(a);
    route.push(0);
    vector<bool> visited = vector<bool>(towns_map.size(), false);
    while (!route.empty()) {
        int current_town = route.front();
        route.pop();
        int distance = route.front();
        route.pop();

        distance++;
        vector<int> roads = towns_map[current_town];
        for (int i = 0; i < roads.size(); i++) {
            if (roads[i] == 1 && i == b) {
                return distance;
            }
            if (!visited[i] && roads[i] == 1) {
                route.push(i);
                route.push(distance);
                visited[i] = true;
            }
        }
    }
    return 0;
}

void fill_probability(vector<vector<double>> &probabilities, int m, int R, int d) {
    // Check if value is already calculated:
    if (probabilities[m][d] != -1) {
        return;
    }

    // Exit terms:
    if (m <= 0) {
        probabilities[m][d] = 0;
        return;
    }
    if (m >= d * R) {
        probabilities[m][d] = 1;
        return;
    }
    if (d == 1) {
        if (m >= R) {
            probabilities[m][d] = 1;
        } else {
            probabilities[m][d] = (double) m / (double) R;
        }
        return;
    }

    // Calculate the probability:
    double sum = 0;
    for (int i = 1; i <= R; i++) {
        if (m - i <= 0) {
            continue;
        }
        fill_probability(probabilities, m - i, R, d - 1);
        sum += probabilities[m - i][d - 1];
    }
    probabilities[m][d] = ((double) 1 / R) * sum;
}

double calculate_probability(vector<vector<double>> &probabilities, int m, int R, int distance) {
    fill_probability(probabilities, m, R, distance);
    return probabilities[m][distance];
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int test_case = 0; test_case < test_cases; test_case++) {
        // Read input:
        int N, R; // N = amount of towns, R = ticket price
        cin >> N >> R;
        vector<vector<int>> towns_map = vector<vector<int>>(N, vector<int>(N, 0));
        for (int n = 0; n < N; n++) {
            string input;
            cin >> input;
            for (int i = 0; i < N; i++) {
                if (input[i] == 'Y') {
                    towns_map[n][i] = 1;
                }
            }
        }
        int C; // C = amount of couples
        cin >> C;

        // Calculate the probability per couple:
        cout << "Case " << test_case + 1 << endl;
        vector<vector<double>> probabilities = vector<vector<double>>();
        for (int c = 0; c < C; c++) {
            int a, b, m; // a = from town, b = to town, m = spendable money
            cin >> a >> b >> m;
            a--;
            b--;
            if(m>=probabilities.size()) {
                int add_amount = m-probabilities.size()+1;
                for(int i=0;i<add_amount;i++) {
                    probabilities.emplace_back(vector<double>(N, -1));
                }
            }
            int distance = find_shortest_route(towns_map, a, b);
            double probability = calculate_probability(probabilities, m, R, distance);
            printf("%.6lf\n", probability);
        }

        // Print space between cases:
        if (test_case != test_cases - 1) {
            cout << endl;
        }
    }
    return 0;
}