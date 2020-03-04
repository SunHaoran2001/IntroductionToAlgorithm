#include <iostream>
#include <cstdio>
#include <limits.h>
using namespace std;

int FindMaxCrossingSubarray(double *A, int low, int mid, int high, double *CrossSum, int *CrossLow, int *CrossHigh)
{
    double LeftSum = INT_MIN;
    double RightSum = INT_MIN;
    double sum = A[mid];
    int i = 0;
    int MaxLeft = mid;
    int MaxRight = mid + 1;
    for (i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if (sum > LeftSum)
        {
            LeftSum = sum;
            MaxLeft = i;
        }
    }
    sum = 0;
    for (i = mid + 1; i <= high; i++)
    {
        sum = sum + A[i];
        if (sum > RightSum)
        {
            RightSum = sum;
            MaxRight = i;
        }
    }
    *CrossSum = LeftSum + RightSum;
    *CrossLow = MaxLeft;
    *CrossHigh = MaxRight;
    return 0;
}

#define INDEX_ERR 1

int FindMaxSubarray(double *A, int low, int high, double *MaxSum, int *SubLow, int *SubHigh)
{
    int mid = 0;
    int LeftLow;
    int LeftHigh;
    int RightLow;
    int RightHigh;
    int CrossLow;
    int CrossHigh;
    double LeftSum;
    double RightSum;
    double CrossSum;
    int ret = 0;
    if (high < low) //输入索引错误
    {
        return INDEX_ERR;
    }
    if (high == low) //只有一个元素
    {
        *MaxSum = A[low];
        *SubLow = low;
        *SubHigh = low;
    }
    else
    {
        //分解子问题
        mid = (int)((low + high) / 2);
        //寻找中间点左侧的最大子数组
        ret = FindMaxSubarray(A, low, mid, &LeftSum, &LeftLow, &LeftHigh);
        if (ret)
        {
            return ret;
        }
        //寻找中间点右侧的最大子数组
        ret = FindMaxSubarray(A, mid + 1, high, &RightSum, &RightLow, &RightHigh);
        if (ret)
        {
            return ret;
        }
        //寻找跨越中间点的最大子数组
        ret = FindMaxCrossingSubarray(A, low, mid, high, &CrossSum, &CrossLow, &CrossHigh);
        if (ret)
        {
            return ret;
        }
        //子问题的解合成原问题的解
        if (LeftSum >= RightSum && LeftSum >= CrossSum)
        {
            *MaxSum = LeftSum;
            *SubLow = LeftLow;
            *SubHigh = LeftHigh;
        }
        else if (RightSum >= LeftSum && RightSum >= CrossSum)
        {
            *MaxSum = RightSum;
            *SubLow = RightLow;
            *SubHigh = RightHigh;
        }
        else
        {
            *MaxSum = CrossSum;
            *SubLow = CrossLow;
            *SubHigh = CrossHigh;
        }
    }
    return 0;
}
int main()
{
    double A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7}; //算法导论4.1节的数据
    int low = 0;
    int high = 15;
    double MaxSum;
    int SubLow;
    int SubHigh;
    int ret = FindMaxSubarray(A, low, high, &MaxSum, &SubLow, &SubHigh);
    if (ret)
    {
        printf("FindMaxSubarray error %d\n", ret);
        return 0;
    }
    //打印结果
    for (int i = SubLow; i <= SubHigh; i++)
    {
        printf("A[%d]=%lf\t", i + 1, A[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}