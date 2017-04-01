class Solution 
{
  public:
  
    bool detectCapitalUse(string word) 
    {
        if ( word.size() == 1 )
            return true;
        else if ( word.size() == 2 && word[1] < 'a' && word[0] >= 'a' )
            return false;
            
        char c = word[1];
        if ( c < 'a' )
            return areAllLettersUppercase(word);
        else
            return areAllLettersLowercase(word);
    }

  private:

	bool areAllLettersLowercase(const string& word )
    {
        for ( int i = 2; i < word.size(); ++i )
        {
            if ( word[i] < 'a' )
                return false;
        }
        return true;
    }
    
    bool areAllLettersUppercase(const string& word )
    {
        for ( int i = 2; i < word.size(); ++i )
        {
            if ( word[i] >= 'a' )
                return false;
        }
        return word[0] >= 'a' ? false : true;
    }
};
