class Trie:

    def __init__(self):
        self.root = {}

    def insert(self, word: str) -> None:
        current = self.root
        for letter in word:
            if letter not in current:
                current[letter] = {}
            current = current[letter]
        current['*'] = True

    def search(self, word: str) -> bool:
        current = self.root
        for letter in word:
            if letter not in current:
                return False
            current = current[letter]
        return '*' in current
        

    def startsWith(self, prefix: str) -> bool:
        current = self.root
        for letter in prefix:
            if letter not in current:
                return False
            current = current[letter]
        return True
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)

#A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently 
# store and retrieve keys in a dataset of strings. There are various applications of this 
# data structure, such as autocomplete and spellchecker.