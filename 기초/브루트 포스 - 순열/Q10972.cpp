#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N;
    scanf("%d", &N);

    vector<int> arr;
    int buf;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &buf);
        if(buf >= 1 && buf <= 10000)
            arr.push_back(buf);
    }

    next_permutation(arr.begin(), arr.end());

    bool is_last = true;

    for(int i = 0; i < N; ++i)
        if(arr[i] != i+1) {
            is_last = false;
            break;
        }

    if(is_last) {
        printf("-1");
    }
    else {
        for(int i = 0; i < N; ++i)
            printf("%d ", arr[i]);
    }

    printf("\n");
}
