#include <bits/stdc++.h>

using namespace std;

// global variable
int N;
int** table;

// Function
void Input(void) {
    scanf("%d", &N);

    table = new int*[N];
    for(int i = 0; i < N; ++i) {
        table[i] = new int[N];
    }

    char input;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            scanf("%c", &input);
            while(input != 'C' && input != 'P' && input != 'Z' && input != 'Y') {
                scanf("%c", &input);
            }

            if (input == 'C')
                table[i][j] = 0;
            else if(input == 'P')
                table[i][j] = 1;
            else if(input == 'Z')
                table[i][j] = 2;
            else if(input == 'Y')
                table[i][j] = 3;
        }
    }
}

int CalculateResult() {
    int result = 0;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            int cur_result = 1;

            int temp_i = i;
            int temp_j = j;

            for(cur_result = 1; temp_i+1 < N && table[temp_i][j] == table[temp_i+1][j]; temp_i++, cur_result++);
            result = max(result, cur_result);

            for(cur_result = 1; temp_j+1 < N && table[i][temp_j] == table[i][temp_j+1]; temp_j++, cur_result++);
            result = max(result, cur_result);
        }
    }

    return result;
}

int Calculate(void) {
    int result = 0;

    // 인접한 것 교환
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(i+1 < N && table[i][j] != table[i+1][j]) {
                swap(table[i][j], table[i+1][j]);
                result = max(result, CalculateResult());
                swap(table[i][j], table[i+1][j]);
            }
            if(j+1 < N && table[i][j] != table[i][j+1]) {
                swap(table[i][j], table[i][j+1]);
                result = max(result, CalculateResult());
                swap(table[i][j], table[i][j+1]);
            }
        }
    }

    return result;
}

int main(void) {
    Input();
    int result = Calculate();

    printf("%d\n", result);
}
