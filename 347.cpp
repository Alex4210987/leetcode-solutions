class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        //min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (pq.size() < k) {
                pq.push(make_pair(it->second, it->first));
            } else {
                if (it->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            } 
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};