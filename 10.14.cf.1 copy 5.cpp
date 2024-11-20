#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define llmax 9223372036854775807
#define intmax 2147483647

ll arr[10000007];
// ll brr[10000007];
// ll sum[10000007];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int asd;
    cin >> asd;
    while (asd--)
    {
        ll ans = 1 - llmax;
        int n, k;
        cin >> n >> k;
        vector<ll> brr(2 * n + 10, 0);
        vector<ll> sum(2 * n + 10);
        _rep(i, 1, n) cin >> arr[i];
        sort(arr + 1, arr + 1 + n);
        ll cnt = 0;
        arr[0] = arr[1] - 1;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] - arr[i - 1] >= 2)
                cnt += 2;
            else if (arr[i] - arr[i - 1] == 1)
                cnt++;
            brr[cnt]++;
        }
        for (int i = 1; i <= cnt; i++)
        {
            sum[i] = sum[i - 1] + brr[i];
        }

        // for (int i = 0; i <= 10; i++)
        // {
        //     cout << brr[i] << ' ';
        // }
        int l = 1, r = 1;
        for (; r <= cnt;)
        {
            ans = max(ans, sum[r] - sum[l - 1]);
            r++;
            if (r - l + 1 > k)
                l++;
            if (brr[r] == 0)
            {
                r++;
                l = r;
            }
        }
        // cout << "ans ";
        cout << ans << endl;
    }

    return 0;
}

/*
10 2
1 1 1 2 3 4 8 9 10 11

10 2
2 2 2 3 4 8 9 10 11
*/
