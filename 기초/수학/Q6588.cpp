#include <bits/stdc++.h>

using namespace std;

bool is_decimal[1000001];

void CalculateDecimal(void) {
    fill_n(is_decimal, 1000001, true);
    is_decimal[0] = false;
    is_decimal[1] = false;

    for(int i = 2; i <= 1000000; ++i) {
        if(is_decimal[i]) {
            for(int j = 2; i * j <= 1000000; ++j) {
                is_decimal[i * j] = false;
            }
        }
    }
}

int main(void) {

    CalculateDecimal();

    int n = 1;
    scanf("%d", &n);

    while(n != 0) {
        int a, b;
        bool is_wrong = true;

        for(b = n; b >= n/2; --b) {
            if(is_decimal[b] && is_decimal[n-b]) {
                a = n-b;
                is_wrong = false;
                break;
            }
        }

        if(is_wrong)
            printf("Goldbach's conjecture is wrong.\n");
        else
            printf("%d = %d + %d\n", n, a, b);

        scanf("%d", &n);
    }
    return 0;
}
