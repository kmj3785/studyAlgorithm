#include <bits/stdc++.h>

using namespace std;

struct Schedule
{
    int time;
    int price;
};

int N;
vector<Schedule> consultingSchedule;
int result = 0;

void input(void)
{
    scanf("%d", &N);

    int time, price;
    Schedule newSchedule;
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &time, &price);
        newSchedule = {time, price};
        consultingSchedule.push_back(newSchedule);
    }
}

void calculate(int curIndex, int curPrice)
{
    if(curIndex + consultingSchedule[curIndex].time >= N)
    {
        if(curIndex + consultingSchedule[curIndex].time == N)
            curPrice += consultingSchedule[curIndex].price;

        if(result < curPrice)
            result = curPrice;
        return;
    }

    curPrice += consultingSchedule[curIndex].price;

    for(int i = curIndex + consultingSchedule[curIndex].time; i < N; ++i)
    {
        calculate(i, curPrice);
    }
}

int main(void)
{
    input();
    for(int i = 0; i < consultingSchedule[0].time; ++i)
        calculate(i, 0);
    cout << result << endl;
}
