#include <bits/stdc++.h>
#define MAXN 50
using namespace std;
int dx[] = {1, -1, 0};
int dy[] = {1, -1, 0};
int N, M;
int G[MAXN + 2][MAXN + 2];
void dfs(int x, int y) {
    if (!G[x][y]) return;
    G[x][y] = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2 && j == 2) continue;
            dfs(x + dx[i], y + dy[j]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> M >> N) {
        if (N == 0 && M == 0) break;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) cin >> G[i][j];
        int landCount = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (G[i][j]) { // 섬일 때만 호출
                    dfs(i, j);
                    landCount++;
                }
        cout << landCount << "\n";
    }
    return 0;
}
