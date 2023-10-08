#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_CITIES = 10;
const int INF = INT_MAX;

int n, cost = 0;
int a[MAX_CITIES][MAX_CITIES];
vector<int> visited(MAX_CITIES, 0);

void getCostMatrix() {
    cout << "Enter the number of cities: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
        visited[i] = 0;
    }
}

void findMinCost(int city) {
    visited[city] = 1;
    cout << city + 1 << " -> ";

    int nearestCity = INF;
    int minCost = INF;

    for (int i = 0; i < n; i++) {
        if (a[city][i] != 0 && !visited[i]) {
            int tempCost = a[city][i] + findMinCost(i);
            if (tempCost < minCost) {
                minCost = tempCost;
                nearestCity = i;
            }
        }
    }

    if (nearestCity == INF) {
        nearestCity = 0;
        cost += a[city][nearestCity];
    }
}

void printMinimumCost() {
    cout << "\nThe Path is:\n";
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            findMinCost(i);
            break;
        }
    }
    cout << "\n\nMinimum cost: " << cost << "\n";
}

int main() {
    getCostMatrix();
    
    printMinimumCost();
    return 0;
}

