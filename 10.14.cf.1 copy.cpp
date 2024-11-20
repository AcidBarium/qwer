#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n' 
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define llmax 9223372036854775807
#define intmax 2147483647

ll arr[1000000];
ll brr[1000000];
ll mod = 1e9 + 7;

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    _rep(i, 1, n) cin >> arr[i];
    _rep(i, 1, n) cin >> brr[i];

    _rep(i,1,n)
    {
        cout << binpow(2, brr[i], mod) << endl;
    }

    return 0;
}
