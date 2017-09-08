#include <iostream>
#include <string>

using std::string;

int min(int a, int b){
  if(a>=b)
    return b;
  else
    return a;
}

int min(int a, int b, int c){
  return min(min(a, b), c);
}

int edit_distance(const string &str1, const string &str2) {
  int m = str1.size();
  int n = str2.size();
  int d[m+1][n+1];

  for(int i=0; i<m+1; i++){
    for(int j=0; j<n+1; j++){
      if(i==0)
        d[i][j] = j;
      else if(j==0)
        d[i][j] = i;
      else if(str1[i-1] == str2[j-1])
        d[i][j] = d[i-1][j-1];
      else
        d[i][j] = 1 + min(d[i][j-1], d[i-1][j], d[i-1][j-1]);
    }
  }
  return d[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
