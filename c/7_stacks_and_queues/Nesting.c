/*
A string S consisting of N characters is called properly nested if:
        S is empty;
        S has the form "(U)" where U is a properly nested string;
        S has the form "VW" where V and W are properly nested strings.

For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:
    int solution(char *S);
that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:
        N is an integer within the range [0..1,000,000];
        string S consists only of the characters "(" and/or ")".
*/

#include <string.h>

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)

    int i, len = strlen(S);
    int error = 0;
    int opened = 0;
    
    for(i = 0; (i < len) && (error == 0); i++) {
        switch(S[i]) {
            case '(':
                opened++;
            break;
            case ')':
                if(opened > 0) {
                    opened--;
                } else {
                    error = 1;
                }
            break;
        }    
    }
    
    if(opened != 0) error = 1;
    
    return(error == 1) ? 0 : 1;
}