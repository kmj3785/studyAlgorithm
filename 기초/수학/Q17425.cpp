#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    scanf("%d", &T);

    vector<long long> f(1000001);

    vector<long long> g(1000001);

    for(int i = 1; i <= 1000000; ++i) {
        for(int j = 1; i * j <= 1000000; ++j) {
            f[i * j] += i;
        }
    }

    for(int i = 1; i <= 1000000; ++i) {
        g[i] = g[i-1] + f[i];
    }

    int N;

    for(int i = 0; i < T; ++i) {
        scanf("%d", &N);
        printf("%lld\n", g[N]);
    }

}
