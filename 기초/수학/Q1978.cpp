#include <bits/stdc++.h>

using namespace std;

int main(void) {
    vector<int> decimal = {2};

    int N;
    scanf("%d", &N);
    vector<int> input;

    int cur_input;
    for(int i = 0 ; i < N; ++i) {
        scanf("%d", &cur_input);
        input.push_back(cur_input);
    }

    sort(input.begin(), input.end());

    for(int i = 3; i <= input.back(); ++i) {
        bool is_decimal = true;
        for(int j = 0; j < decimal.size(); ++j) {
            if( i % decimal[j] == 0)
                is_decimal = false;
        }
        if(is_decimal)
            decimal.push_back(i);
    }

    int result = 0;

    for(int i = 0; i < input.size(); ++i) {
        if(find(decimal.begin(), decimal.end(), input[i]) != decimal.end())
            result++;
    }

    printf("%d\n", result);
}
