a = input().strip().split()
import sys  
from functools import cache

n_loops = 75

sys.setrecursionlimit(1000000000)
@cache
def rec(s, n):
    if n==0: return 1
    if s=='0': return rec('1', n-1)
    l = len(s)
    if len(s)%2==0: return rec(s[:l//2], n-1) + rec(str(int(s[l//2:])), n-1)
    return rec(str(int(s)*2024), n-1)
    

print(sum(rec(c,n_loops) for c in a))