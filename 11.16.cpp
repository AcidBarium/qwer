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
inline long long write(__int128 goal)
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
const int MAXN = 2e5 + 5;
__int128 a[MAXN];
__int128 mutiple[MAXN];
int main()
{
    int n, m, add;
    __int128 answer;
    n = read();
    m = read();
    for (int i = 1; i <= n; i++)
    {
        mutiple[i] = i;
        mutiple[i] = mutiple[i] * mutiple[i];
        mutiple[i] = mutiple[i] * mutiple[i];
    }
    for (int i = 1; i <= m; i++)
    {
        a[i] = read();
    }
    answer = 0;
    add = 1;
    for (int i = 2; i <= m; i++)
    {
        if (mutiple[add + 1] - mutiple[add] > a[i - 1])
        {
            answer += mutiple[add] + a[i - 1];
            add = 1;
        }
        else
        {
            add++;
        }
    }
    answer += a[m] + mutiple[add];
    write(answer);
    putchar('\n');
    return 0;
}