#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum = 0;
  int i = 1;
  int last;
  while(true){
    if (sum + i <= n){
      sum += i;
      summands.push_back(i);
      i++;
    }
    else{
      if(sum != n){
        last = summands.back();
        summands.pop_back();
        last = n-(sum-last);
        summands.push_back(last);
      }
      break;
    }
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  std::cout<<"\n";
}
