/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
// complexity: O(nlogk), where k is the number of linked lists and n is the total number of nodes.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0)
            return nullptr;

        int n = lists.size();
        while(n > 1)
        {
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }//logk

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }

        if(l1)
            p->next = l1;
        if(l2)
            p->next = l2;

        return dummy->next;
    }
};
// @lc code=end

