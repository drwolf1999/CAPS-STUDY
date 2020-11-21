// 스택 version
// 인접 행렬 <Adjacency Matrix>
bool visit[MAXN];   // 정점들을 한번씩만 방문하기 위해 방문 체크하는 배열
bool G[MAXN][MAXN]; // 그래프 정보를 담고있는 배열
stack<int> S;

void dfs(int v) // v를 시작점으로 하는 dfs
{
    S.push(v);
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        if (visit[cur]) continue; // 방문한 점이라면 무시
        visit[cur] = true;        // 아니라면 방문 체크
        printf("%d ", cur);
        for (int i = 1; i <= N; i++) {
            if (G[cur][i]) // 0이 아니라면 cur 와 i가 인접
                S.push(i);
        }
    }
}

// 인접 리스트 <Adjacency List>
bool visit[MAXN];      // 정점들을 한번씩만 방문하기 위해 방문 체크하는 배열
vector<vector<int>> G; // 그래프 정보를 담고있는 배열
stack<int> S;

void dfs(int v) // v를 시작점으로 하는 dfs
{
    S.push(v);
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        if (visit[cur]) continue; // 방문한 점이라면 무시
        visit[cur] = true;        // 아니라면 방문 체크
        printf("%d ", cur);
        for (int i = 0; i < G[cur].size(); i++) S.push(G[cur][i]); // 인접 리스트에는 인접한 정보만 있으므로 단순 push
    }
}

/**
 * 재귀 구조는 스택 구조이므로 재귀로도 구현 가능하다.
 */
// 재귀 version
// 인접 행렬 <Adjacency Matrix>
bool visit[MAXN];   // 정점들을 한번씩만 방문하기 위해 방문 체크하는 배열
bool G[MAXN][MAXN]; // 그래프 정보를 담고있는 배열
void dfs(int v) {
    if (visit[v]) return;
    visit[v] = true;
    printf("%d ", v);
    for (int i = 1; i <= N; i++) {
        if (G[v][i]) dfs(i);
    }
}

// 인접 리스트 <Adjacency List>
bool visit[MAXN];      // 정점들을 한번씩만 방문하기 위해 방문 체크하는 배열
vector<vector<int>> G; // 그래프 정보를 담고있는 리스트

void dfs(int v) {
    if (visit[v]) return;
    visit[v] = true;
    printf("%d ", v);
    for (int i = 0; i < G[v].size(); i++) dfs(G[v][i]);
}