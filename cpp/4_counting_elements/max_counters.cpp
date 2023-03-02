/*
You are given N counters, initially set to 0, and you have two possible operations on them:

        increase(X) − counter X is increased by 1,
        max counter − all counters are set to the maximum value of any counter.

A non-empty array A of M integers is given. This array represents consecutive operations:

        if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
        if A[K] = N + 1 then operation K is max counter.

For example, given integer N = 5 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4

the values of the counters after each consecutive operation will be:
    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations.

Write a function:

    vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as a vector of integers.

For example, given:
    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4

the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

        N and M are integers within the range [1..100,000];
        each element of array A is an integer within the range [1..N + 1].
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> &A);

int main()
{

    vector<int> a = {3, 4, 4, 6, 1, 4, 4};
    int n = 5;

    vector<int> result = solution(n, a);

    for (unsigned i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\t";
    }
    cout << endl;

    return 0;
}

#include <cassert>
vector<int> solution(int N, vector<int> &A)
{
    vector<int> ret_val(N, 0);

    assert(ret_val.size() == N);

    int min_val = 0;
    int max_val = 0;

    for (unsigned i = 0; i < A.size(); i++)
    {
        if ((A[i] >= 1) && (A[i] <= N))
        {
            if (ret_val[A[i] - 1] < min_val)
            {
                ret_val[A[i] - 1] = min_val + 1;
            }
            else
            {
                ret_val[A[i] - 1] += 1;
            }

            max_val = (ret_val[A[i] - 1] > max_val) ? ret_val[A[i] - 1] : max_val;
        }
        else if (A[i] == (N + 1))
        {
            min_val = max_val;
        }
    }

    for (unsigned i = 0; i < N; i++)
    {
        if (ret_val[i] < min_val)
        {
            ret_val[i] = min_val;
        }
    }

    return ret_val;
}