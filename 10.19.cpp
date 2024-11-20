#include<stdio.h>
int mid_num;
int last[5005];
int check[5005];
int edge[2][10005];
long long answer;
long long f[5005];
long long g[5005];
long long l[5005];
long long r[5005];
long long mid[5005];
int read()
{
    int goal;
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
int write(int goal)
{
    if (goal < 10)
    {
        putchar('0' + goal);
        return 0;
    }
    write(goal / 10);
    putchar('0' + goal % 10);
    return 0;
}
int difficult_code(int iocation, int father)
{
    for (int way = last[iocation]; way != 0; way = edge[1][way])
    {
        if (edge[0][way] != father)
        {
            difficult_code(edge[0][way], iocation);
        }
    }
    if (check[iocation] == 1)
    {
        g[iocation] = 1;
        mid_num = 0;
        for (int way = last[iocation]; way != 0; way = edge[1][way])
        {
            if (edge[0][way] == father && check[father] == 1)
            {
                continue;
            }
            if (check[edge[0][way]] == 1)
            {
                g[iocation] *= (2 * f[edge[0][way]] + g[edge[0][way]]) % 998244353;
                g[iocation] %= 998244353;
                mid_num++;
                mid[mid_num] = (2 * f[edge[0][way]] + g[edge[0][way]]) % 998244353;
            }
            if (check[edge[0][way]] == 0)
            {
                g[iocation] *= 2;
                g[iocation] %= 998244353;
                mid_num++;
                mid[mid_num] = 2;
            }
        }
        l[0] = 1;
        for (int i = 1; i <= mid_num; i++)
        {
            l[i] = l[i - 1] * mid[i];
            l[i] %= 998244353;
        }
        r[mid_num + 1] = 1;
        for (int i = mid_num; i >= 1; i--)
        {
            r[i] = r[i + 1] * mid[i];
            r[i] %= 998244353;
        }
        f[iocation] = 0;
        mid_num = 1;
        for (int way = last[iocation]; way != 0; way = edge[1][way])
        {
            if (edge[0][way] == father && check[father] == 1)
            {
                continue;
            }
            if (check[edge[0][way]] == 1 && f[edge[0][way]] != 0)
            {
                f[iocation] += (((l[mid_num - 1] * r[mid_num + 1]) % 998244353) * f[edge[0][way]]) % 998244353;
                f[iocation] %= 998244353;
            }
            if (check[edge[0][way]] == 0)
            {
                f[iocation] += (l[mid_num - 1] * r[mid_num + 1]) % 998244353;
                f[iocation] %= 998244353;
            }
            mid_num++;
        }
        if (check[father] != 1)
        {
            answer *= f[iocation];
            answer %= 998244353;
        }
    }
    return 0;
}
int main()
{
    int n, u, v, b;
    n = read();
    for (int i = 1; i <= n - 1; i++)
    {
        u = read();
        v = read();
        edge[0][i * 2 - 1] = v;
        edge[1][i * 2 - 1] = last[u];
        last[u] = i * 2 - 1;
        edge[0][i * 2] = u;
        edge[1][i * 2] = last[v];
        last[v] = i * 2;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        b = read();
        check[b] = 1;
        answer = 1;
        difficult_code(1, 0);
        write(answer);
        putchar('\n');
    }
    return 0;
}