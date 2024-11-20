#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;
typedef long long ll;
const int MAXN = 1e6 + 5;
int T;
ll N;
const ll MOD = 998244353;
ll K;
map<int, int> check;
int big;
struct edge
{
    ll l, r;
    bool operator<(const edge &e) const
    {
        if (r != e.r)
        {
            return r < e.r;
        }
        return l < e.l;
    }
} eds[MAXN];
ll nsum = 0;
ll lowbit(ll x)
{
    return (x & -x);
}
ll d[MAXN];
ll sum(ll x)
{
    x--;
    ll res = 0;
    while (x > 0)
    {
        res += d[x];
        x -= lowbit(x);
    }
    return nsum - res;
}
void add(ll x)
{
    nsum++;
    while (x <= big)
    {
        d[x]++;
        x += lowbit(x);
    }
}
int main()
{
    int dda;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld", &N, &K);
        check.clear();
        big = 0;
        for (int i = 1; i <= N; ++i)
        {
            scanf("%lld%lld", &eds[i].l, &eds[i].r);
            check[eds[i].l] = 1;
            check[eds[i].r] = 1;
            if (eds[i].r > big)
            {
                big = eds[i].r;
            }
        }
        dda = 0;
        for (auto it = check.begin(); it != check.end(); it++)
        {
            dda++;
            it->second = dda;
        }
        big = check[big];
        for (int i = 1; i <= N; i++)
        {
            eds[i].l = check[eds[i].l];
            eds[i].r = check[eds[i].r];
        }
        // add(100);
        // printf("%lld!\n", sum(102));
        sort(eds + 1, eds + N + 1);
        ll ans = 1;
        for (int i = 1; i <= N; ++i)
        {
            ll res = K - sum(eds[i].l);
            res %= MOD;
            ans *= res;
            ans %= MOD;
            add(eds[i].r);
        }
        // for (int i = 0; i <= N; ++i)
        for (int i = 0; i <= big; ++i)
        {
            d[i] = 0;
        }
        nsum = 0;
        printf("%lld\n", ans);
    }

    return 0;
}