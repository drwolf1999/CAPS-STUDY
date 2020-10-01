#include <stdio.h>

void Sequence(int idx, int A[8], int N, int M) { // A의 (idx-1) 위치 까지 채웠고, N까지 사용 가능하며, 길이 M을 요구할 때
    if (idx == M) { // A의 길이가 M을 만족시킴
        for (int i = 0; i < M; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
        return;
    }
    int last = 0; // 초기에는 0에서 시작
    if (idx > 0) last = A[idx - 1]; // 만약 A의 길이가 1 이상이면 A의 마지막 원소로 설정
    for (int i = last + 1; i <= N; i++) { // 사전 순으로 출력하기 위함
        A[idx] = i; // idx위치에 i를 저장
        Sequence(idx + 1, A, N, M); // A의 idx 위치 까지 채웠고, N까지 사용 가능하며, 길이 M을 요구할 때
    }
}


int main() {
    int N, M;
    int A[8];
    scanf("%d %d", &N, &M);
    Sequence(0, A, N, M);
    return 0;
}