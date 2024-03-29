/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// @lc code=start
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p= head;
        while(p){
            if(p->next){
                int temp=p->val;
                p->val=p->next->val;
                p->next->val=temp;
                p=p->next->next;
            }
            else{
                p=p->next;
            }
        }
        return head;
    }
};
// @lc code=end

