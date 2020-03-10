/*
You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.
The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

Write a function:
    int solution(int H[], int N);
that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

For example, given array H containing N = 9 integers:
  H[0] = 8    H[1] = 8    H[2] = 5
  H[3] = 7    H[4] = 9    H[5] = 8
  H[6] = 7    H[7] = 4    H[8] = 8
the function should return 7. The figure shows one possible arrangement of seven blocks.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [1..100,000];
        each element of array H is an integer within the range [1..1,000,000,000].
*/

int solution(int H[], int N) {
    // write your code in C99 (gcc 6.2.0)

    int *stack = calloc(N, sizeof(int));
    int i, on_stack = 0;
    
    stack[on_stack++] = H[0];
	int elems = 1;
	
    for(i = elems; i < N; i++) {
        
        //printf("watching %d\t", H[i]);
        if(H[i] == stack[on_stack-1]) {
            //printf("ignore, continue...\n");
            //do nothing
        } else if(H[i] > stack[on_stack-1]) {
            //add new_element to stack
            //printf("adding, now on stack: %d\n", on_stack+1);
            stack[on_stack++] = H[i];
            elems++;
        } else {
            //when H[i] < stack[on_stack-1]
            while((H[i] < stack[on_stack-1]) && (on_stack >= 1)) {
                //printf("\nremoving %d, now on stack %d\n", stack[on_stack-1], on_stack-1);
                on_stack--;
            }
            if(on_stack == 0 || H[i] != stack[on_stack-1]) {
                stack[on_stack++] = H[i];
                //printf("adding %d, now on stack: %d\n", H[i], on_stack);
                elems++;
            }
        }
    }    
    
	free(stack);
	
    return elems;
}