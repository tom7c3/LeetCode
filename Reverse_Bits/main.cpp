#include <iostream>

using namespace std;

class Solution
{
  public:

    static uint32_t reverseBits(uint32_t n)
    {
        uint32_t result = 0;

        for ( int i = 0; i < 32; ++i )
        {
            int digit = n & 1;
            n >>= 1;
            result <<= 1;
            result = result | digit;
        }

        return result;
    }
};

int main()
{
    cout << Solution::reverseBits(43261596) << endl;
    return 0;
}
