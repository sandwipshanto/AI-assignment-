#include <bits/stdc++.h>
using namespace std;

void uniformCostSearch(vector<vector<pair<int, int>>>& graph, int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distance(graph.size(), INT_MAX);
    vector<bool> visited(graph.size(), false); 

    pq.push({0, start});
    distance[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == end) {
            cout << "Shortest distance from " << start << " to " << end << " is: " << distance[u] << endl;
            return;
        }

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    cout << "No path exists from " << start << " to " << end << endl;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges;

    vector<vector<pair<int, int>>> graph(numNodes);

    for (int i = 0; i < numEdges; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }

    int start, end;
    cin >> start >> end;

    uniformCostSearch(graph, start, end);

    return 0;
}
