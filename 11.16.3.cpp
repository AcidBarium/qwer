#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int asd;
    cin >> asd;
    while (asd--)
    {
        string s;
        cin >> s;
        int arr[10];
        for (int i = 0; i <= 4; i++)
        {
            arr[i + 1] = s[i] - '0';
        }
        int mark = 0;
        for (int i = 1; i <= 5; i++)
        {
            if (arr[i] % 2 == 0)
            {
                mark = i;
            }
            if (arr[i] == 0)
            {
                mark = i;
                break;
            }
        }

        if (mark == 0)
        {
            cout << 97531 << endl;
        }
        else
        {
            for (int i = 1; i <= 5; i++)
            {
                if (i == mark)
                    continue;
                cout << arr[i];
            }
            cout << arr[mark];
            cout << endl;
        }
    }

    return 0;
}