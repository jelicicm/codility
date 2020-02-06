/*
A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.
Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7

Write a function:
int solution(int A[], int N);
that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:
N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
 
int solution(int A[], int N) {
    long long int left_sum = A[0];
    long long int right_sum = 0;
    int i;
   
    for(i = 1; i < N; i++) right_sum += A[i];
       
    long long int min_difference = abs(right_sum-left_sum);
   
    for(i = 1; i < N-1; i++) {     
        if(abs(right_sum-left_sum) < min_difference) {
            min_difference = abs(right_sum-left_sum);
        }
       
        //printf("Left sum = %d\t", left_sum);
        //printf("Right sum = %d\n", right_sum);
        left_sum    += A[i];
        right_sum   -= A[i];
    }  
   
    if(abs(right_sum-left_sum) < min_difference) {
        min_difference = abs(right_sum-left_sum);
    }
 
    return (int)min_difference;
}
 
#define ELEMENTS 5
 
int main() {
   
    int *A = malloc(sizeof(int)*ELEMENTS);
    A[0] = 3;
    A[1] = 1;
    A[2] = 2;
    A[3] = 4;
    A[4] = 3;
    printf("solution: %d\n", solution(A, ELEMENTS));   
   
    A[0]=3;
    A[1]=1;
    A[2]=2;
    printf("solution: %d\n", solution(A, 3));
   
    A[0]= -1000;
    A[1]= 1000;
    printf("solution: %d\n", solution(A, 2));
   
    A[0]= 3;
    A[1]= 1;
    A[2]= -2000;
    A[3]= 90;
    A[4]= 0;
    printf("solution: %d\n", solution(A, 5));
   
    free(A);
   
    return 0;
}