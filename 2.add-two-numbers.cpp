/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ans(0), *nxt = &ans; // 定义一个哑节点 ans，用于存储结果链表的头节点
        bool flag1 = false, flag2 = false;
        int sum;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr)
                flag1 = true;
            if (l2 == nullptr)
                flag2 = true;
            if (flag1 && flag2)
                break;
            sum = 0;
            if (!flag1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (!flag2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum >= 10) {
                sum -= 10;
                if (flag1) {
                    if (l2 == nullptr) {
                        l2 = new ListNode(0);
                        nxt->next = l2;
                    }
                    l2->val += 1;
                } else {
                    if (l1 == nullptr) {
                        l1 = new ListNode(0);
                        nxt->next = l1;
                    }
                    l1->val += 1;
                }
            }
            nxt->next = new ListNode(sum); // 将当前节点加入结果链表
            nxt = nxt->next; // 将指针指向下一个节点
        }
        return ans.next; // 返回结果链表的头节点
    }
};
// @lc code=end

