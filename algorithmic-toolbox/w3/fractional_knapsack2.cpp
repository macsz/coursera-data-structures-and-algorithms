#include <iostream>
#include <vector>

using std::vector;

void print_vector(vector<double> vec){
  std::cout << "vec ";
  for(vector<int>::size_type i = 0; i != vec.size(); i++)
    std::cout << vec[i] << " ";
  std::cout << "\n";
}

int stuff_it_in(int capacity, int weight){
  if(capacity >= weight)
    return weight;
  return capacity;
}

int find_max_index(vector<double> vec){
    int max_value =- 1;
    int max_index = -1;
    for(vector<double>::size_type i = 0; i != ratio.size(); i++) {
        if(max_value <= ratio[i]){
          max_value = ratio[i];
          max_index = i;
        }
    }
    print_vector(vec)
    printf("[%d] %f\n", max_index, vec[max_index]);
    return max_index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values, vector<double> ratio) {
  double value = 0.0;
  int max_value, max_index, temp_capacity;
  while(!ratio.empty()){
    // printf("=================\n");
    // find max value in vector
    // printf("size: %lu\n", ratio.size());
    // print_vector(ratio);
    max_index = find_max_index(ratio);

    temp_capacity = stuff_it_in(capacity, weights[max_index]);
    capacity -= temp_capacity;
    value += temp_capacity*ratio[max_index];
    // printf("value: %d * %d = %d\n", temp_capacity, values[max_index], temp_capacity*values[max_index]);
    
    ratio.erase(ratio.begin() + max_index), weights.erase(weights.begin() + max_index), values.erase(values.begin() + max_index);
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  vector<double> ratio(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    ratio[i] = values[i]/(double)weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values, ratio);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
