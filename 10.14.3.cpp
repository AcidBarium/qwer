#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    int asd;
    asd = 1;
    //cin >> asd;
    while (asd--)
    {

        ll m, s;
        cin >> m >> s;

        if (s == 0 && m == 1)
        {
            cout << "0 0" << endl;
            continue;
        }

        if (m * 9 < s || (s == 0 && m != 1))
        {
            cout << "-1 -1" << endl;
            continue;
        }

        ll jiuwei = s / 9;
        ll sheng = s % 9;
        ll shengwei;
        if (sheng)
            shengwei = 1;
        else
            shengwei = 0;
        ll lingwei = m - shengwei - jiuwei;

        if (lingwei)
        {
            if (shengwei)
            {
                cout << '1';
                for (int i = 0; i < lingwei - 1; i++)
                {
                    cout << '0';
                }
                cout << sheng - 1;
                for (int i = 0; i < jiuwei; i++)
                {
                    cout << '9';
                }
            }
            else
            {
                cout << '1';
                for (int i = 0; i < lingwei - 1; i++)
                {
                    cout << '0';
                }
                if (jiuwei)
                {
                    cout << '8';
                    for (int i = 0; i < jiuwei - 1; i++)
                    {
                        cout << '9';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < shengwei; i++)
            {
                cout << sheng;
            }
            for (int i = 0; i < jiuwei; i++)
            {
                cout << '9';
            }
        }

        cout << ' ';
        for (int i = 0; i < jiuwei; i++)
        {
            cout << '9';
        }
        for (int i = 0; i < shengwei; i++)
        {
            cout << sheng;
        }
        for (int i = 0; i < lingwei; i++)
        {
            cout << '0';
        }
        cout << endl;
    }

    return 0;
}