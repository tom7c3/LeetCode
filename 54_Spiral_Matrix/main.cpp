#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:

    struct Position
    {
        int x;
        int y;
    };

    void goRight()
    {
        for ( int i = pos.x, j = pos.y; i < n; ++i )
        {
            result.push_back( (*mat)[j][i] );
        }
    }

    void goDown()
    {
        for ( int j = pos.y + 1, i = n - 1; j < m; ++j )
        {
            result.push_back( (*mat)[j][i] );
        }
    }

    void goLeft()
    {
        for ( int i = n - 2, j = m - 1; i >= pos.x; --i )
        {
            result.push_back( (*mat)[j][i] );
        }
    }

    void goUp()
    {
        for ( int j = m - 2, i = pos.x; j > pos.y; --j )
        {
            result.push_back( (*mat)[j][i] );
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        mat = &matrix;
        n = matrix[0].size();
        m = matrix.size();
        pos.x = 0;
        pos.y = 0;

        if ( m == n )
        {
            while ( pos.x < n )
            {
                goRight();
                goDown();
                goLeft();
                goUp();

                ++pos.x;
                ++pos.y;
                --n;
                --m;
            }
        }
        else if ( n > m )
        {
            while ( pos.x < n )
            {
                goRight();

                int j = pos.y + 1;
                if ( j >= m - 1 )
                    break;

                goDown();
                goLeft();
                goUp();

                ++pos.x;
                ++pos.y;
                --n;
                --m;
            }
        }

        return result;
    }

  private:

    vector<vector<int>>* mat;
    Position pos;
    vector<int> result;
    int m, n;

};

int main()
{
    Solution solution;
    vector<vector<int>> input = { {1,2,3,0,2}, {4,5,6,0,2}, {7,8,9,0,2} };
    vector<int> v = solution.spiralOrder( input );

    for ( auto i : v )
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}






