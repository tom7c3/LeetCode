#include <iostream>

using namespace std;

class Solution
{
  public:
    static int hammingWeight(uint32_t n)
    {
        int sum = 0;
        while ( n != 0 )
        {
            sum += n & 1;
            n >>= 1;
        }
        return sum;
    }
};

int main()
{
    cout << Solution::hammingWeight(11) << endl;
    return 0;
}
