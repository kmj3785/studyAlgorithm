#include <bits/stdc++.h>

using namespace std;

int main(void) {
    bool is_decimal[1000001];
    fill_n(is_decimal, 1000001, true);
    is_decimal[0] = false;
    is_decimal[1] = false;

    int a, b;
    scanf("%d%d", &a, &b);

    for(int i = 2; i <= b; ++i) {
        if(is_decimal[i]) {
            for(int j = 2; i * j <= b; ++j) {
                is_decimal[i * j] = false;
            }
        }
    }

    for(int i = a; i <= b; ++i) {
        if(is_decimal[i])
            printf("%d\n", i);
    }
}
