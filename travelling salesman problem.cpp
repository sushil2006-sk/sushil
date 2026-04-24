#include <iostream>
#include <climits>
using namespace std;

int n = 4; // number of cities

int tsp(int graph[][4], bool visited[], int pos, int count, int cost, int ans) {
    if (count == n && graph[pos][0]) {
        return min(ans, cost + graph[pos][0]);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[pos][i]) {
            visited[i] = true;
            ans = tsp(graph, visited, i, count + 1, cost + graph[pos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main() {
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    bool visited[4] = {true, false, false, false};

    int ans = tsp(graph, visited, 0, 1, 0, INT_MAX);

    cout << "Minimum cost: " << ans;

    return 0;
}