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

ld eps = 1e-9;

struct point
{
    ld x;
    ld y;
    int id;
} arr[1000006], st[1000006];

struct p
{
    ld x;
    ld y;
    ld r;
} yuan[10000];

ld crossMull(const point &a1, const point &a2, const point &b1, const point &b2)
{
    return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}

ld dis(const point &a, const point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld dis(const p &a, const p &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld cmp(const point &a, const point &b)
{
    ld temp = crossMull(arr[1], a, arr[1], b);
    if (temp > 0)
        return true;
    if (temp == 0 && dis(arr[1], a) < dis(arr[1], b))
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    _rep(i, 1, n)
    {
        cin >> yuan[i].x >> yuan[i].y >> yuan[i].r;
        yuan[i].r += 10;
    }

    int posi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            ld tempdis = dis(yuan[i], yuan[j]);
            ld theta = atan2(yuan[j].y - yuan[i].y, yuan[j].x - yuan[i].x);
            if (tempdis + min(yuan[i].r, yuan[j].r) < max(yuan[i].r, yuan[j].r) || (yuan[i].x == yuan[j].x && yuan[i].y == yuan[j].y))
                continue;
            if (yuan[i].r > yuan[j].r)
            {
                if (abs(tempdis + yuan[j].r - yuan[i].r) < eps)
                {
                    arr[++posi].x = yuan[i].x + yuan[i].r * cos(theta);
                    arr[posi].y = yuan[i].y + yuan[i].r * sin(theta);
                    arr[posi].id = i;
                }
            }
            if (abs(yuan[i].r - yuan[j].r) < eps)
            {
                arr[++posi].x = yuan[i].x + yuan[i].r * cos(theta + 3.14159265358979 / 2.0);
                arr[posi].y = yuan[i].y + yuan[i].r * sin(theta + 3.14159265358979 / 2.0);
                arr[posi].id = i;
                arr[++posi].x = yuan[i].x + yuan[i].r * cos(theta - 3.14159265358979 / 2.0);
                arr[posi].y = yuan[i].y + yuan[i].r * sin(theta - 3.14159265358979 / 2.0);
                arr[posi].id = i;
                continue;
            }

            p wai;
            wai.x = (yuan[i].x) - tempdis / (yuan[j].r - yuan[i].r) * yuan[i].r * cos(theta);
            wai.y = (yuan[i].y) - tempdis / (yuan[j].r - yuan[i].r) * yuan[i].r * sin(theta);
            // cout << "wai x" << wai.x << " wai y " << wai.y << endl;
            ld waiToYuan = dis(wai, yuan[i]);
            // cout << "wai to yuan " << waiToYuan << endl;
            ld thete2 = asin(yuan[i].r / waiToYuan);
            // cout << "theta2 " << thete2 << endl;
            ld zhijiaobian = sqrt(waiToYuan * waiToYuan - yuan[i].r * yuan[i].r);
            theta = atan2(yuan[i].y - wai.y, yuan[i].x - wai.x);
            // cout << "zhijiaobian " << zhijiaobian << endl;
            // cout << "zhijiaobian *cos " << zhijiaobian * cos(theta - thete2) << endl;
            arr[++posi].x = wai.x + zhijiaobian * cos(theta - thete2);
            arr[posi].y = wai.y + zhijiaobian * sin(theta - thete2);
            arr[posi].id = i;
            arr[++posi].x = wai.x + zhijiaobian * cos(theta + thete2);
            arr[posi].y = wai.y + zhijiaobian * sin(theta + thete2);
            arr[posi].id = i;
        }
    }
    // for (int i = 1; i <= 20; i++)
    // {
    // 	cout << i << ' ' << arr[i].x << ' ' << arr[i].y << endl;
    // }

    ld chafen = 3.14159265358979 * 2.0 / 87.0;
    _rep(i, 1, n)
    {
        ld jiaodu = 0;
        _rep(j, 1, 87.0)
        {
            arr[++posi].x = yuan[i].x + yuan[i].r * cos(jiaodu);
            arr[posi].y = yuan[i].y + yuan[i].r * sin(jiaodu);
            arr[posi].id = i;
            jiaodu += chafen;
        }
    }

    int imin = 1;
    ld ymin = 3e30;
    ld xmin = 3e30;

    _rep(i, 1, posi)
    {
        if ((arr[i].y < ymin && abs(arr[i].y - ymin) > eps) || (abs(arr[i].y - ymin) < eps && (arr[i].x < xmin) && abs(arr[i].x - xmin) > eps))
        {
            ymin = arr[i].y;
            xmin = arr[i].x;
            imin = i;
        }
        // cout << fixed << setprecision(20) << i << "min " << xmin << " " << ymin << endl;
    }

    point temppp;
    temppp = arr[1];
    arr[1] = arr[imin];
    arr[imin] = temppp;

    if (posi <= 3)
    {
        ld maxR = -10;
        for (int i = 1; i <= n; i++)
            maxR = max(maxR, yuan[i].r);
        cout << maxR * 2.0 * 3.14159265358979324 << endl;
        Forget_that Just_go;
    }

    sort(arr + 2, arr + 1 + posi, cmp);

    int pp = 1;
    for (int i = 2; i <= posi; i++)
    {
        if (abs(arr[i].x - arr[i - 1].x) > eps || abs(arr[i].y - arr[i - 1].y) > eps)
            arr[++pp] = arr[i];
    }
    posi = pp;

    // _rep(i, 1, posi)
    // {
    // 	cout << "after sort arr " << i << " " << arr[i].x << " " << arr[i].y << " " << arr[i].id << endl;
    // }

    int cnt = 0;
    st[++cnt] = arr[1];

    for (int i = 2; i <= posi; i++)
    {
        while (cnt > 1 && crossMull(st[cnt - 1], st[cnt], st[cnt - 1], arr[i]) <= 0)
            cnt--;
        st[++cnt] = arr[i];
    }
    st[cnt + 1] = arr[1];

    ld sum = 0;

    // for (int i = 1; i <= cnt; i++)
    // {
    //     cout << "St " << i << "  " << st[i].x << " " << st[i].y << " id " << st[i].id << endl;
    // }

    _rep(i, 1, cnt)
    {
        // cout << st[i].x << ' ' << st[i].y << ' ' << st[i].id << ' ';
        if (st[i].id == st[i + 1].id)
        {
            // ld x0 = yuan[st[i].id].x, y0 = yuan[st[i].id].y;
            // ld rr = yuan[st[i].id].r;
            // ld x1, x2, y1, y2;
            // x1 = st[i].x - x0;
            // x2 = st[i + 1].x - x0;
            // y1 = st[i].y - y0;
            // y2 = st[i + 1].y - y0;
            // ld the = acos((x1 * x2 + y1 * y2) / rr / rr);
            // sum += the * yuan[st[i].id].r;
            ld the1 = atan2(st[i].y - yuan[st[i].id].y, st[i].x - yuan[st[i].id].x);
            ld the2 = atan2(st[i + 1].y - yuan[st[i].id].y, st[i + 1].x - yuan[st[i].id].x);
            // cout << "the "	<< ednl;

            // cout << the1 << ' ' << the2 << endl;
            // cout << fixed << setprecision(10) << "the1 " << the1 << " the2 " << the2 << endl;

            if (the1 < 0)
                the1 += 3.14159265358979324 * 2.0;
            if (the2 < 0)
                the2 += 3.14159265358979324 * 2.0;
            if (the2 <= the1 + eps)
                the2 += 3.14159265358979324 * 2.0;
            sum += (the2 - the1) * yuan[st[i].id].r;
            // cout << "huddu  " << (the2 - the1) * yuan[st[i].id].r << endl;
        }
        else
        {
            sum += dis(st[i], st[i + 1]);
            // cout << "zhixianchang   " << dis(st[i], st[i + 1]) << ednl;
        }
    }

    // _rep(i, 1, n)
    // {
    // 	cout << yuan[i].r << endl;
    // }

    ld maxR = -10;
    for (int i = 1; i <= n; i++)
    {
        maxR = max(maxR, yuan[i].r);
    }

    // cout << "ans ";
    cout << fixed << setprecision(10) << max(maxR * 2.0 * 3.14159265358979324, sum) << endl;

    // cout << fixed << setprecision(10) << 1715.91229929 << endl;

    Forget_that Just_go;
}

/*


2
0 0 3
4 0 1

3
0 0 100
-60 200 40
350 50 150


5
11 0 1
12 0 2
13 0 3
14 0 4
15 0 5


*/