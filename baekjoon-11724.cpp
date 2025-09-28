#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // 대표자 찾기 (경로 압축)
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    // 두 집합 합치기
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return; // 이미 같은 집합

        // rank 기준으로 최적화
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

int main(void) {
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }

    // 대표자 개수 세기
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (uf.find(i) == i) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}

