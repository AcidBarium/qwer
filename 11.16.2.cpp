#include <bits/stdc++.h>
using namespace std;

inline long long read()
{
    long long goal;
    char mid;
    mid = getchar();
    for (; mid < '0' || mid > '9';)
    {
        mid = getchar();
    }
    goal = 0;
    for (; mid >= '0' && mid <= '9';)
    {
        goal *= 10;
        goal += mid - '0';
        mid = getchar();
    }
    return goal;
}
inline long long write(long long goal)
{
    if (goal == 0)
    {
        putchar('0');
        return 0;
    }
    static long long mid[20];
    for (mid[0] = 0; goal != 0; goal /= 10)
    {
        mid[0]++;
        mid[mid[0]] = goal % 10;
    }
    for (int i = mid[0]; i >= 1; i--)
    {
        putchar('0' + mid[i]);
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int asd;
    cin >> asd;
    while (asd--)
    {
        long long n, d;
        // n = read();
        // d = read();
        cin >> n >> d;
        long long x = 1LL * 123456789;
        x = x * 10 + d;
        int wei = 0;
        long long tempn = n;
        while (tempn /= 10)
        {
            wei++;
        }
        for (int i = 0; i < wei; i++)
        {
            x *= 10;
        }
        x *= 10;

        x += n;
        long long k = x / n;
        // cout << x << ' ' << k << ' ' << k * n << endl;
        // write(x);
        cout << k << endl;
        // putchar(' ');
        // write(k);
        // putchar(' ');
        // write(k * n);
        // putchar('\n');
    }
    return 0;
}