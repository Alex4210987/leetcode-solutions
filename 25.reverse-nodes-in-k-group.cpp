/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.

 */
#include<vector>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* p=head, *t;
        while(p){
            t=p;
            for(int i=0;i<k;i++){
                if(p){
                    v.push_back(p->val);
                    p=p->next;
                }
            }
            if(v.size()==k){
                for(int i=0;i<k;i++){
                    t->val=v[k-i-1];
                    t=t->next;
                }
            }
            v.clear();
        }
        return head;
    }
};
// @lc code=end
// [1,2,3,4,5]
// 2
// int main(){
//     Solution sol;
//     ListNode* head=new ListNode(1);
//     ListNode* p=head;
//     for(int i=2;i<=5;i++){
//         p->next=new ListNode(i);
//         p=p->next;
//     }
//     sol.reverseKGroup(head,2);
//     return 0;
// }