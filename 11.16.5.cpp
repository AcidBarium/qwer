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
    static int mid[30];
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
const int MAXN = 1e5 + 5;
int answer;
int a[MAXN];
int w[MAXN];
int last[MAXN];
int check[MAXN];
int edge[MAXN][3];
int difficult_code(int iocation, int father)
{
    int mark;
    mark = 0;
    for (int way = last[iocation]; way != 0; way = edge[way][2])
    {
        if (edge[way][0] == father)
        {
            if (edge[way][1] == 1)
            {
                mark = 1;
            }
            break;
        }
    }
    if (mark == 1)
    {
        return 0;
    }
    for (int way = last[iocation]; way != 0; way = edge[way][2])
    {
        if (edge[way][0] == father)
        {
            continue;
        }
        if (edge[way][1] == 1)
        {
            check[iocation] = 1;
        }
        difficult_code(edge[way][0], iocation);
        if (check[edge[way][0]] == 1)
        {
            check[iocation] = 1;
        }
    }
    if (check[iocation] == 0)
    {
        answer++;
    }
    return 0;
}
int main()
{
    int t, n, u, v;
    t = read();
    for (int i = 0; i < t; i++)
    {
        n = read();
        for (int j = 1; j <= n; j++)
        {
            last[j] = 0;
            check[j] = 0;
        }
        for (int j = 1; j <= n; j++)
        {
            w[j] = read();
        }
        for (int j = 1; j <= n - 1; j++)
        {
            u = read();
            v = read();
            putchar('\n');
            putchar('1');
            putchar('1');
            putchar('1');
            putchar('1');
            putchar('1');
            putchar(' ');
            write(j);
            putchar('\n');
            edge[j * 2 - 1][0] = v;
            edge[j * 2 - 1][1] = 0;
            edge[j * 2 - 1][2] = last[u];
            last[u] = j * 2 - 1;
            edge[j * 2][0] = u;
            edge[j * 2][1] = 0;
            edge[j * 2][2] = last[v];
            last[v] = j * 2;
            if (w[v] < w[u] / 2)
            {
                edge[j * 2 - 1][1] = 1;
            }
            if (w[u] < w[v] / 2)
            {
                edge[j * 2][1] = 1;
            }
        }
        answer = 0;
        difficult_code(1, 0);
        write(answer);
        putchar('\n');
    }
    return 0;
}