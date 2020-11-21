// 인접 행렬 <Adjacency Matrix>
bool visit[MAXN];   // 정점들을 한번씩만 방문하기 위해 방문 체크하는 배열
bool G[MAXN][MAXN]; // 그래프 정보를 담고있는 배열
queue<int> Q;

void bfs(int v) // v를 시작점으로 하는 dfs
{
    Q.push(v);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (visit[cur]) continue; // 방문한 점이라면 무시
        visit[cur] = true;        // 아니라면 방문 체크
        printf("%d ", cur);
        for (int i = 1; i <= N; i++) {
            if (G[cur][i]) // 0이 아니라면 cur와 i가 인접해있다는 의미
                Q.push(i);
        }
    }
}

// 인접 리스트 <Adjacency List>
bool visit[MAXN];      // 정점들을 한번씩만 방문하기 위해 방문 체크하는 배열
vector<vector<int>> G; // 그래프 정보를 담고있는 배열
queue<int> Q;

void bfs(int v) // v를 시작점으로 하는 dfs
{
    Q.push(v);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (visit[cur]) continue; // 방문한 점이라면 무시
        visit[cur] = true;        // 아니라면 방문 체크
        printf("%d ", cur);
        for (int i = 0; i < G[cur].size(); i++) { Q.push(G[cur][i]); } // 인접한 정점들이므로 단순 push
    }
}