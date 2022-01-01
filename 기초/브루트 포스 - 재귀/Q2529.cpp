#include <bits/stdc++.h>

using namespace std;

vector<char> sign;

int k;
vector<int> min_vector;
vector<int> max_vector;
bool min_full =false;

void input(void) {
    scanf("%d", &k);

    char temp;
    for(int i = 0; i < k;) {
        scanf("%c", &temp);
        if(temp == '>' || temp == '<') {
            sign.push_back(temp);
            i++;
        }
    }
}

void calculate(void)
{
    vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    while(next_permutation(num.begin(), num.end())) {
        int i = 0;
        for(; i < k; ++i) {
            if(!(sign[i] == '>' && num[i] > num[i+1]) && !(sign[i] == '<' && num[i] < num[i+1])) {
                break;
            }
        }
        if(i == k) {
            if (!min_full) {
                min_vector.assign(num.begin(), num.begin() + k+1);
                min_full = true;
            }
            max_vector.assign(num.begin(), num.begin() + k+1);
        }
    }
}

int main(void)
{
    input();
    calculate();

    for(int i = 0; i < k+1; ++i)
        printf("%d", max_vector[i]);
    printf("\n");
    for(int i = 0;i < k+1; ++i)
        printf("%d", min_vector[i]);
}
