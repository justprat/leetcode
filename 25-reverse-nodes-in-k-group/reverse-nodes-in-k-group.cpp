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
    ListNode* getKth(ListNode* head , int k){

        ListNode *temp = head;

        while(k-- && temp){
            temp = temp ->next;
        }

        return temp;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode *groupPrev = &dummy;

        while(groupPrev && groupPrev->next){

            ListNode *kth = getKth(groupPrev,k);
            if(kth == NULL) break;

            ListNode *groupNext = kth -> next;

            ListNode *curr = groupPrev -> next;
            ListNode *prev = groupNext;

            while(curr != groupNext){
                ListNode *next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }

            ListNode *temp = groupPrev -> next;
            groupPrev -> next = prev;
            groupPrev = temp;

        }

        return dummy.next;
        
    }
};