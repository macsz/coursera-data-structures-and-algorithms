# Uses python3
import sys

b_print = False

def mprint(*args, **kwargs):
    if b_print:
        print(*args)

def get_majority_element(a, left, right):
    m = {}
    for elem in a:
        mprint('*'*10, elem, '*'*10)
        try:
            m[str(elem)] += 1
            mprint('exists', m[str(elem)])
        except:
            m[str(elem)] = 1
        if m[str(elem)] > len(a)/2:
            return 1
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
