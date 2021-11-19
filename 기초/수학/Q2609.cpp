#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);

    int small_num = min(a, b);
    int big_num = max(a, b);

    int max_divide = small_num, min_multiple = big_num;

    while(min_multiple % a != 0 || min_multiple % b != 0) {
         min_multiple += big_num;
    }

    while(max_divide > 0 && (a % max_divide != 0 || b % max_divide != 0)) {
        max_divide--;
    }

    printf("%d\n%d\n", max_divide, min_multiple);

    return 0;
}
