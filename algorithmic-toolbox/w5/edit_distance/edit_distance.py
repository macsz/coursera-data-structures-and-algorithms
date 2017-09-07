# Uses python3
def edit_distance(s, t):
    m, n = len(s), len(t)
    d = [[0 for i in range(n+1)] for j in range(m+1)] 
    for i in range(0, m+1):
        for j in range(0, n+1):
            if i==0:
                d[i][j] = j
            elif j==0:
                d[i][j] = i
            elif s[i-1] == t[j-1]:
                d[i][j] = d[i-1][j-1]
            else:
                d[i][j] = 1 + min(d[i][j-1], d[i-1][j], d[i-1][j-1])
    return d[m][n]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
