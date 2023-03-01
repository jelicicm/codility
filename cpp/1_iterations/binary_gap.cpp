#include <iostream>

/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

    int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..2,147,483,647].
*/

int solution(int);
std::string int_to_bin(int);

int main(int argc, char *argv[])
{
    int test_num = 32;

    std::cout << solution(test_num) << std::endl;
}

int solution(int N)
{
    // std::string binary = int_to_bin(N);
    unsigned longest_streak = 0;
    unsigned current_streak = 0;

    std::string binary = "";
    {
        while (N >= 2)
        {
            int remainder = N % 2;
            N /= 2;
            binary = binary.insert(0, std::to_string(remainder));
        }
    };

    for (unsigned i = 0; i < binary.length(); i++)
    {
        if (binary[i] == '0')
        {
            current_streak += 1;
        }
        else if (current_streak > 0)
        {
            longest_streak = (current_streak > longest_streak) ? current_streak : longest_streak;
            current_streak = 0;
        }
        else
        {
            current_streak = 0;
        }
    }

    return longest_streak;
}
