#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

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
        vector<int> fa(n + 10, 0);
        vector<bool> isfang(n + 10, false);
        vector<int> du(n + 10, 0);
        vector<int> duTrue(n + 10, 0);
        queue<int> shan;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            fa[i] = temp;
            du[i]++;
            du[temp]++;
            duTrue[i]++;
            duTrue[temp]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (du[i] == 1)
                shan.push(i);
        }
        while (!shan.empty())
        {
            int p = shan.front();
            shan.pop();
            du[p]--;
            du[fa[p]]--;
            if (du[fa[p]] == 1)
                shan.push(fa[p]);
        }
        ll ansKe = 0, ansNuke = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isfang[i])
                continue;
            if (du[i] == 2)
            {
                int p = i;
                ll cnt = 1;
                isfang[i] = true;
                bool isOk = false;
                if (duTrue[p] >= 3)
                {
                    isOk = true;
                }
                while (fa[p] != i)
                {
                    p = fa[p];
                    cnt++;
                    isfang[p] = true;
                    if (duTrue[p] >= 3)
                    {
                        isOk = true;
                    }
                }
                if (cnt == 2 || isOk)
                    ansKe++;
                else
                    ansNuke++;
            }
        }
        // cout << "ans ";
        if (ansKe)
            cout << ansNuke + 1 << ' ' << ansKe + ansNuke << endl;
        else
            cout << ansNuke << ' ' << ansKe + ansNuke << endl;
    }
    return 0;
}