#include <bits/stdc++.h>
using namespace std;
#define lld long long
#define lf double
#define endl '\n'
#define llu unsigned long long
int s[1001] = {0};
map<int, int> biao;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        lld n, x;
        lld sum = 0;
        int shu = 0;
        cin >> n >> x;

        biao.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            sum += s[i];
            if (!biao[s[i]])
            {
                biao[s[i]] = 1;
                shu++;
            }
        }
        if (shu == 1 && s[1] == x)
            cout << 0;
        else if (sum == n * x)
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }
    return 0;
}