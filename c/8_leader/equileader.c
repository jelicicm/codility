/*
A non-empty array A consisting of N integers is given.
The leader of this array is the value that occurs in more than half of the elements of A.
An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi leaders:
        0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
        2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.

The goal is to count the number of equi leaders.

Write a function:
    int solution(int A[], int N);
that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:
    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
*/

int comp(const void *arg1, const void *arg2) {
    const int lhs = *(const int*)arg1;
    const int rhs = *(const int*)arg2;
    
    if(lhs > rhs) return 1;
    if(lhs == rhs) return 0;
    return -1;
}

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int *copy = malloc(sizeof(int)*N);
    for(int i = 0; i < N; i++) {
        copy[i] = A[i];
    }
    qsort(copy, N, sizeof(int), comp);
    
    int leader = 0, max_cnt = 0, current = 0, cnt = 0;
    
    cnt = 1;
    current = copy[0];
    for(int i = 1; i < N; i++) {
        if(current == copy[i]) {
            cnt++;
        } else {
            if(max_cnt < cnt) {
                max_cnt = cnt;
                leader = current;
            }
            
            current = copy[i];
            cnt = 1;
        }
    }
    if(max_cnt < cnt) {
        max_cnt = cnt;
        leader = current;
    }
    
    //printf("max = %d\tcnt = %d\N", leader, max_cnt);
    int lhs_lead_cnt = 0;
    int rhs_lead_cnt = max_cnt;
    int lhs_elem_cnt = 0;
    int rhs_elem_cnt = N;
    int ret_val = 0;
    
    for(int i = 0; i < N - 1; i++) {
        
    	lhs_elem_cnt++;
    	rhs_elem_cnt--;
        if(A[i] == leader) {
            lhs_lead_cnt++;
            rhs_lead_cnt--;
        }
        if((lhs_lead_cnt > lhs_elem_cnt/2) && (rhs_lead_cnt > rhs_elem_cnt/2)) {
            ret_val++;
            //printf("%d:\tlhs_elem_cnt: %d\tlhs_lead_cnt: %d\trhs_elem_cnt: %d\t rhs_lead_cnt: %d\n",              	i, lhs_elem_cnt, lhs_lead_cnt, rhs_elem_cnt, rhs_lead_cnt);
        }
    }

    free(copy);
    
    return ret_val;
}

