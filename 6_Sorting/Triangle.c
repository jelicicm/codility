/*
An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
        A[P] + A[Q] > A[R],
        A[Q] + A[R] > A[P],
        A[R] + A[P] > A[Q].

For example, consider array A such that:
	A[0] = 10    A[1] = 2    A[2] = 5
	A[3] = 1     A[4] = 8    A[5] = 20
Triplet (0, 2, 4) is triangular.

Write a function:
    int solution(int A[], int N);
that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:
  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20

the function should return 1, as explained above. Given array A such that:
  A[0] = 10    A[1] = 50    A[2] = 5    A[3] = 1
the function should return 0.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
*/

void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void merge_sort(int arr[], int l, int r) { 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        merge_sort(arr, l, m); 
        merge_sort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int i = 0;
    int first, second, third;
    
    if(N < 3) {
        return 0;
    }
    
    merge_sort(A, 0, N-1);
    
    while(A[i] < 0) { 
        i++; 
    }
    
    for(; i < N - 2; i++) {
        first  = A[i];
        second = A[i+1];
        third  = A[i+2];
        
        if((long)first + (long)second > (long)third) {
        //    if((long)b + (long)c > (long)a) {     //always true, since the array is sorted in ascending order
        //        if((long)a + (long)c > (long)b) { //always true, since the array is sorted in ascending order
            return 1;
        //        }
        //    }
        }
    }
    
    return 0;
}

