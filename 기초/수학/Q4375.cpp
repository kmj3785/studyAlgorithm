#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n = 1;

    while ( cin >> n ) {;

        int cur_n = 1;
        int result = 1;

        if(n == 1) {
            printf("1\n");
        }

        else {
            while(cur_n != 0) {
                cur_n = (cur_n * 10 + 1) % n;
                result++;
            }

            printf("%d\n", result);
        }

    }
    return 0;
}
