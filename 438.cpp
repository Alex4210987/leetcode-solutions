class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;
        vector<int> pmap(26, 0);
        vector<int> smap(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            ++pmap[p[i] - 'a'];
            ++smap[s[i] - 'a'];
        }
        if (pmap == smap) res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++smap[s[i] - 'a'];
            --smap[s[i - p.size()] - 'a'];
            if (pmap == smap) res.push_back(i - p.size() + 1);
        }
        return res;      
    }
};