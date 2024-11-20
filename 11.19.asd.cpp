#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2147483647;
const int maxn = 1e5 + 5;
int vis[maxn], dis[maxn], head[maxn];
int m, n, s;
int cnt = 0;
struct edge
{
    int u;
    int v;
    int w;
    int next;
} e[5 * maxn];
struct node
{
    int w;
    int now;
    inline bool operator<(const node &a) const
    {
        return w > a.w;
    }
};
priority_queue<node> q;

inline void add(int u, int v, int w)
{
    e[++cnt].u = u;
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void gaofang()
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[s] = 0;
    q.push((node){0, s});

    while (!q.empty())
    {
        node temp = q.top();
        int u = temp.now;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push((node){dis[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    gaofang();

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}