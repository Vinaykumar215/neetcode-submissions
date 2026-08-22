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
        int count=0;
        ListNode* temp=head;
        while(temp != NULL){
            count++;
            temp=temp->next;
        }
        int k=count-n;
        if(k==0){
            ListNode* newHead=head->next;
            return newHead;
        }else{
            temp=head;
            while(k>1){
                k--;
                temp=temp->next;    
            }
            ListNode* nodetodel=temp->next;
            temp->next=nodetodel->next;
            nodetodel->next=NULL;
        }
        return head;
    }
};
