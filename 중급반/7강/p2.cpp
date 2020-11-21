#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAXN 100000
#define INF (1 << 30)
using namespace std;
int D[MAXN + 100];
void bfs(int N, int K) {
    for (int i = 0; i < MAXN + 100; i++) D[i] = INF;
    queue<int> Q;
    Q.push(N);
    D[N] = 0;
    vector<bool> V(MAXN + 100, false);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (V[cur]) continue;
        if (cur - 1 >= 0 && D[cur - 1] > D[cur] + 1) {
            D[cur - 1] = D[cur] + 1;
            Q.push(cur - 1);
        }
        if (cur + 1 <= MAXN && D[cur + 1] > D[cur] + 1) {
            D[cur + 1] = D[cur] + 1;
            Q.push(cur + 1);
        }
        if (2 * cur <= MAXN && D[cur * 2] > D[cur] + 1) {
            D[cur * 2] = D[cur] + 1;
            Q.push(cur * 2);
        }
        V[cur] = true;
    }
    printf("%d", D[K]);
}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    bfs(N, K);
    return 0;
}