#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using namespace std;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int main() {
  int ans=0;
  map<int, int> mapa;
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
    mapa[a[i]] = mapa[a[i]] + 1;
    if(mapa[a[i]] > (int)(n/2.0)){
      ans=1;
      break;
    }
  }
  // std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  cout << ans << "\n";
}
