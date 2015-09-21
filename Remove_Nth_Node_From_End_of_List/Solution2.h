/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
  public:
    
    struct Node
    {
        Node* next = nullptr;
        Node* prev = nullptr;
        ListNode* node = nullptr;
    };
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        Node* root = new Node();            // remember to call delete on this object //
        Node* node = root;
        while ( head )
        {
            node->node = head;
            
            if ( head->next )
            {
                node->next = new Node();    // remember to call delete on this object //
                node->next->prev = node;
                node = node->next;
            }
            
            head = head->next;
        }
        
        for ( int i = 0; i < n - 1; ++i )
        {
            node = node->prev;
        }
        
        if ( !node->prev )
        {
            if ( node->next )
                return node->next->node;
            else
                return nullptr;
        }
        else if ( !node->next )
        {
            if ( node->prev )
                node->prev->node->next = nullptr;
        }
        else
            node->prev->node->next = node->next->node;
            
        return root->node;
    }
};





