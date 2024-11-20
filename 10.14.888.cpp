#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

// ll fa[1000007];
// bool isfang[1000007];

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
        ll twoHuan = 0;
        ll otherHuan = 0;
        vector<int> fa(n + 10, 0);
        vector<bool> isfang(n + 10, false);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            fa[i] = temp;
        }
        for (int i = 1; i <= n; i++)
        {
            if (isfang[i])
                continue;
            int p = i;
            ll cnt = 1;
            isfang[p] = true;
            while (fa[p] != i)
            {
                p = fa[p];
                cnt++;
                isfang[p] = true;
            }
            if (cnt == 2)
                twoHuan++;
            else
                otherHuan++;
        }
        cout << otherHuan << ' ' << otherHuan + twoHuan << endl;
    }

    return 0;
}