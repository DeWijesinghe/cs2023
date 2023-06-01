#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max(); // Use maximum integer value as infinity

void Dijkstra(const vector<vector<int>>& weighted_adjacency_matrix, int source, vector<int>& distances) {
    int numVertices = weighted_adjacency_matrix.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances.resize(numVertices, INF); // Initialize distances to infinity
    distances[source] = 0; // Distance from the source to itself is 0
    pq.push(make_pair(distances[source], source)); // Push the source vertex into the priority queue

    while (!pq.empty()) {
        int u = pq.top().second; // Get the vertex with the minimum distance from the priority queue
        pq.pop();

        for (int v = 0; v < numVertices; v++) {
            int weight = weighted_adjacency_matrix[u][v]; // Get the weight between vertices u and v

            if (weight != 0 && distances[u] + weight < distances[v]) {
                // If there is a path from u to v (weight != 0) and the distance through u is smaller than the current distance to v
                distances[v] = distances[u] + weight; // Update the distance to v
                pq.push(make_pair(distances[v], v)); // Push v into the priority queue to explore its neighbors
            }
        }
    }
}

int main() {
    vector<vector<int>> weighted_adjacency_matrix = {
        { 0, 10, 0, 0, 15, 5 },
        { 10, 0, 10, 30, 0, 0 },
        { 0, 10, 0, 12, 5, 0 },
        { 0, 30, 12, 0, 0, 20 },
        { 15, 0, 5, 0, 0, 0 },
        { 5, 0, 0, 20, 0, 0 }
    };

    vector<vector<int>> distancesList(6);
    float totalTime;

    for (int i = 0; i < 6; i++) {
        Dijkstra(weighted_adjacency_matrix, i, distancesList[i]);
        totalTime=0;
        cout << "Shortest time from city " << i << " to other cities:" << endl;
        for (int j = 0; j < distancesList[i].size(); j++) {
            cout << "City " << j << ": " << distancesList[i][j] << endl;
            totalTime += distancesList[i][j];
        }
        cout <<"Average Time "<< totalTime/5 << endl;
    }
    return 0;
}
