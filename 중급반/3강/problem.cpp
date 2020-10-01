#include <limits.h>
#include <stdio.h>

int N, K; // 필요한 LAN 선 개수, 가지고 있는 LAN 선 개수
long long LAN[10001]; // LAN선 정보

bool Possible(long long CUT) { // CUT으로 잘랐을 때 N 개 이상 얻을 수 있는가?
    int cnt = 0;
    for (int i = 0; i < K; i++) cnt += LAN[i] / CUT; // int / int --> int (floor 적용)
    return cnt >= N;
}

int main() {
    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++) scanf("%lld", &LAN[i]);

    long long L = 0;
    long long R = LLONG_MAX; // long long int 의 최댓값
    long long ANS = 0;

    while (L <= R) {
        long long X = (L + R) / 2;

        if (Possible(X)) { // X에 대해 가능하다.
            L = X + 1;
            if (X > ANS) ANS = X;
        } else
            R = X - 1;
    }

    printf("%lld\n", ANS);

    return 0;
}