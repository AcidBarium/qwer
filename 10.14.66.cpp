#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll fa[1000007];

ll find(int x)
{
    while (fa[x] != x)
    {
        x = fa[x] = fa[fa[x]];
    }
    return x;
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
        int n;
        cin >> n;
        for (int i = 0; i <= n + 10; i++)
        {
            fa[i] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            ll dadie = find(temp);
            if (dadie == i)
                continue;
            fa[i] = dadie;
        }
        map<ll, ll> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[find(i)]++;
        }
        ll twoCnt = 0, otherCnt = 0;
        for (auto it : mp)
        {
            if (it.second == 2)
                twoCnt++;
            else
                otherCnt++;
        }
        cout << "ans ";
        if (twoCnt)
            cout << otherCnt + 1 << ' ' << twoCnt + otherCnt << endl;
        else
            cout << 1 << ' ' << twoCnt + otherCnt << endl;
    }
    return 0;
}