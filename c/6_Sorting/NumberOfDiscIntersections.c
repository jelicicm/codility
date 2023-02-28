/*
We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].
We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:
  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0

There are eleven (unordered) pairs of discs that intersect, namely:
        discs 1 and 4 intersect, and both intersect with all the other discs;
        disc 2 also intersects with discs 0 and 3.

Write a function:
    int solution(int A[], int N);
that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [0..2,147,483,647].
*/

typedef long long int my_type; //can't use unsigned!
#define LIMIT 10000000
 
//method used by qsort()
int comp(const void* left, const void* right) {
    my_type arg1 = *(const my_type*)left;
    my_type arg2 = *(const my_type*)right;
 
    if(arg1 < arg2) return -1;
    if(arg2 < arg1) return 1;
    return 0;
}
 
int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
 
    //allocate two arrays to hold beginning and ending points of each circle
    my_type *lower = calloc(N, sizeof(my_type));
    my_type *upper = calloc(N, sizeof(my_type));
    int i;
    my_type count = 0;
 
    //initialize arrays
    for(i = 0; i < N; i++) {
        lower[i] = (my_type)i - A[i];
        upper[i] = (my_type)i + A[i];
    }
 
    qsort(lower, N, sizeof(my_type), comp);
    qsort(upper, N, sizeof(my_type), comp);
 
    int open = 0;
    int upper_index = 0;
 
    for(i = 0; i < N; i++) {
        while(lower[i] > upper[upper_index]) {
            //printf("closing %d\n", upper[upper_index]);
            upper_index++;
            open--;
        }
 
        open++;
        count += (open-1);
 
        //printf("opening %d\n", lower[i]);
    }
 
    free(lower);
    free(upper);
 
    return ((int)count <= LIMIT) ? (int)count : -1;
}