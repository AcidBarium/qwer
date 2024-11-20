#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int dp[100005][4];
int N;
bool isP(int p)
{
    if (p == 1 || p == 2)
    {
        return true;
    }
    for (int i = 2; i <= sqrt(p); ++i)
    {
        if (p % i == 0)
        {
            return false;
        }
    }
    return true;
}
int a[100005];
int main()
{
    // printf("%d!\n", isP(5));
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &a[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    if (a[1] == 1)
    {
        dp[1][1] = 0;
    }
    dp[1][2] = dp[1][3] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (isP(a[i - 1] + a[i]))
        {
            dp[i][0] = dp[i - 1][0];
        }
        if (isP(a[i] + 1))
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (a[i] % 2 == 0)
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][3]);
        }
        else
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][2]);
        }
        if (a[i] == 1)
        {
            dp[i][1] = min(dp[i][1], dp[i][0]);
        }
        dp[i][1] = min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]) + 1);
        if(isP(a[i-1]+1)){
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        }
        dp[i][2] = min(dp[i][2], min(dp[i - 1][3], dp[i - 1][1]) + 1);
        if (a[i - 1] % 2 == 1)
        {
            dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        }
        dp[i][3] = min(dp[i][3], dp[i - 1][2] + 1);
        if (a[i - 1] % 2 == 0)
        {
            dp[i][3] = min(dp[i][3], dp[i - 1][0] + 1);
        }
    }
    // for (int i = 1; i <= N; ++i)
    // {
    //     for (int j = 0; j <= 3; ++j)
    //     {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", min(dp[N][0], min(dp[N][1], min(dp[N][2], dp[N][3]))));
    return 0;
}