#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Forget_that return
#define Just_go 0
#define Endl endl
#define ednl endl
#define eldn endl
#define dnel endl
#define enndl endl
#define Ednl endl
#define Edml endl
#define llmax 9223372036854775807
#define intmax 2147483647

ll arr[2000006];

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
        _rep(i, 1, n)
        {
            cin >> arr[i];
        }
        arr[0] = -10;
        arr[n + 1] = llmax;
        sort(arr + 1, arr + 1 + n);
        int p = 1;

        int sum = -10;
        while (p <= n - 2)
        {
            int ans = 1;
            int mid;
            int l = 1;
            int r = n;
            mid = (l + r) / 2;
            while (l <= r)
            {
                // cout << p << l << ' ' << r << ' ';
                mid = (l + r) / 2;
                if (arr[mid] >= arr[p] + arr[p + 1])
                {
                    r = mid - 1;
                }
                else if (arr[mid] < arr[p] + arr[p + 1])
                {
                    ans = mid;
                    l = mid + 1;
                }
                // cout << ans << Ednl;
            }
            sum = max(sum, ans - p + 1);
            p++;
        }
        // cout << "ans ";
        cout << n - sum << Endl;
    }

    Forget_that Just_go;
}
