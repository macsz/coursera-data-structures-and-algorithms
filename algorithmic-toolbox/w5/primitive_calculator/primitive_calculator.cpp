#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int min(int a, int b){
  if(a>=b)
    return b;
  else
    return a;
}

int min(int a, int b, int c){
  return min(min(a, b), c);
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal(int n){
  vector<int> sequence;
  int c[n+1];
  int a1, a2, a3, m;
  c[1] = 0;
  for(int i=2; i<n+1; i++){
    a1 = 9999999;
    a2 = 9999999;
    a3 = 9999999;

    if(i%2 == 0){
      a1 = c[(int)(i/2)] + 1;
    }
    if(i%3 == 0){
      a2 = c[(int)(i/3)] + 1;
    }
    a3 = c[i-1] + 1;
    m = min(a1, a2, a3);
    c[i] = m;
  }
  int i=n;
  while(i>1){
    a1 = 9999999;
    a2 = 9999999;
    a3 = 9999999;

    if(i%2 == 0){
      a1 = c[(int)(i/2)] + 1;
    }
    if(i%3 == 0){
      a2 = c[(int)(i/3)] + 1;
    }
    a3 = c[i-1] + 1;
    m = min(a1, a2, a3);

    if(m == a1){
      sequence.push_back((int)(i/2));
      i = (int)(i/2);
    }
    else if(m == a2){
      sequence.push_back((int)(i/3));
      i = (int)(i/3);
    }
    else{
      sequence.push_back(i-1);
      i = i-1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
