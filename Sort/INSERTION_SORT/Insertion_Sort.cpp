#include <iostream>

using namespace std;

int A[100] = {0, 6, 5, 4, 4, 5, 6};
int B[100] = {6, 5, 4, 4, 5, 6};

void Insertion_Sort(int len) //下标1开始
{
    int key, i;
    for (int j = 2; j <= len; j++)
    {
        key = A[j];
        i = j - 1;
        while (i > 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

void Insertion_Sort2(int len) //下标0开始
{
    int key, i;
    for (int j = 1; j < len; j++)
    {
        key = B[j];
        i = j - 1;
        while (i >= 0 && B[i] > key) //降序只需把">"换成"<""
        {
            B[i + 1] = B[i];
            i = i - 1;
        }
        B[i + 1] = key;
    }
}

void Insertion_Sort3(int len) //下标0开始
{
    int key, i;
    for (int j = 1; j < len; j++)
    {
        key = B[j];
        /*i = j - 1;
        while (i >= 0 && B[i] > key) //降序只需把">"换成"<""
        {
            B[i + 1] = B[i];
            i = i - 1;
        }*/
        for (i = j - 1; i >= 0 && B[i] > key; i--)
            B[i + 1] = B[i];
        B[i + 1] = key;
    }
}

int main()
{
    Insertion_Sort3(6);
    for (int i = 0; i < 6; i++)
        cout << B[i] << " ";
    return 0;
}