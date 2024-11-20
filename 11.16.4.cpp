#include <bits/stdc++.h>
using namespace std;

inline long long read()
{
    int mark;
    long long goal;
    char mid;
    mid = getchar();
    for (; (mid < '0' || mid > '9') && mid != '-';)
    {
        mid = getchar();
    }
    mark = 1;
    if (mid == '-')
    {
        mark = -1;
        mid = getchar();
    }
    goal = 0;
    for (; mid >= '0' && mid <= '9';)
    {
        goal *= 10;
        goal += mid - '0';
        mid = getchar();
    }
    goal *= mark;
    return goal;
}

inline long long write(long long goal)
{
    if (goal == 0)
    {
        putchar('0');
        return 0;
    }
    static int mid[20];
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

const int M = 998244353;
long long ksm(long long one)
{
    long long goal, mutiple, two;
    two = 998244351;
    goal = 1;
    mutiple = one;
    for (; two != 0; two /= 2)
    {
        if ((two & 1) == 1)
        {
            goal *= mutiple;
            goal %= M;
        }
        mutiple *= mutiple;
        mutiple %= M;
    }
    return goal;
}

int main()
{
    long long n;
    n = read();

    long long minx = -10086;
    long long cnt = 0;
    long long ans = 1;

    map<long long, long long> mp;

    for (int i = 1; i <= 2 * n; i++)
    {
        long long x;
        x = read();
        if (x != -1)
        {
            mp[x]++;
            cnt++;
        }
        else
        {
            long long se = (*mp.begin()).second;
            long long fi = (*mp.begin()).first;

            // printf("fi %lld , se %lld cnt %lld \n", fi, se, cnt);

            if (fi >= minx)
            {
                minx = fi;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
            ans = ans * se % M;
            ans = ans * ksm(cnt) % M;
            mp[fi]--;
            if (mp[fi] == 0)
            {
                auto it = mp.find(fi);
                mp.erase(it);
            }

            cnt--;
        }
    }
    write(ans);

    return 0;
}