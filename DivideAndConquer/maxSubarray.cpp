#include <iostream>
#include <climits>
using namespace std;
/*INFO
*   auther: Sunhaoran
*/
constexpr int INF = 0x3f3f3f3f; //无穷大

typedef struct
{
    int left;
    int right;
    int sum;
} max_subarray;

max_subarray FIND_MAX_CROSSING_SUBARRAY(int *A, int low, int mid, int high)
{
    max_subarray result = {-1, -1, 0};
    int left_sum = -INF;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            result.left = i;
        }
    }
    int right_sum = -INF;
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            result.right = j;
        }
    }
    result.sum = left_sum + right_sum;
    return result;
}

max_subarray FIND_MAXIMUN_SUBARRAY(int *A, int low, int high)
{
    if (high == low)
        max_subarray result = {low, high, A[low]};
    else
    {
        int mid = (low + high) / 2;
        max_subarray left = FIND_MAXIMUN_SUBARRAY(A, low, mid);
        max_subarray right = FIND_MAXIMUN_SUBARRAY(A, mid, high);
        max_subarray cross = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum)
            return left;
        else if (right.sum >= left.sum && right.sum >= left.sum)
            return right;
        else
            return cross;
    }
}
int main()
{
    int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    FIND_MAXIMUN_SUBARRAY(A, 0, 15);

    system("pause");
    return 0;
}