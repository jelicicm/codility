/*
This is a demo task.

Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main()
{
    vector<int> a = {1, 3, 6, 4, 1, 2};

    cout << solution(a) << endl;

    return 0;
}

int solution(vector<int> &A)
{
    vector<int> b(1000000, 0);

    for (unsigned i = 0; i < A.size(); i++)
    {
        if ((A[i] > 0) && (b[A[i] - 1] == 0))
        {
            b[A[i] - 1] = 1;
        }
    }

    for (unsigned i = 0; i < b.size(); i++)
    {
        if (b[i] == 0)
        {
            return i + 1;
        }
    }

    return -1;
}