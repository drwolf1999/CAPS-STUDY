#include <stdio.h>
#include <stack>
using namespace std;
int N; // 사람 수
int H[100000], A[100000]; // 순서대로 사람 키, 정답 배열
stack<int> S; // 스택 선언
int main() {
	scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &H[i]);
	for (int i = 0; i < N; i++) {
		while (!S.empty() && H[i] >= H[S.top()]) // 현재 사람(R)이 크다 --> H[S.top()]은 G에 속함
            S.pop(); // 제거
        A[i] = S.size(); // B의 크기
		S.push(i); // 인덱스를 저장
	}
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	return 0;
}