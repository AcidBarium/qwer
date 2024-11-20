#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

struct point
{
    ll x;
    ll xiabiao;
} arr[10000007];

bool cmp(point a, point b)
{
    return a.x < b.x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].x;
        arr[i].xiabiao = i;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    ll ans = 98765432198765;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i].xiabiao != 1)
            ans = min(ans, arr[i].x / abs(arr[i].xiabiao - 1));
        if (arr[i].xiabiao != n)
            ans = min(ans, arr[i].x / abs(arr[i].xiabiao - n));
    }
    cout << ans << endl;

    return 0;
}