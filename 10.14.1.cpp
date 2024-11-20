#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll xu, shang;
struct point
{
    ll xue;
    ll shanghai;
    ll zhaochengzongshanghai;
} arr[2000006];

bool cmp(point a, point b)
{
    if (a.shanghai != b.shanghai)
        return a.shanghai < b.shanghai;
    else
        return a.xue < b.xue;
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
        cin >> shang >> xu;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].shanghai;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].xue;
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i].xue % shang == 0)
            {
                arr[i].zhaochengzongshanghai = arr[i].xue / shang * arr[i].shanghai;
            }
            else
            {
                arr[i].zhaochengzongshanghai = (arr[i].xue / shang + 1) * arr[i].shanghai;
            }
        }
        sort(arr, arr + n, cmp);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << "zhaochengshanghai" << " " << arr[i].zhaochengzongshanghai << endl;
        // }

        for (int i = 0; i < n - 1; i++)
        {
            xu -= arr[i].zhaochengzongshanghai;
        }
        if (xu <= 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (arr[n - 1].xue % shang == 0)
            {
                if (arr[n - 1].xue / shang - 1 >= 0)
                    xu -= (arr[n - 1].xue / shang - 1) * arr[n - 1].shanghai;
            }
            else
            {
                xu -= (arr[n - 1].xue / shang) * arr[n - 1].shanghai;
            }
            if (xu <= 0)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}