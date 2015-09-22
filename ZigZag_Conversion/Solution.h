class Solution 
{
  public:
  
    string convert(string s, int numRows) 
    {
        if ( numRows == 1 )
            return s;
            
        char* colPtr = &s[0];
        char* rowPtr = &s[0];
        int step = numRows + numRows - 2;
        int endingStep = step;
        int actualStep = step;
        char* result = new char[ s.size() ];
        char* resultPtr = &result[0];
        
        for ( int i = 0; i < numRows; ++i )
        {
            while ( colPtr < &*s.end() )
            {
                *resultPtr++ = *colPtr;
                colPtr += actualStep;
                if ( actualStep != endingStep )
                    actualStep = endingStep - actualStep;
            }
            
            step -= 2;
            if ( step == 0 )
                step = endingStep;
            actualStep = step;
            ++rowPtr;
            colPtr = rowPtr;
        }

        string endString(result, s.size());
        delete [] result;
        return endString;
    }
};
