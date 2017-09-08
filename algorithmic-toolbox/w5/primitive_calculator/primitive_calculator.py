# Uses python3
import sys


def optimal_sequence(n):
    sequence = []
    while n >= 1:
        sequence.append(n)
        if n % 3 == 0:
            n = n // 3
        elif n % 2 == 0:
            n = n // 2
        else:
            n = n - 1
    return reversed(sequence)



def dp(n):
    sequence = []
    c = [0] * (n + 1)
    a1 = 0
    a2 = 0
    a3 = 0
    c[1] = 0
    for i in range(2, n+1):     
        a1 = sys.maxsize
        a2 = sys.maxsize
        a3 = sys.maxsize
        if i%2 == 0:
            a1 = c[int(i/2)] + 1
        if i%3 == 0:
            a2 = c[int(i/3)] + 1
        a3 = c[i-1] + 1
        m = min(a1, a2, a3)
        c[i] = m
    # print(c[n])
    # for i in reversed(range(2, n+1)):
    i = n
    while i > 1:
        a1 = sys.maxsize
        a2 = sys.maxsize
        a3 = sys.maxsize
        if i%2 == 0:
            a1 = c[int(i/2)] + 1
        if i%3 == 0:
            a2 = c[int(i/3)] + 1
        a3 = c[i-1]+1
        m = min(a1, a2, a3)
        if m == a1:
            sequence.append(int(i/2))
            i = int(i/2)
        elif m == a2:
            sequence.append(int(i/3))
            i = int(i/3)
        else:
            sequence.append(i-1)
            i = i-1
    return reversed(sequence)

input = sys.stdin.read()
n = int(input)
# sequence = list(optimal_sequence(n))
# print(len(sequence) - 1)
# for x in sequence:
#     print(x, end=' ')
# print()
sequence = list(dp(n))
print(len(sequence))
for x in sequence:
    print(x, end=' ')
