typedef long long int LL;

LL Sum_D_C(LL N) {
    if (N == 0LL) return 0LL;
    if (N % 2) return Sum_D_C(N - 1) + N; // 짝수로 변형
    return 2 * Sum_D_C(N / 2) + (N / 2) * (N / 2);
}