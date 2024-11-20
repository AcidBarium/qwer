#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Forget_that return
#define Just_go 0
#define llmax 9223372036854775807
#define intmax 2147483647

struct NODE
{
    string data;
    ll weight;
    int id;
    int parent;
    int lson;
    int rson;

    bool operator<(const NODE &other) const
    {
        return weight > other.weight; // 小根堆
    }

} arr[10005];

priority_queue<NODE> s;

void dfs(string code, int p)
{
    if (arr[p].lson == 1 - intmax)
    {
        cout << arr[p].data << ' ' << code << endl;
        return;
    }
    dfs(code + "0", arr[p].lson);
    dfs(code + "1", arr[p].rson);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    _rep(i, 1, n) cin >> arr[i].data;
    _rep(i, 1, n) cin >> arr[i].weight;
    _rep(i, 1, n) arr[i].id = i;
    _rep(i, 1, n)
    {
        arr[i].lson = 1 - intmax;
        arr[i].rson = 1 - intmax;
    }
    _rep(i, 1, n) s.push(arr[i]);

    int cnt = n;

    while (s.size() > 1)
    {
        NODE fir = s.top();
        s.pop();
        NODE sec = s.top();
        s.pop();
        ++cnt;
        arr[cnt].lson = fir.id;
        arr[cnt].rson = sec.id;
        arr[cnt].weight = fir.weight + sec.weight;
        arr[cnt].id = cnt; // 新增节点ID
        fir.parent = cnt;
        sec.parent = cnt;
        s.push(arr[cnt]);
    }

    string be = "";
    dfs(be, cnt);

    Forget_that Just_go;
}
