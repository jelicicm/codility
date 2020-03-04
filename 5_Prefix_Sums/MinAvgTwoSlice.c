/*
A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

contains the following example slices:
        slice (1, 2), whose average is (2 + 2) / 2 = 2;
        slice (3, 4), whose average is (5 + 1) / 2 = 3;
        slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

The goal is to find the starting position of a slice whose average is minimal.

Write a function:
    int solution(int A[], int N);
that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−10,000..10,000].

*/

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    double current_avg;
    double min_avg;
    const double two = 2.0;
    const double three = 3.0;
    int min_index = 0;
    int i;
    
    if(N == 2) { return min_index; }
    
    //find avg of first 2 piece slice
    current_avg = min_avg = (A[0] + A[1])/two;
    //find avg of first 3 piece slice
    current_avg = (A[0] + A[1] + A[2])/three;
    if(min_avg > current_avg) {
        min_avg = current_avg;
    }
    
	//iterate trough entire array
    for(i = 1; i < N-1; i++) {
		//check two piece slice
        if((current_avg = (A[i] + A[i+1])/two) < min_avg) {
            min_avg = current_avg;
            min_index = i;
        }
        
		//check three piece slice
		//take note: boundary for ending can create problems, this IF is needed for protection
        if(i < N-2) {
            if((current_avg = (A[i] + A[i+1] + A[i+2])/three) < min_avg) {
                min_avg = current_avg;
                min_index = i;
            }
        }
    }
    
    return min_index;
}