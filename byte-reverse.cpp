// g++ -std=c++11 byte-reverse.cpp -o  byte-reverse

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <string>

void printIntInBinary(unsigned num)
{
    // unsign is 21 bits

    // check every bit
    std::string numIn32Print;

    for (int i = 0; i < 32; i++)
    {
        if ((num & 1) == 1)
        {
            numIn32Print.insert(0, "1");
        }
        else
        {
            numIn32Print.insert(0, "0");
        }
        if ((i + 1) % 4 == 0)
        {
            numIn32Print.insert(0, " ");
        }
        num >>= 1;
    }
    printf("%s\n", numIn32Print.c_str());
}

void leetcode_bit_reversal()
{
    unsigned wordTest = 10;
    printIntInBinary(wordTest);

    unsigned int wordReversed = 0;
    // HW : given any unsigned int wordTest, reverse the bit order in wordTest

    // please implement the solution here
     

    for (int i = 0; i < 32; i++)
    {
        // get each value from the end
        if ((wordTest & 1) == 1)
        {
            wordReversed += pow(2,31-i);
        }
        
        wordTest >>= 1;
    }

    printIntInBinary(wordReversed);
}

int main()
{

    leetcode_bit_reversal();

    return 0;
}
