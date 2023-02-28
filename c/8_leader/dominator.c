/*
An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that
 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function
    int solution(int A[], int N);
that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

For example, given array A such that
 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
*/

int comparator(const void* arg1, const void* arg2) {
    const int left = *(const int*)arg1;
    const int right = *(const int*)arg2;
    
    return left-right;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int max = 0, max_num = 0, current = 0, num = 0, ret = -1;
    
    int *copied = malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++) {
        copied[i] = A[i];   
    }
    
    qsort(copied, N, sizeof(int), comparator);
    current = copied[0];
    num = max_num = 1;
    for(int i = 1; i < N; i++) {
        if(copied[i] == current) {
            num++;
        } else {
            if(num > max_num) {
                max_num = num;
                max = current;
            }
            
            current = copied[i];
            num = 1;
        }
    }
    if(num > max_num) {
        max_num = num;
        max = current;
    }
    
    //printf("max = %d\tmax_num = %d\n", max, max_num);
    
    if(max_num > N/2) {
        //maximum exists
        for(int i = 0; i < N; i++) {
            if(A[i] == max) {
                ret = i;
                break;
            }
        }
    }
    
    free(copied);
    
    return ret;
}