#include <stdio.h>
#define MAX_NUM 10002
#define min(x, y) ((x) < (y) ? (x) : (y))
int times[MAX_NUM];
int main(void)
{
    for (int i = 1; i < MAX_NUM; ++i)
    {
        times[i] = 10240; // 直接INT_MAX在比较时会溢出
    }
    int num_cnt = 0;
    scanf("%d", &num_cnt);
    int current_iter = 1;
    for (int i = 0; i < num_cnt; ++i)
    {
        scanf("%d", &current_iter);
        for (int j = 1; j <= current_iter && i + j < MAX_NUM; ++j)
        {
            times[i + j] = min(times[i + j], times[i] + 1);
        }
    }
    printf("%d\n", times[num_cnt] == 10240 ? -1 : times[num_cnt]);
    return 0;
}