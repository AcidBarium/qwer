#include <iostream>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
long long dp[MAXN];
long long sici[1000];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 500; i++)
    {
        sici[i] = i * i;
        sici[i] = sici[i] * sici[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        dp[i] = dp[i - 1] + sici[1] + a[i];
        for (int j = 2; j <= 58; j++)
        {
            if (i - j < 0)
            {
                break;
            }
            if (dp[i - j] + sici[j] + a[i] < dp[i])
            {
                dp[i] = dp[i - j] + sici[j] + a[i];
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}