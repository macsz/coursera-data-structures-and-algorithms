#include <iostream>
#include <vector>

using std::vector;

int max(int a, int b){
  if(a>b){
    return a;
  }
  else
    return b;
}

int optimal_weight(int W, const vector<int> &wt) {
  //write your code here
  int n = wt.size();
  int K[n+1][W+1];
  for (int i = 0; i <= n; i++) {
      for (int w = 0; w <= W; w++) {
          if (i==0 || w==0)
              K[i][w] = 0;
          else if (wt[i-1] <= w)
              K[i][w] = max(wt[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
          else
              K[i][w] = K[i-1][w];
      }
  }
  return K[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
  return 0;
}
