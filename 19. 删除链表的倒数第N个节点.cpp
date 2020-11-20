/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head | !head -> next) return NULL;
        ListNode * first=head, *end=head;
        while(end->next){
            if(n>0) n--;
            else first=first->next;
            end=end->next;
        }
        if(n>0) return head->next;
        first -> next = first -> next -> next;
        return head;
    }
};