#include <bits/stdc++.h>

#define RangeE 15
#define RangeS 28
#define RangeM 19

using namespace std;

int main(void) {
    int E, S, M;

    scanf("%d%d%d", &E, &S, &M);

    if(E == RangeE)
        E = 0;
    if(M == RangeM)
        M = 0;

    int result = S;

    while(result % RangeE != E || result % RangeM != M)
        result += RangeS;

    printf("%d\n", result);

    return 0;
}
