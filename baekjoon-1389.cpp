#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    const int INF = 1e9;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

    for (int i = 1; i <= N; i++) dist[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        dist[A][B] = 1;
        dist[B][A] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int via = dist[i][k] + dist[k][j];
                if (via < dist[i][j]) dist[i][j] = via;
            }
        }
    }

    int bestUser = 1;
    int bestSum = INF;

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) sum += dist[i][j];

        if (sum < bestSum) {
            bestSum = sum;
            bestUser = i;
        }
    }

    cout << bestUser << "\n";
    return 0;
}

