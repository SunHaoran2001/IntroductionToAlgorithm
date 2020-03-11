#include <iostream>

using namespace std;

int n, r;
int vis[30];
int re[30], a[30];

void dfs(int step, int pre)
{
    if (step == r)
    {
        cout << re[0];
        for (int i = 1; i < r; i++)
        {
            printf(" %d", re[i]);
        }
        printf("\n");
        return;
    }

    for (int i = pre; i < n; i++)
    {
        if (!vis[i])
        {
            re[step] = i + 1;
            vis[i] = 1;
            dfs(step + 1, i);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> r;
    dfs(0, 0);
    return 0;
}