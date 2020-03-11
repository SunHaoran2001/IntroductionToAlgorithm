#include <iostream>
#include <cstring>
using namespace std;

int n;
char a[15], re[15];
int vis[15];

void dfs(int step)
{
    int i;
    if (step == n)
    {
        for (i = 0; i < n; i++)
            printf("%c", re[i]);
        printf("\n");
        return;
    }
    for (i = 0; i < n; i++)
    {
        if (i > 0 && a[i - 1] == a[i] && vis[i - 1] == 0)
            continue;
        if (vis[i] == 0)
        {
            re[step] = a[i];
            vis[i] = 1;
            dfs(step + 1);
            vis[i] = 0;
        }
    }
    return;
}
int main()
{
    scanf("%s", a);
    n = strlen(a);
    dfs(0);
    return 0;
}