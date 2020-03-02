#include <iostream>

using namespace std;

const int INF = 65535;

void MERGE(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 2], R[n2 + 2];
    for (int i = 1; i <= n1; i++)
        L[i] = A[p + i - 1];
    for (int j = 1; j <= n2; j++)
        R[j] = A[q + j];
    L[n1 + 1] = INF;
    R[n2 + 1] = INF;
    int i = 1, j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MERGE_SORT(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

void Merge(int *A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k <= right; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeU2(int *A, int left, int mid, int right);
void MergeU(int *A, int left, int mid, int right);
void MergeSort(int *A, int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        MergeU2(A, left, mid, right);
    }
}

void MergeU(int *A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            A[left++] = L[i++];
        else
            A[left++] = R[j++];
    }
    while (i < n1)
        A[left++] = L[i++];
    while (j < n2)
        A[left++] = R[j++];
}

void MergeU2(int *A, int left, int mid, int right)
{
    int *B = new int[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= right)
        B[k++] = A[j++];
    for (i = left, k = 0; i <= right; i++)
    {
        A[i] = B[k++];
    }
}

int main()
{
    int A[100];
    for (int i = 0; i < 5; i++)
        cin >> A[i];
    MergeSort(A, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << A[i] << endl;
    system("pause");
    return 0;
}