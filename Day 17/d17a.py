from sympy import Symbol, solve, Xor, Pow


def combo(x, A, B, C):
    if x <= 3:
        return x
    if x == 4:
        return A
    if x == 5:
        return B
    if x == 6:
        return C
    print("bro")
    return -1

def main():
    p = [2, 4, 1, 3, 7, 5, 4, 0, 1, 3, 0, 3, 5, 5, 3, 0]
    i = 0
    A = Symbol('A')  
    B = Symbol('B')
    C = Symbol('C')


    while i < len(p):
        val = p[i + 1]
        op = p[i]
        if op == 0:
            A = A // Pow(2, combo(val, A, B, C))
        elif op == 1:
            B = Xor(B, val)
        elif op == 2:
            B = combo(val, A, B, C) % 8
        elif op == 3:
            if not A.equals(0):
                i = val - 2
        elif op == 4:
            B = Xor(B, C)
        elif op == 5:
            print(combo(val, A, B, C) % 8, end=",")
        elif op == 6:
            B = A // Pow(2, combo(val, A, B, C))
        elif op == 7:
            C = A // Pow(2, combo(val, A, B, C))
        i += 2
    sol = solve(A)
    print(sol)

if __name__ == "__main__":
    main()
    