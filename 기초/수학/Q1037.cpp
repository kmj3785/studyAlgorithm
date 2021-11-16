#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int N;
    vector<int> divided_num;

    scanf("%d", &N);
    int input_num;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &input_num);
        divided_num.push_back(input_num);
    }

    sort(divided_num.begin(), divided_num.end());

    int result = divided_num[0] * divided_num[N-1];

    for(int i = 0; i < N; ++i) {
        if(result % divided_num[i] != 0) {
            result *= divided_num[i];
        }
    }

    printf("%d\n", result);

    return 0;
}
