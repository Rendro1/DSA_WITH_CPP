#include <bits/stdc++.h>
using namespace std;

bool possibleAlocation(int A[], int N, int M, int mid)
{
    int student = 1, pages = 0;

    for (int i = 0; i < N; i++)
    {
        if (mid < A[i])
        {
            return false;
        }
        if (pages + A[i] > mid)
        {
            student++;
            pages = 0;
            pages += A[i];
        }
        else
        {
            pages += A[i];
        }
    }
    if (student > M)
    {
        return false;
    }
    return true;
}
int findPages(int A[], int N, int M)
{
    int sum = 0;

    if (N < M)
    {
        return -1;
    }

    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    int low = A[0];
    int high = sum;

    int res = -1;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if (possibleAlocation(A, N, M, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int N = 4;
    int A[N] = {12,34,67,90};
    int M = 2;
    cout<<findPages(A,N,M);
    return 0;
}