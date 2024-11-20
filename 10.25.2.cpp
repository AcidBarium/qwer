#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define int long long

const int MAXN = 2e5 + 10;
struct NODE
{
    int x, k, g;
};

void solve()
{
    int q;
    cin >> q;
    stack<NODE> s;
    while (q--)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int m;
            cin >> m;
            s.push({m, 1, -1});
        }
        else if (k == 2)
        {
            s.top().k--;
            if (s.top().k == 0)
                s.pop();
        }
        else if (k == 3)
        {
            cout << s.top().x << endl;
        }
        else
        {
            int x, now = 0, gg = 0;
            cin >> x;
            while (now < x)
            {
                NODE tmp = s.top();
                s.pop();
                now += tmp.k;
                gg = __gcd(gg, tmp.x);
            }
            s.push({gg, now, gg});
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}