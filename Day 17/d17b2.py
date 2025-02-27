import heapq

regs = [51342988, 0, 0]
ins = [2,4,1,3,7,5,4,0,1,3,0,3,5,5,3,0]

def step(A):
    B = A % 8
    B = B ^ 3
    C = A >> B
    B = B ^ 3 ^ C
    return B, C

def run(A):
    out = []
    while A:
        B, C = step(A)
        A = A >> 3
        out.append(B % 8)
    return out

def search_3bits(pA):
    valid_As = []
    for Ashift in range(8):
        A = (pA << 3) + Ashift
        B, C = step(A)
        if (B % 8) == ins[-(A.bit_length()//3 + 1)]: 
            valid_As.append(A)
    return valid_As

print(run(regs[0]))

DP = {}
Q = [0]
minA = 1 << (3*(len(ins)-1))
while Q:
    A = heapq.heappop(Q)
    if A >= minA: 
        print(A)
        break
    if (A.bit_length()//3 + 1) < len(ins):
        for nA in search_3bits(A):
            if nA == 0: continue
            heapq.heappush(Q,nA)
