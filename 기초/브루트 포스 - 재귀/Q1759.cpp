#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> pass;
vector<int> ind;

void input(void) {
    scanf("%d %d", &L, &C);

    char temp;
    for(int i = 0; i < C;) {
        scanf("%c", &temp);

        if(temp>='a' && temp<='z') {
            pass.push_back(temp);
            i++;
        }
    }
    sort(pass.begin(), pass.end());

    for(int i = 0; i < L; ++i) {
        ind.push_back(1);
    }
    for(int i = 0; i < C - L; ++i) {
        ind.push_back(0);
    }
}

void printPassL(vector<char> cur_pass) {
    for(int i = 0; i < cur_pass.size(); i++)
        printf("%c", cur_pass[i]);
    printf("\n");
}

bool isPossible(vector<char> cur_pass) {
    int vowel_num = 0;
    for(int i = 0; i < cur_pass.size(); i++)
        if(cur_pass[i] == 'a' || cur_pass[i] == 'e' || cur_pass[i] == 'i' || cur_pass[i] == 'o' || cur_pass[i] == 'u')
            vowel_num++;

    if(vowel_num >= 1 && L - vowel_num >= 2)
        return true;
    else
        return false;
}

void findPossiblePassword(void) {
    vector<char> cur_pass;
    do {
        for(int i = 0; i < C; ++i) {
            if(ind[i] == 1) {
                cur_pass.push_back(pass[i]);
            }
        }

        if(isPossible(cur_pass))
            printPassL(cur_pass);
        cur_pass.clear();
    }while(prev_permutation(ind.begin(), ind.end()));
}

int main(void)
{
    input();
    findPossiblePassword();
}
