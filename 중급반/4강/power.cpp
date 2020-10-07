#include <stdio.h>



typedef long long int LL;
const LL MOD = 1'000'000'007LL;

LL Power_D_C(LL A, LL N) {
    if (!N) return 1LL;
    LL p = Power_D_C(A, N / 2);
    p = (p * p) % MOD;
    if (N % 2) p = (p * A) % MOD;
    return p;
}