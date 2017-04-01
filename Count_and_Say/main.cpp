#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

string getString( string number )
{
    int count = 1;
    char digit = number[0];
    string result;

    for ( int j = 0; j < number.size(); ++j )
    {
        digit = number[j];

        if ( j == number.size() - 1 )
        {
            result += to_string(count) + digit;
            return result;
        }

        if ( number[j] == number[j + 1] )
        {
            ++count;
        }
        else
        {
            result += to_string(count) + digit;
            count = 1;
        }
    }

    return result;
}

string countAndSay(int n)
{
    if ( n == 1 )
        return "1";

    string number = "1";
    string result;

    for ( int i = 1; i < n; ++i )
    {
        result = getString( number );
        number = result;
    }

    return result;
}

string revert( string s )
{
    string res;
    for ( auto it = s.rbegin(); it != s.rend(); ++it )
        res += *it;

    return res;
}

int main()
{
    for (int i = 1; i <= 30; ++i )
        cout << revert(countAndSay(i)) << endl;

    return 0;
}
