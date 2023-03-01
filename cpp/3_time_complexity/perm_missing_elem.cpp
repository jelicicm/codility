/*
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)].
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main()
{
    vector<int> vec = {2, 3, 1, 5};

    cout << solution(vec) << endl;
    return 0;
}

#include <numeric>
int solution(vector<int> &A)
{
    const unsigned n = A.size();

    // sum of first N integers:
    const unsigned long sum_n_plus_1 = (n + 1) * (n + 1 + 1) / 2;

    const unsigned long sum_of_vec = accumulate(A.begin(), A.end(), 0);

    return static_cast<int>(sum_n_plus_1 - sum_of_vec);
}