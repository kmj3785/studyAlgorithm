#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int T;
    scanf("%d", &T);

    int M, N, x, y;

    for(int i = 0; i < T; ++i) {
        scanf("%d%d%d%d", &M, &N, &x, &y);
        int j;
        for(j = x - 1; j < M * N; j += M) {
            if (j % N + 1 == y) {
                printf("%d\n", j + 1);
                break;
            }
        }
        if(j >= M * N)
            printf("-1\n");
    }
    return 0;

}
