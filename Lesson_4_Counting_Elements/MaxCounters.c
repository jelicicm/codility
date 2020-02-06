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
 
Assume that the following declarations are given:
 
struct Results {
  int * C;
  int L; // Length of the array
};
 
Write a function:
struct Results solution(int N, int A[], int M);
that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.
Result array should be returned as a structure Results.
 
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
 
struct Results solution(int N, int A[], int M) {
    struct Results result;
    // write your code in C99 (gcc 6.2.0)
    result.C = calloc(N, sizeof(int));
    result.L = N;
   
    int current_max = 0;
    int current_min = 0;
    int i;
   
    for(i = 0; i < M; i++) {
        if( A[i] == N+1 ) {
            current_min = current_max;
        } else {
           
            if(result.C[A[i]-1] < current_min) {
                result.C[A[i]-1] = current_min + 1;
            } else {
                result.C[A[i]-1] += 1;
            }
           
            if(current_max < result.C[A[i]-1]) {
                current_max = result.C[A[i]-1];
            }
        }
    }
   
    for(i = 0; i < N; i++) {
        if(result.C[i] < current_min) result.C[i] = current_min;
    }
   
    return result;
}