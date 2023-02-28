/*
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
        S is empty;
        S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
        S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:
    int solution(char *S);
that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
Write an efficient algorithm for the following assumptions:
        N is an integer within the range [0..200,000];
        string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
*/

#include <string.h>

int solution(char *S) {
    // write your code in C99 (gcc 6.2.0)
    
    char *brackets = calloc(strlen(S), sizeof(char));
    int i;
    int total_opened = 0;
    int error = 0;
    
    for(i = 0; i < strlen(S); i++) {
        switch(S[i]) {
            case '(':
            case '{':
            case '[':
                brackets[total_opened] = S[i];
                total_opened++;
            break;
            case ')':
                if(total_opened == 0) { error = 1; goto finish; }
                if(brackets[total_opened - 1] == '(') {
                    total_opened--;
                } else {
                    error = 1;
                    goto finish;
                }
            break;
            case '}':
                if(total_opened == 0) { error = 1; goto finish; }
                if(brackets[total_opened - 1] == '{') {
                    total_opened--;
                } else {
                    error = 1;
                    goto finish;
                }
            break;
            case ']':
                if(total_opened == 0) { error = 1; goto finish; }
                if(brackets[total_opened - 1] == '[') {
                    total_opened--;
                } else {
                    error = 1;
                    goto finish;
                }
            break;
        }
    }
    
    if(total_opened != 0) {error = 1;}

finish: 
    free(brackets);
    
    return (error == 1) ? 0 : 1;
}