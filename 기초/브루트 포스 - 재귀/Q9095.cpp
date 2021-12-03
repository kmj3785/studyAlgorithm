#include <bits/stdc++.h>

using namespace std;

int cal(int n, int sum){
    if(n==sum) {
        return 1;
    }
    else if(n<sum)
        return 0;
    int result = 0;
    for(int i = 1; i <= 3; ++i)
        result += cal(n, sum + i);
    return result;
}

int main(void) {
    int T, n;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> n;
        cout << cal(n, 0) << endl;
    }
    return 0;
}
