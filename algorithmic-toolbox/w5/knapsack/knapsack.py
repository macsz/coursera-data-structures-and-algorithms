# Uses python3
import sys

def optimal_weight(W, wt):
    # write your code here
    n = len(wt)
    # K = [n+1][W+1]
    K = [[0 for i in range(W+1)] for j in range(n+1)]
    for i in range(0, n+1):
        for w in range(0, W+1):
            if i==0 or w==0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                K[i][w] = max(wt[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
    return K[n][W]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
