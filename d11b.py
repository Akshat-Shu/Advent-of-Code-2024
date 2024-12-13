a = input().strip().split()
import sys  
from functools import cache

n_loops = 75

sys.setrecursionlimit(1000000000)
@cache
def stones(stone, n):
    if n==0: return 1
    if stone=='0': return stones('1', n-1)
    if len(stone)%2==0: return stones(stone[:len(stone)//2], n-1) + stones(str(int(stone[len(stone)//2:])), n-1)
    return stones(str(int(stone)*2024), n-1)
    

print(sum(stones(c,n_loops) for c in a))