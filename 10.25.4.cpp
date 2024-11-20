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
    ll x;
    ll y;
} arr[1000007], st[1000007]; // 大灯笼的坐标，最后凸包的坐标

ll crossMul(const point &a1, const point &a2, const point &b1, const point &b2) // 叉乘判位置，都用ll了
{
    return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}

ll dis(const point &a, const point &b) // 返回距离的平方
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(const point &a, const point &b) // 找凸包的cmp
{
    ll temp = crossMul(arr[1], a, arr[1], b);
    if (temp > 0)
        return true;
    if (temp == 0 && dis(arr[1], a) < dis(arr[1], b))
        return true;
    return false;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    // 找大灯笼的凸包

    while (1)
    {

        int n, m;
        if (!(cin >> n))
            Forget_that Just_go;

        int imin = 1;
        ll ymin = llmax;
        ll xmin = llmax;

        _rep(i, 1, n)
        {
            cin >> arr[i].x >> arr[i].y;
            if (arr[i].y < ymin || (arr[i].y == ymin && arr[i].x < xmin))
            {
                ymin = arr[i].y;
                xmin = arr[i].x;
                imin = i;
            }
        }

        point temppp;
        temppp.x = arr[1].x;
        temppp.y = arr[1].y;
        arr[1].x = arr[imin].x;
        arr[1].y = arr[imin].y;
        arr[imin].x = temppp.x;
        arr[imin].y = temppp.y;

        sort(arr + 2, arr + 1 + n, cmp);

        st[1] = arr[1];
        int cnt = 1;
        _rep(i, 2, n)
        {
            while (cnt > 1 && crossMul(st[cnt - 1], st[cnt], st[cnt - 1], arr[i]) <= 0)
                cnt--;
            st[++cnt] = arr[i];
        }

        // 找大灯笼的凸包

        temppp.x = arr[1].x - 10; // 在最下面的灯笼的左边加入一个灯笼
        temppp.y = arr[1].y;
        st[cnt + 1] = temppp;

        _rep(i, 1, cnt) st[i] = st[i + 1];

        cin >> m;
        ll sum = 0;
        _rep(i, 1, m)
        {
            point elem;
            cin >> elem.x >> elem.y;
            if (elem.y < arr[1].y) // 如果小灯笼在最下面的大灯笼的下面，直接结束
                continue;
            ll lleft = 1, rright = cnt;
            ll mid = (lleft + rright) / 2;
            ll ans = mid;
            while (lleft <= rright) // 二分找小灯笼属于那个三角形
            {
                mid = (lleft + rright) / 2;
                // cout << "l " << lleft << " r " << rright << " mid " << mid << endl;
                if (crossMul(arr[1], st[mid], arr[1], elem) > 0)
                {

                    lleft = mid + 1;
                }
                else
                {
                    ans = mid;
                    rright = mid - 1;
                }
            }
            // cout << "find " << ans << endl;
            if (ans == cnt) // 假如找到最左边的三角形了（刚刚加的点）
                continue;
            if (crossMul(arr[1], st[ans], arr[1], elem) == 0 && dis(arr[1], elem) <= dis(arr[1], st[ans])) // 假如在三角形的边上
            {
                // cout << "ok1" << endl;
                sum++;
                continue;
            }
            if (ans == 1 || ans == cnt)
            {
                continue;
            }
            if (crossMul(st[ans - 1], st[ans], st[ans - 1], elem) >= 0) // 假如在三角形外边的左侧
            {
                // cout << "ok2" << endl;
                sum++;
                continue;
            }
        }
        // cout << "ans ";
        cout << sum << endl;
    }
    Forget_that Just_go;
}
