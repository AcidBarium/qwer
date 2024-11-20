#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll arr[10000007];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int asd;
    cin >> asd;
    while (asd--)
    {
        ll n, x;
        ll sum = 0;
        cin >> n >> x;
        bool isok = true;
        ll isyou = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] != x)
                isok = false;
            if (arr[i] == x)
                isyou++;
        }
        if (isok)
        {
            cout << 0 << endl;
            continue;
        }
        if ((sum % n == 0 && sum / n == x) || isyou)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}