#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class NumArray
{
  public:

    NumArray(vector<int> &nums)
    {
        if ( nums.empty() )
            return;

        int* end = &nums[ nums.size() - 1 ];
        for ( v = &nums[1]; v <= end; ++v )
        {
            *v += *(v - 1);
        }

        v = &nums[0];


        /*
        v = new int[ nums.size() ];

        if ( nums.empty() )
            return;

        v[0] = nums[0];
        int* ptrv = &v[1];
        int* ptrnend = &nums[ nums.size() - 1 ];

        for ( int* ptrn = &nums[1]; ptrn <= ptrnend; ++ptrn )
        {
            *ptrv = *(ptrv - 1) + *ptrn;
            ++ptrv;
        }
        */
    }

    ~NumArray()
    {
        //delete [] v;
    }

    int sumRange(int i, int j)
    {
        //if ( !v )
        //    return 0;

        //if ( i == 0 )
        //    return v[j];

        //if ( j == 0 )
        //    return v[0];

        return v[j] - v[i-1];
    }

  private:

    int* v;
};

void test1()
{
    vector<int> v = {-2, 0, 3, -5, 2, -1};
    NumArray na(v);

    assert( na.sumRange(0,2) == 1 );
    assert( na.sumRange(2,5) == -1 );
    assert( na.sumRange(0,5) == -3 );
    assert( na.sumRange(0,0) == -2 );
    assert( na.sumRange(1,2) == 3 );
    assert( na.sumRange(1,3) == -2 );
    assert( na.sumRange(3,4) == -3 );
}

void test2()
{
    vector<int> v;
    //v.reserve(100);
    v.resize(10000);
    NumArray na(v);

    for ( int i = 0; i < 10000000; ++i )
    {
        na.sumRange(0,9999);
    }
}

void test3()
{
    vector<int> v;
    NumArray na(v);
    na.sumRange(0,5);
}

void test4()
{
    vector<int> v;
    //v.reserve(100);
    v.resize(10000);
    NumArray na(v);

    for ( int i = 0; i < 10000000; ++i )
    {
        na.sumRange(967,9999);
    }
}

int main()
{
    test1();
    test2();
    //test3();
    test4();

    return 0;
}







