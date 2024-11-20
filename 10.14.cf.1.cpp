#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define llmax 9223372036854775807
#define intmax 2147483647

ll arr[200][200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int n = 0; n < 10; n++)
    { // loop over n from 0 to N-1 (inclusive)
        arr[n][0] = 1;
        arr[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            arr[n][k] = arr[n][k - 1] + arr[n - 1][k - 1];
    }

    for (int n = 0; n < 10; n++)
    {
        for (int k = 1; k < n; k++)
        {
            cout << arr[n][k] << ' ';
        }
        cout << endl;
    }

    return 0;
}
