#include <iostream>
#include <cstring>
using namespace std;
char a[20000010];
int f[20000010];
int main()
{
    scanf("%s", a + 1);
    int n = strlen(a + 1);
    f[0] = 0, f[1] = 0;
    long long ans = 1;
    for (int i = 2; i <= n; i++)
    {
        int j = f[i - 1];
        while (j && (a[i] != a[j + 1] || j > i / 2))
            j = f[j];
        f[i] = (a[j + 1] == a[i]) ? j + 1 : 0;
        ans ^= i - f[i];
        cout << " lcx " << i - f[i] << endl;
        // cout<<f[i]<<" ";
    }
    cout << ans;
}