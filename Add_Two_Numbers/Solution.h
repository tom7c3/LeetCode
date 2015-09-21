/*
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

class Solution 
{
  public:

    void setNewValue( int& value, ListNode* result, int& temp )
    {
        if ( value > 9 )
        {
            value = value % 10;
            result->val = value;
            temp = 1;
        }
        else
        {
            result->val = value;
            temp = 0;
        }
    }
  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* root = new ListNode(0);
        ListNode* result = root;
        
        int temp = 0;
        
        while ( l1 && l2 )
        {
            int value = l1->val + l2->val + temp;
            
            setNewValue( value, result, temp );
            
            l1 = l1->next;
            l2 = l2->next;
            if ( l1 && l2 )
            {
                result->next = new ListNode(0);
                result = result->next;
            }
        }
        
        if ( !l1 )
        {
            l1 = l2;
        }
        
        while ( l1 )
        {
            result->next = new ListNode(0);
            result = result->next;
                
            int value  = l1->val + temp;
            
            setNewValue( value, result, temp );
            
            l1 = l1->next;
        }

        if ( temp )
        {
            result->next = new ListNode(0);
            result->next->val = temp;
        }
        
        return root;
    }
};
