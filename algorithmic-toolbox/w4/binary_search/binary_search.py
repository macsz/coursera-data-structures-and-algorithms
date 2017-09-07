# Uses python3
import sys

def binary_search(a, x):
    print('='*5,x,'='*5)
    left, right = 0, len(a)
    while left < right:
        mid = int((left+right)/2)
        print('mid', mid)
        if a[mid] < x:
            left = mid+1
        elif a[mid] > x: 
            right = mid
        else:
            return mid
    return -1

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[n + 1]
    a = data[1 : n + 1]
    for x in data[n + 2:]:
        # replace with the call to binary_search when implemented
        print(binary_search(a, x), end = ' ')
