#include <bits/stdc++.h>

using namespace std;

int N, M;
int** table;
int result = 0;

vector<vector<int>> shape1_1 = {{1, 1, 1, 1}};
vector<vector<int>> shape1_2 = {{1},{1},{1},{1}};

vector<vector<int>> shape2_1 = {{1, 1}, {1, 1}};

vector<vector<int>> shape3_1 = {{1, 0}, {1, 0}, {1, 1}};
vector<vector<int>> shape3_2 = {{1, 1, 1}, {1, 0, 0}};
vector<vector<int>> shape3_3 = {{1, 1}, {0, 1}, {0, 1}};
vector<vector<int>> shape3_4 = {{0, 0, 1}, {1, 1, 1}};
vector<vector<int>> shape3_5 = {{0, 1}, {0, 1}, {1, 1}};
vector<vector<int>> shape3_6 = {{1, 1, 1}, {0, 0, 1}};
vector<vector<int>> shape3_7 = {{1, 1}, {1, 0}, {1, 0}};
vector<vector<int>> shape3_8 = {{1, 0, 0}, {1, 1, 1}};

vector<vector<int>> shape4_1 = {{1, 0}, {1, 1}, {0, 1}};
vector<vector<int>> shape4_2 = {{0, 1, 1}, {1, 1, 0}};
vector<vector<int>> shape4_3 = {{0, 1}, {1, 1}, {1, 0}};
vector<vector<int>> shape4_4 = {{1, 1, 0}, {0, 1, 1}};

vector<vector<int>> shape5_1 = {{1, 1, 1}, {0, 1, 0}};
vector<vector<int>> shape5_2 = {{0, 1}, {1, 1}, {0, 1}};
vector<vector<int>> shape5_3 = {{0, 1, 0}, {1, 1, 1}};
vector<vector<int>> shape5_4 = {{1, 0}, {1, 1}, {1, 0}};

void Input(void) {
    scanf("%d%d", &N, &M);

    table = new int*[N];
    for(int i = 0; i < N; ++i) {
        table[i] = new int[M];
    }

    char input;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            scanf("%d", &table[i][j]);
            while(table[i][j] < 1 || table[i][j] > 1000) {
                scanf("%d", &table[i][j]);
            }
        }
    }
}

void CalculatePoint(int x, int y, vector<vector<int>> shape) {
    int value = 0;
    int xSize = shape[0].size();
    int ySize = shape.size();

    if(x + xSize > M || y + ySize > N)
        return;

    for(int i = 0; i < ySize; ++i) {
        for(int j = 0; j < xSize; ++j) {
            if(shape[i][j] == 1)
                value += table[y + i][x + j];
        }
    }

    result = max(value, result);
}

void Calculate(void) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            CalculatePoint(j, i, shape1_1);
            CalculatePoint(j, i, shape1_2);
            CalculatePoint(j, i, shape2_1);
            CalculatePoint(j, i, shape3_1);
            CalculatePoint(j, i, shape3_2);
            CalculatePoint(j, i, shape3_3);
            CalculatePoint(j, i, shape3_4);
            CalculatePoint(j, i, shape3_5);
            CalculatePoint(j, i, shape3_6);
            CalculatePoint(j, i, shape3_7);
            CalculatePoint(j, i, shape3_8);
            CalculatePoint(j, i, shape4_1);
            CalculatePoint(j, i, shape4_2);
            CalculatePoint(j, i, shape4_3);
            CalculatePoint(j, i, shape4_4);
            CalculatePoint(j, i, shape5_1);
            CalculatePoint(j, i, shape5_2);
            CalculatePoint(j, i, shape5_3);
            CalculatePoint(j, i, shape5_4);
        }
    }
}

int main(void) {
    Input();
    Calculate();
    printf("%d\n", result);
    return 0;
}
