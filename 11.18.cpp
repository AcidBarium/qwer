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

struct point
{
    ld x;
    ld y;
    int id;
    point(ld xx = 0, ld yy = 0, int iid = 0)
    {
        x = xx;
        y = yy;
        id = iid;
    }
} arr[1000006], st[1000006];

const point ze(0, 0, 0);

inline ld dis(const point &a, const point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline bool cmp(const point &a, const point &b)
{
    return a.y < b.y;
}

inline bool cmp2(const point &a, const point &b)
{
    return a.x < b.x;
}

inline ld getAns(const point &a, const point &b)
{
    ld fenzi = abs(a.x - b.x) + abs(a.y - b.y);
    ld fenmu = dis(a, b);
    return fenzi / fenmu;
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
        _rep(i, 1, n)
        {
            cin >> arr[i].x;
            cin >> arr[i].y;
            arr[i].id = i;
        }
        _rep(i, 1, n)
        {
            ld temp = dis(arr[i], ze);
            ld theta = atan2(arr[i].y, arr[i].x);
            st[i].x = temp * cos(theta - 3.14159265358979324 / 4);
            st[i].y = temp * sin(theta - 3.14159265358979324 / 4);
            st[i].id = i;
        }
        sort(st + 1, st + 1 + n, cmp);
        ld maxAns = -10086;
        for (register int i = 1; i < n; i++)
        {
            maxAns = max(maxAns, getAns(arr[st[i].id], arr[st[i + 1].id]));
        }
        sort(st + 1, st + 1 + n, cmp2);
        for (register int i = 1; i < n; i++)
        {
            maxAns = max(maxAns, getAns(arr[st[i].id], arr[st[i + 1].id]));
        }
        cout << fixed << setprecision(15) << maxAns << endl;
    }

    Forget_that Just_go;
}