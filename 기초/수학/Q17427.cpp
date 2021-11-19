#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    long long int result = 0;

    for(int i = 1; i <= N; ++i) {
        result += N/i * i;
    }

    printf("%lld\n", result);

    return 0;
}
