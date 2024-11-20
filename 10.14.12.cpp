#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll arr[1000007];
bool cmp(ll a, ll b)
{
    return a > b;
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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, cmp);
        ll x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (arr[i] % 2 == 0)
                {
                    x += arr[i];
                }
            }
            else
            {
                if (arr[i] % 2 == 1)
                {
                    y += arr[i];
                }
            }
        }
        if (x > y)
        {
            cout << "Alice" << endl;
        }
        else if (x < y)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Tie" << endl;
        }
    }

    return 0;
}
