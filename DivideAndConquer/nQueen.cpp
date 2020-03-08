#include <iostream>
#include <cmath>

using namespace std;
int queenPos[100];
void NQueen(int k, int n)
{
    int i;
    if (k == n) //N个皇后摆好
    {
        /*
        for (i = 0; i < n; i++)
            cout << queenPos[i] + 1 << " ";
            */
        for (int i = 0; i < n; i++)
        {
            for (int j = -1; j < n - 1; j++)
            {
                if ((j + 1) != queenPos[i])
                    cout << '0' << " ";
                else
                    cout << '1' << " ";
            }
            cout << endl;
            if ((i + 1) % n == 0)
                cout << "---------------" << endl;
        }
        return;
    }
    for (i = 0; i < n; i++) //尝试第k个皇后的位置   前k-1皇后摆的列
    {
        int j;
        for (j = 0; j < k; j++) //行
        {
            if (queenPos[j] == i ||
                abs(queenPos[j] - i) == abs(k - j)) //斜边成立是行差等于列差
                break;
        }
        if (j == k)
        {
            queenPos[k] = i;
            NQueen(k + 1, n);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    NQueen(0, n);
    system("pause");
    return 0;
}