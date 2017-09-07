#include <iostream>
#include <cassert>
#include <vector>

using std::vector;
using namespace std;

int binary_search(const vector<int> &a, int x) {
  // cout << "\n===== " << x << " =====\n"; 
  int left = 0, right = (int)a.size(); 
  int mid;
  while(left < right){
    mid = (int)((left+right)/2);
    // cout << "mid [" << mid << "] = " << a[mid] << "\n";
    if(a[mid] < x){
      left = mid+1;
      // cout << "wiekszy\n";
    }
    else if(a[mid] > x){
      right = mid;
      // cout << "mniejszy\n";
    }
    else{
      // cout << "dokladnie\n";
      return mid;
    }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
