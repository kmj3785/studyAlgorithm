#include <bits/stdc++.h>

#define EntireDwarfNum 9
#define TrueDwarfNum 7
#define DwarfHeightSum 100

using namespace std;


int main(void) {

    int entire_dwarf[EntireDwarfNum];

    for(int i = 0; i < EntireDwarfNum; ++i) {
        scanf("%d", &entire_dwarf[i]);
    }

    int cur_sum = 0;
    stack<int> true_dwarf_index;

    for(int i = 0; i < TrueDwarfNum; ++i) {
        true_dwarf_index.push(i);
        cur_sum += entire_dwarf[i];
    }

    while(cur_sum != 100) {
        int cur_index = true_dwarf_index.top();
        true_dwarf_index.pop();
        cur_sum -= entire_dwarf[cur_index];

        if(cur_index >= EntireDwarfNum - 1) {
            while(true_dwarf_index.top() == cur_index - 1) {
                cur_index = true_dwarf_index.top();
                true_dwarf_index.pop();
                cur_sum -= entire_dwarf[cur_index];
            }
            cur_index = true_dwarf_index.top();
            true_dwarf_index.pop();
            cur_sum -= entire_dwarf[cur_index];
        }

        while(true_dwarf_index.size() < TrueDwarfNum) {
            cur_index++;
            true_dwarf_index.push(cur_index);
            cur_sum += entire_dwarf[cur_index];
        }
    }

    int answer;
    vector<int> result;
    while(!true_dwarf_index.empty()) {
        answer = true_dwarf_index.top();
        true_dwarf_index.pop();
        result.push_back(entire_dwarf[answer]);
    }

    sort(result.begin(), result.end());
    for(int i = 0; i < TrueDwarfNum; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}
