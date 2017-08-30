#include <iostream>

int get_change(int m) {
  int denom[3] = {10, 5, 1};
  int n = 0, n_temp;
  for(int i=0; i<sizeof(denom)/sizeof(*denom); i++){
    n_temp = m/denom[i];
    m = m-n_temp*denom[i];
    n+=n_temp;
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
