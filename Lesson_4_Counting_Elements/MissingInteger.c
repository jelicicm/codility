/*
Write a function:
int solution(int A[], int N);
that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
 
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/
 
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
   
    int *taken = calloc(N-1, sizeof(int));
    int ret = N+1;
    int i;
   
    for(i = 0; i < N; i++) {
        if(A[i] <= 0 || A[i] > N) {
           
        } else if(taken[A[i]-1] == 1) {
           
        } else {
            taken[A[i]-1] = 1;
        }
    }
   
    for(i = 0; i < N; i++) {
        if(taken[i] == 0) {
            ret = i+1;
            break;
        }
    }
   
    free(taken);
   
    return ret;
}