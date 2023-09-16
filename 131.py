class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(s):
            return s == s[::-1]
        def backtrack(s, path, res):
            if not s:
                res.append(path)
                return
            for i in range(1, len(s) + 1):
                if isPalindrome(s[:i]):
                    backtrack(s[i:], path + [s[:i]], res)
        res = []
        backtrack(s, [], res)
        return res
