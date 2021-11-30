#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    scanf("%d", &N);

    int result = 0;

    for(int multiValue = 1, currentValue = 9; N > 0; multiValue++, currentValue*=10) {
        if(N - currentValue >= 0) {
            result += currentValue * multiValue;
            N -= currentValue;
        }
        else{
            result += N * multiValue;
            N = 0;
        }
    }

    printf("%d\n", result);

    return 0;
}
