#include <stdio.h>
int main() {
    int i, j;
    int V[10], NOT[10] = {0, }; // 각 사람의 고유 번호 / 100을 만족하지 않는 나머지 사람은 1로 체크
    int E = 0, VS = 0; // 존재 여부 / V 배열의 합계
    for (i = 0; i < 10; i++) {
        scanf("%d", &V[i]);
        VS += V[i]; // 합계를 구해줌
    }
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (!E && V[i] + V[j] == VS - 100) { // 아직 못 찾았고, 8명을 제외한 2명이라면
                NOT[i] = 1; // 제외
                NOT[j] = 1; // 제외
                E = 1; // 찾았다는 것을 체크
            }
        }
    }
    if (!E) { // 못 찾았다면 -1 출력
        printf("-1");
        return 0;
    }
    for (i = 0; i < 10; i++) {
        if (NOT[i] == 1) continue; // NOT[i] 가 1이라면 8명을 제외한 사람임
        printf("%d ", V[i]);
    }
    return 0;
}