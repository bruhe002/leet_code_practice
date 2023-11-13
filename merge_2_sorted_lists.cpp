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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Create new List
        ListNode *newList;

        // Create trailing pointer
        ListNode *temp = newList;

        // Loop through the lists and add to new list
        while(list1 != nullptr && list2 != nullptr) {
            if (list1 == nullptr) {
                temp->val = list2->val;
            } else if (list2 == nullptr) {
                temp->val = list1->val;
            } else {
                if(list1->val <= list2->val) {
                    temp->val = list1->val;
                } else {
                    temp->val = list2->val;
                }

                list1 = list1->next;
                list2 = list2->next;
            }
            temp->next = &ListNode();
            temp = temp->next;
        }

        return newList; 
    }
};