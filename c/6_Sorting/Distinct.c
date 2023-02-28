/*
Write a function
	int solution(int A[], int N);
that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

*/

#define MILLION 1000000

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int *taken = calloc((2*MILLION + 1), sizeof(int));
    int count = 0;
    int i;
    
    for(i = 0; i < N; i++) {
        if(taken[A[i]+MILLION] == 0) {
            taken[A[i]+MILLION] = 1;
        }
    }
    
    for(i = 0; i < 2*MILLION + 1; i++) {
        if(taken[i] == 1) {
            count++;
        }
    }
    
    return count;
}