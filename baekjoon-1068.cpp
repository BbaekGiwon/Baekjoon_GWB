#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ct;     // children
vector<int> parent_of;      // 부모 기록
vector<char> deleted_node;  // 삭제 여부

void delete_subtree(int u) {
    deleted_node[u] = 1;               // 본인 삭제 표시 (리프거나 아니거나 무조건 표시)
    for (int v : ct[u]) {
        if (!deleted_node[v]) delete_subtree(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    ct.assign(N, {});
    parent_of.assign(N, -1);
    deleted_node.assign(N, 0);

    for (int child = 0; child < N; ++child) {
        int p; 
        cin >> p;
        parent_of[child] = p;
        if (p != -1) ct[p].push_back(child);
    }

    int del; 
    cin >> del;

    // (1) 부모의 children 목록에서 del 제거 (부모가 리프가 될 수 있게)
    if (parent_of[del] != -1) {
        auto &vec = ct[parent_of[del]];
        vec.erase(remove(vec.begin(), vec.end(), del), vec.end());
    }

    // (2) del 서브트리 삭제 표시
    delete_subtree(del);

    // (3) 리프 카운트: 삭제 안 된 노드 중에서, 삭제 안 된 자식이 하나도 없는 노드
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        if (deleted_node[i]) continue;
        bool has_alive_child = false;
        for (int v : ct[i]) {
            if (!deleted_node[v]) { has_alive_child = true; break; }
        }
        if (!has_alive_child) ++cnt;
    }

    cout << cnt << "\n";
    return 0;
}

