/*
An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
Your goal is to find that missing element.

Write a function:
int solution(int A[], int N);
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    //sum [1..n] = n*(n+1)/2
    long long unsigned int N1 = N+1;
    long long unsigned int sum_n1 = N1*(N1+1)/2;
    long long unsigned int sum_acc = 0, i;
    
    for(i = 0; i < N1; i++) {
        sum_acc += A[i];
    }
    
    return (int)(sum_n1 - sum_acc);
}

#define TOTAL 100000
#define POINT 99000

int main() {
	int N = TOTAL;
	int *A = malloc(sizeof(int)*N);
	int i;

	for(i = 0; i < N; i++) {
		if(i >= POINT) {
			A[i] = i+2;
		} else {
			A[i] = i+1;
		}
	}


	for(i = 0; i < N; i++) {
		if(i < POINT && i+1 != A[i]) {
			printf("diff at %d\n", i);
		}
		if(i >= POINT && i+2 != A[i]) {
			printf("DIFF AT %d\n", i);
		}
	}

	printf("solution = %d\n", solution(A, N));

	free(A);

	return 0;
}
