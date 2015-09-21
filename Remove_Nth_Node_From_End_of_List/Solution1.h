#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

using std::vector;

class Solution 
{
  public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        vector<ListNode*> nodes;
        while ( head )
        {
            nodes.push_back( head );
            head = head->next;
        }
        
        int index = nodes.size() - n;
        if ( n == 1 )
        {
            if ( nodes.size() == 1 )
                return nullptr;
            nodes[index - 1]->next = nullptr;
        }
        else if ( n == nodes.size() )
        {
            return n > 1 ? nodes[1] : nullptr;
        }
        else
            nodes[ index - 1]->next = nodes[ index + 1];
            
        return nodes[0];
    }
};




