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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* dupli=NULL;
        ListNode* curr=head;
        while(curr != NULL){
            prev=curr;
            curr=curr->next;
            prev->next=dupli;
            dupli=prev;
        }
        return prev;
    }
    ListNode* findkthnode(ListNode* temp,int k){
        k=k-1;
        while(temp && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* nextNode=NULL;
        ListNode* prevNode=NULL;
        while(temp){
            ListNode* kthnode=findkthnode(temp,k);
            if(kthnode == NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            
            nextNode=kthnode->next;
            kthnode->next=NULL;
            reverseList(temp);
            if(temp == head){
                head=kthnode;
            }else{
                prevNode->next=kthnode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};
