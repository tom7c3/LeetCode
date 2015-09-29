class Solution 
{
  public:
    
    int findFirstZero( vector<int>& nums )
    {
        for ( int i = 0; i < nums.size(); ++i )
        {
            if ( nums[i] == 0 )
            {
                if ( i + 1 == nums.size() )
                    return -1;
                    
                return i;
            }
        }
        
        return -1;
    }
    
    void moveZeroes(vector<int>& nums) 
    {
        if ( nums.size() == 1 )
            return;
        
        int firstZero;
        
        if ( (firstZero = findFirstZero( nums )) == -1 )
            return;
            
        if ( firstZero + 1 == nums.size() )
            return;
        
        int* save = &nums[firstZero];
        int* read = &nums[firstZero + 1];

        while ( read != &*nums.end() )
        {
            if ( *read != 0 )
            {
                *save = *read;
                ++save;
            }
            
            ++read;
        }

        while ( save != &*nums.end() )
        {
            *save = 0;
            ++save;
        }
    }
};
