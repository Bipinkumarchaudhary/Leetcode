class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        l1=list(s)
        l2=list(t)
        for i in l2:
            if i in l1:
                l1.remove(i)
            else :
                return i